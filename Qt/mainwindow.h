#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*!
* \file
* \brief Definicja klasy MainWindow
*/

/*!
* \brief Wartość inicjalizująca dla sumy kontrolnej
*/
#define CRC8_INIT        0
/*!
* \brief Wartość wielomianu dla sumy kontrolnej
*/
#define CRC8_POLYNOMIAL  0x39

#include <QMainWindow>
#include <QStatusBar>
#include <QTabWidget>
#include <QPixmap>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QtCore>
#include <qmath.h>
#include <string.h>

#include "lander.h"
#include "graphs.h"
#include "gases2.h"
#include "wektor2d.h"
#include <memory>
#include <list>
#include <cstring>
#include <QtCharts/QChartView>
#include <QTranslator>
#include <QFont>
QT_USE_NAMESPACE

/*!
* \brief Przestrzeń nazw UI
*/

namespace Ui{
    class MainWindow;
}

    /*!
     * \brief Główna klasa
     */
class MainWindow : public QMainWindow
{
   Q_OBJECT

private:

    Ui::MainWindow *ui;

    /*!
    * \brief Port seryjny do odbierania danych z akcelerometru
    */
    QSerialPort *_serialPort;

    /*!
    * \brief Lądownik
    */
    Lander* _Spaceship;


    graphs *_GraphX;
    graphs *_GraphY;
    graphs *_GraphZ;

    /*!
    * \brief Animacja gazów
    */
    gases2 *_Gases;
    void loadPorts();
    QPixmap English, German;
    QImage Cosmos, RedDott, GreenDott;

    /*!
    * \brief Bufor, do którego wczytywane są surowe dane
    */
    char _Buffor[50];

    /*!
    * \brief Pojedyńcza ramka danych
    */
    char _DataFrame[50];

    /*!
    * \brief Pojednyńcza dana w ramce
    */
    char* _word;

    /*!
    * \brief Obliczona suma kontrolna
    */
    int ControlSum;

    /*!
    * \brief Suma kontrolna dodana do ramki danych
    */
    int CuntrolSumRecivedData;

    /*!
    * \brief Sprawdza czy jest połączenie
    */
    bool _Connection;

    /*!
    * \brief Tablica z ramką danych
    */
    char firstArray[50];
    /*!
    * \brief Tablica z dodaną sumą kontrolną
    */
    char secondArray[10];
    /*!
    * \brief Zmienna służąca do tłumaczenia
    */
    QTranslator *T;

public:
    /*!
     * \brief Inicjalizuje wszystkie bitmapy
     */
    explicit MainWindow(QWidget *wParent = nullptr);

    /*!
     * \brief Funkcja wyliczająca sumę kontrolną
     */
    unsigned short int ComputeCRC8(char* pData, int Length, unsigned int Poly, unsigned short int InitVal);

    virtual void paintEvent( QPaintEvent * event ) override;
    /*!
    * \brief Dodaje dane do wyświetlenie zawartości ramki
    */
    bool AddData(char* DataFrame);

    /*!
    * \brief Wylicza kąt odchylenia
    */
    void CountAngles(double _x, double _y, double _z);

    /*!
    * \brief Desktuktor
    */
    ~MainWindow();

private slots:

    void ReadData();

    /*!
    * \brief Reaguje, kiedy zostanie klinknięty przycisk łączący aplikację z urządzeniem
    */
    void on_openPort_clicked();

    /*!
    * \brief Reaguje kiedy zostanie klinknięty przycisk odłączający aplikację z urządzeniem
    */
    void on_closePort_clicked();

    /*!
    * \brief Załącza silniki
    */
    void on_TurnOnEngine_clicked();

    /*!
    * \brief Odłącza silniki
    */
    void on_TurnOffEngine_clicked();

    /*!
    * \brief Przetłumacza na język angielski
    */
    void on_english_clicked();

    /*!
    * \brief Przetłumacza na język niemiecki
    */
    void on_german_clicked();
};
#endif // MAINWINDOW_H
