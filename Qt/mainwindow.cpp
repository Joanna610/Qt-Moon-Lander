#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
 * Poprzez konstruktor zostaje zainicjowane tło na którym będzie znajdować się statek oraz sam lądownik.
 * Wszystkie przyciski zostały stworzone za pomocą Designera.
 */

MainWindow::MainWindow(QWidget *wParent) : QMainWindow(wParent),
    ui(new Ui::MainWindow),
    _serialPort(nullptr){

    ui->setupUi(this);
    loadPorts();

    _GraphX = new graphs(ui->chartView_x);
    _GraphY = new graphs(ui->chartView_y);
    _GraphZ = new graphs(ui->chartView_z);


    //Cosmos.load("C:/Users/joann/Desktop/WDS/WDS/image/cosmos.png");
    Cosmos.load("C:/Users/joann/Desktop/WDS/WDS3/image/cosmos.png");
    English.load("C:/Users/joann/Desktop/WDS/WDS3/image/english_flag.png");
    German.load("C:/Users/joann/Desktop/WDS/WDS3/image/german_flag.png");
    RedDott.load("C:/Users/joann/Desktop/WDS/WDS3/image/red.png");
    GreenDott.load("C:/Users/joann/Desktop/WDS/WDS3/image/green.png");

    QFont font("Arial", 11);
    ui->angle_xy->setStyleSheet("background-color: gray;color: black; ");
    ui->angle_xy->setFont(font);
    ui->angle_xz->setStyleSheet("background-color: gray;color: black;");
    ui->angle_xz->setFont(font);
    ui->angle_yz->setStyleSheet("background-color: gray;color: black;");
    ui->angle_yz->setFont(font);

    ui->X_value->setStyleSheet("background-color: gray;color: black;");
    ui->X_value->setFont(font);
    ui->Y_value->setStyleSheet("background-color: gray;color: black;");
    ui->Y_value->setFont(font);
    ui->Z_value->setStyleSheet("background-color: gray;color: black;");
    ui->Z_value->setFont(font);

    _Connection = false;
    ui->connection->setText(tr("Not Connected"));

    T= new QTranslator();

    _Gases = new gases2(this);
    _Spaceship = new Lander(this);

}
/*!
 * Wyrysowywane jest tło dla lądownika
 * oraz inne animacje.
 */
void MainWindow::paintEvent( QPaintEvent * )
{

    QPainter painter(this);
    painter.scale(0.85, 0.85);
    painter.drawImage(15, 15, Cosmos);

    if(_Connection){
        painter.scale(0.015, 0.015);
        painter.drawImage(500, 50500, GreenDott);
    }
    else{
        painter.scale(0.015, 0.015);
        painter.drawImage(500, 50500, RedDott);
    }
}


MainWindow::~MainWindow(){
    delete ui;
    delete _Gases;
    delete _Spaceship;
    delete _GraphX;
    delete _GraphY;
    delete _GraphZ;
    delete T;

    if(_serialPort != nullptr){
        _serialPort->close();
        delete _serialPort;
    }
}


/*!
 * Funkcja pozwala wybrać port, z ktorego mają zostać pobrane dane.
 */

void MainWindow::loadPorts(){
    foreach (auto &port, QSerialPortInfo::availablePorts()){
        ui->PortChoice->addItem(port.portName());
    }
}

/*!
 *  Włącza port seryjny i nadaje mu odpowiednie parametry. Jeśli uda
 *  się połączyć to łączy się z lądownikiem i aktualizuje inne parametry.
 *  Jeśli jednak nie uda się połączyć, to aplikacja informuję
 *  o nieudanej próbie połączenia sie z urządzeniem.
 */

void MainWindow::on_openPort_clicked()
{
    if(_serialPort != nullptr){
        _serialPort->close();
        delete _serialPort;
    }

    _serialPort = new QSerialPort(this);
    _serialPort->setPortName(ui->PortChoice->currentText());
    _serialPort->setBaudRate(QSerialPort::Baud115200);
    _serialPort->setDataBits(QSerialPort::Data8);
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setStopBits(QSerialPort::OneStop);
    if(_serialPort->open(QIODevice::ReadWrite)){
        connect(_serialPort, &QSerialPort::readyRead, this, &MainWindow::ReadData);

        _Connection = true;
        ui->connection->setText(tr("Connected"));
        update();
        _Spaceship->ConnectLander(true);
    }
    else {
        QMessageBox::information(this, tr("Port error"), tr("Unable to open port."));
    }
}

/*!
 *  Wylicza arcus tangens odpowidnich kątów. Następnie wartości
 *  zamieniane są na jednostki w radianach. Za każdym razem, gdy
 *  zostanie obliczona nowa wartośc usuwany jest aktualny stan
 *  pola, w którym wyswietlane są dane.
 *  Następnie dane są przekazywane do obiektu klasy Lander.
 */

