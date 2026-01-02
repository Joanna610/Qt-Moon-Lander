#include "gases2.h"

/*!
* Inicjalizuje wszystkie kuli oraz nadaje im wartości
*/
gases2::gases2(QWidget *wParent) : QWidget(wParent) {

    int duration = 0, min = 15, max = 30, position = 0;
    std::srand(std::time(nullptr));
    for(int i = 0; i< 30; i++){

        duration = rand() % (max - min + 1) + min;
        this->Gases.push_back(std::make_shared<gas>(wParent, duration, position+=2));

    }
}


/*!
* Aktualizuje obecny stan lądownika i przekazuj go dalej do funkcji
*/
void gases2::updateLanderPosition(Wektor2D pos){

    for(auto& gas : Gases){
       gas->setPosition(pos);
    }
}

/*!
* Rozpoczęcie animacji wszystkich kulek
*/
void gases2::startEngine()
{

    for (const auto &gas : Gases) {
        gas->startEngine();
        gas->show();
    }
}

/*!
* Zatrzymanie animacji
*/
void gases2::stopEngine()
{
    for (const auto &gas : Gases) {
        gas->stopEngine();
    }
}
