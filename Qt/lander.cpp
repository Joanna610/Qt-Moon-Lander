#include "lander.h"

/*!
 * Inicjalizuję lądownik - wczytuję jego rysunek oraz wielkość.
 */
Lander::Lander(QWidget *wParent) : QWidget(wParent) {
    _Lander.load("C:/Users/joann/Desktop/WDS/WDS3/image/ladownik.png");
    this->setGeometry(10,10,630,630);
}


/*!
* Sprawdza połączenie - jeśli wykryje połączenie z urządzeniem
* to załącza timer, który jest połączony za pomocą SLOT z funkcją,
* która uaktualnia parametry statku.
*/
void Lander::ConnectLander(bool connection){
    if(connection){
        connect(&_Timer,SIGNAL(timeout()),this,SLOT(updateLanderParameters()));

        _Timer.setInterval(10);
        _Timer.setSingleShot(false);
        _Timer.start();
    }
    else  _Timer.stop();

}

/*!
* Aktualizowane jest położenie lądownika w zależności
* od wczytanych danych
* \retval _Pos - zrwaca akualną pozycję lądownika
*/
Wektor2D Lander::setDirection(const int direct, const int landing){
    this->_Direction(direct, landing);
    return this->_Pos;
}


/*!
* Funckja ma za zadanie wyrysowywać dany statek. Pobiera ona rysunek,
* ustawia skale oraz pozycję.
*/
void Lander::paintEvent( QPaintEvent * )
{

    QPainter painter(this);
    painter.scale(X_SCALE, Y_SCALE);
    painter.drawImage(_Pos.getX(), _Pos.getY(), _Lander);
}

/*!
* Sprawdza czy wartość x i y znajduje się wewnątrz zdefiniowanych
* wartości maksymalnych dla danej skali w jakiej został zdefiniowany
* lądownik.
* \retval true - jeśli lądownik nie przekracza założonych ram
* \retval false - jeśli chce wyjść po za ustaloną ramę
*/
bool Lander::CheckBorder(Wektor2D pos){
    return pos < _MaxPos && pos > _MinPos;
}


/*!
* Sprawdza czy wartość x i y znajduje się wewnątrz zdefiniowanych
* wartości maksymalnych dla danej skali w jakiej został zdefiniowany
* lądownik.
*/
void Lander::updateLanderParameters(){
    Wektor2D new_pos = _Pos;
    new_pos +=_Direction;

    if(CheckBorder(new_pos)){
        _Pos = new_pos;
    }

    update();
}