void MainWindow::CountAngles(double _x, double _y, double _z){
    _GraphX->drawData(static_cast<int>(_x));
    _GraphY->drawData(static_cast<int>(_y));
    _GraphZ->drawData(static_cast<int>(_z));

    double kat_alfa = qAtan2( _x, _y);

    kat_alfa = kat_alfa*180/M_PI;
    ui->angle_xy->clear();
    ui->angle_xy->addItem(QString::number(static_cast<int>(kat_alfa)));

    double kat_beta = qAtan2( _x, _z);
    //qDebug() << "kat" <<kat_beta<<"\n";
    kat_beta = kat_beta*180/M_PI;
    ui->angle_xz->clear();
    ui->angle_xz->addItem(QString::number(static_cast<int>(kat_beta)));

    double kat_gamma = qAtan2( _y, _z);
    kat_gamma = kat_gamma*180/M_PI;
    ui->angle_yz->clear();
    ui->angle_yz->addItem(QString::number(static_cast<int>(kat_gamma)));

    _Gases->updateLanderPosition(_Spaceship->setDirection(static_cast<int>(kat_beta-2), static_cast<int>(kat_gamma-2)));
}

/*!
 *  Wylicza sumę kontrolną z przekazanego bufora.
 */
unsigned short int MainWindow::ComputeCRC8(char* pData, int Length, unsigned int Poly, unsigned short int InitVal)
{
    unsigned short int ResCRC = InitVal;


    while (--Length >= 0) {
        ResCRC ^= *pData++;
        for (short int i=0; i < 8; ++i)
            ResCRC = ResCRC & 0x80 ? (ResCRC << 1) ^ Poly : ResCRC << 1;
    }
    return ResCRC & 0xFF;
}

/*!
 *  Dodawana jest wartość akualnego położenia lądownika do
 *  okienek wyswietlającyh te dane na aplikacji. Jest ona
 *  odpowiednio rzutowana, a następnie przekazywana do funkcji,
 *  która ma za zadanie obliczyć jej kąt.
 *
 *  \retval true - dane okazały się być poprawne
 *  \retval false - dane okazały się nie być poprawne
 */
bool MainWindow::AddData(char* DataFrame){
    double x = 0, y = 0, z = 0;


    _word = strtok(DataFrame, " ");
    if(*_word == 's'){
        _word = strtok(NULL, " ");
        ui->X_value->clear();
        ui->X_value->addItem(QString(_word));
        x = QString(_word).toDouble();

        _word = strtok(NULL, " ");
        ui->Y_value->clear();
        ui->Y_value->addItem(QString(_word));
        y = QString(_word).toDouble();

        _word = strtok(NULL, " ");
        ui->Z_value->clear();
        ui->Z_value->addItem(QString(_word));
        z = QString(_word).toDouble();
        CountAngles(x,y,z);
    }
    else return false;
    return true;
}

/*!
 *  Wczytuje surowe dane bezpośrednio z akcelerometru
 *  Sprawdza na początku ramkę następnie wylicza sumię kontrolną
 *  i sprawdza ją z sumą dodaną do ramki, jeśli suma jest poprawna
 *  to przekazuje ramkę danych do funkcji, która
 *  wyświetlaja dane na aplikacji oraz wykonuję inne obliczenia.
 */

void MainWindow::ReadData(){
    if(!_serialPort->isOpen()){
        QMessageBox::critical(this, tr("Port Error"), tr("Port is not opened"));
        return;
    }
    qint64  Rozmiar = _serialPort->readLine(_Buffor, 50);

    if(_Buffor[Rozmiar-1]=='\n'){
        strncat(_DataFrame, _Buffor, sizeof(_DataFrame));

        char *lastSpace = strrchr(_DataFrame, ' ');

        size_t firstLength = lastSpace - _DataFrame; // oblicza gdzie znajdje się
        strncpy(firstArray, _DataFrame, firstLength);
        firstArray[firstLength] = '\0';

        strncpy(secondArray, lastSpace + 1, sizeof(secondArray) - 1);
        secondArray[strlen(secondArray)-1] = '\0';

        ControlSum = ComputeCRC8(firstArray, sizeof(firstArray), CRC8_POLYNOMIAL, CRC8_INIT);
        CuntrolSumRecivedData = atoi(secondArray);

        if(ControlSum == CuntrolSumRecivedData) {
            AddData(firstArray);
        }

        memset(_DataFrame, 0, sizeof _DataFrame);
        memset(firstArray, 0, sizeof firstArray);
    }
    else {
        strncat(_DataFrame, _Buffor, sizeof(_DataFrame));
    }

}

/*!
 * Zamuka port i przestaje wyświetlać aktualne dane.
 */

void MainWindow::on_closePort_clicked()
{
    _serialPort->disconnect();
    ui->connection->setText(tr("Not Connected"));
    _Connection = false;
    update();
    _Spaceship->ConnectLander(false);
}


/*!
 *  Włącza silniki - włącza animacje rysowania
 *  wiązek gazów odrzutowych
 */
void MainWindow::on_TurnOnEngine_clicked()
{
    _Gases->startEngine();
}

/*!
 *  Wyłącza silniki - zatrzymuje animacje rysowania
 *  wiązek gazów odrzutowych
 */

void MainWindow::on_TurnOffEngine_clicked()
{

    _Gases->stopEngine();
}

/*!
 *  Powoduję przetłumaczenie danych na aplikacji,
 *  aby były w języku angielskim
 */
void MainWindow::on_english_clicked()
{
    qApp->removeTranslator(T);
    ui->retranslateUi(this);

}

/*!
 *  Powoduję przetłumaczenie danych na aplikacji,
 *  aby były w języku niemieckim
 */
void MainWindow::on_german_clicked()
{
    if(T->load(":/new/prefix1/german.qm")){
        qApp->installTranslator(T);
    }

    ui->retranslateUi(this);
}

