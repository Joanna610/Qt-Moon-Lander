#include "gas.h"

/*!
* Zostają w nim zainicjowane wszystkie najważniejsze
* parametry w klasie, kluczowa w dalszyej animacji
*
*/
gas::gas(QWidget *wParent, int duration, int offset) : QWidget(wParent) {

    connect(&(this->_Timer),SIGNAL(timeout()),this,SLOT(updateGasParameters()));
    this->interval = 10;
    this->_Timer.setInterval(this->interval );
    this->_Timer.setSingleShot(false);
    this->_Duration = duration;
    this->setGeometry(10,10,630,630);
    this->offset =offset;
    this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/first_blob.png");
    this->timer = 0;
    hide();
}

/*!
* W tej funkcji zostaje ustawiona skala danej bitmapy
* oraz zostaje podana pozycja, w którj ma zostać narysowane
* dany obraz.
*/
void gas::paintEvent( QPaintEvent * )
{
    QPainter painter(this);
    painter.scale(X_SIZE, Y_SIZE);
    painter.drawImage(this->_Pos.getX(), this->_Pos.getY(), this->_Gas);

}

/*!
* Aktualizuej pozycję na jakiej znajduje się lądownik
*
*/
void gas::setPosition(Wektor2D pos){
    this->_currentLanderPosition(pos.getX() + X_OFFSET + this->offset, pos.getY() + Y_OFFSET);
}

/*!
* Rozpoczyna odliczanie timra, przez co jest możliwe
* ustawienie pozycji danej wiązki. Jest inicjalizowana pozycja
* w jakiej początkowo ma znaleść się dana wiązka w zależności
* od pozycji lądownika.
*
*/
void gas::startEngine(){
    _Timer.start();
}

/*!
* Zatrzymuje działanie Timera oraz ukrywa kuleczki.
*/
void gas::stopEngine(){

    _Timer.stop();
    hide();
}

/*!
* Aktualizowany jest kolor kulki, czyli wczytywana jest inna bitmapa
*/
void gas::updatePicture(int time){

    if(time == 0)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/first_blob.png");
    else if(time == _Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/second_blob.png");
    else if(time == 2*_Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/third_blob.png");
    else if(time == 3*_Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/fourth_blob.png");
    else if(time == 3*_Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/fifth_blob.png");
    else if(time == 5*_Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/sixth_blob.png");
    else if(time == 6*_Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/seventh_blob.png");
    else if(time == 7*_Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/eighth_blob.png");
    else if(time == 8*_Duration/9)this->_Gas.load("C:/Users/joann/Desktop/WDS/WDS3/image/ninth_blob.png");
}

/*!
* Sprawdzane jest na jakim poziomie ekranu się
* znajduje i aktualizowany jest jej stan - to
* znaczy kierunek, w którym ma się poruszać.
*
*/
void gas::updateGasParameters(){
    if(this->timer == this->_Duration){
        this->timer=0; // czas kuleczki sie skonczyl
        this->_Pos = this->_currentLanderPosition;
        this->interval = 10;
        this->_Timer.setInterval(this->interval );
    }
    else{
        this->timer++;

        if(_Pos < _MaxPos){
            this->_Pos.setLanding(20);
        }
        else{
            if(offset <= 30) {
                if(timer >= _Duration - 10){
                    this->interval+=1;
                    this->_Timer.setInterval(this->interval );
                    this->_Pos.setDirection(-10);
                }
                else this->_Pos.setDirection(-20);

            }
            else {
                if(timer >= _Duration - 10){
                    this->interval+=1;
                    this->_Timer.setInterval(this->interval );
                    this->_Pos.setDirection(10);
                }
                else this->_Pos.setDirection(20);
            }
        }
    }
    this->updatePicture(timer);
    update();
}


