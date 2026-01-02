#ifndef GASES2_H
#define GASES2_H

/*!
* \file
* \brief Definicja klasy Gases
*
* Plik zawiera definicję klasy Gases. Jest ona listą
* zawirającą w sobie obiekty klasy Gas.
* To ona odpowiada za zainicjowanie wszystkich kulek,
* rozpoczęcie ich animacji oraz ich zatrzymanie.
*/
#include "gas.h"
#include "wektor2d.h"

#include <memory>
#include <QDebug>
#include <list>
#include <cstdlib>
#include <ctime>


/*!
* \brief Wizualizuje całego strumienia gazów odrzutowych
*/
class gases2: public QWidget
{
    /*!
     * \brief Lista inicjalizująca wszystkie pojedyńcze kuleczki
     */
    std::list<std::shared_ptr<gas>> Gases;

public:
    gases2(QWidget* wParent);
    ~gases2() = default;

    /*!
     * \brief Aktualizuje obecną pozycje wszystkich kuleczek
     */
    void updateLanderPosition(Wektor2D pos);

    /*!
     * \brief Rozpozyna animację
     */
    void startEngine();

    /*!
     * \brief Zatrzymuję animację
     */
    void stopEngine();

};

#endif // GASES2_H
