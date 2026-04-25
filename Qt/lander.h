#ifndef LANDER_H
#define LANDER_H

/*!
* \file
* \brief Definicja klasy Lander
*
* Plik zawiera definicję klasy Lander, która
* jest klasą pochodną i dziedziczy po klasie QWidget
*/

#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QTimer>

#include "wektor2d.h"

/*!
* \brief Wartość przeskalowania osi x dla lądownika
*/
#define X_SCALE 0.32
/*!
* \brief Wartość przeskalowania osi y dla lądownika
*/
#define Y_SCALE 0.32
/*!
* \brief Wartość początkowej pozycji x lądownika
*/
#define X_POS 700
/*!
* \brief Wartość początkowej pozycji y lądownika
*/
#define Y_POS 1000
/*!
* \brief Pozycja minimalna lądownika
*/
#define POS_MIN 10
/*!
* \brief Wartość maksymalna x lądownika
*/
#define X_POS_MAX 1500
/*!
* \brief Wartość maksymalna y lądownika
*/
#define Y_POS_MAX 1000


/*!
* \brief Wizualizacja statku odrzutowego
*
*   Klasa pobiera przekazaną bitmapę i wyświetla ją
*   w określonej pozycji w zależności od zadanych parametrów.
*   Poprzez cykliczne pobieranie nowych wartości z akcelerometru
*   klasa wizualizuje ruch lądownika.
*
*/
class Lander: public QWidget
{
    Q_OBJECT
    /*!
    * \brief Rysunek lądownika
    */
    QImage  _Lander;
    QTimer _Timer;

    /*!
    * \brief Aktualna pozycja lądownika
    */
    Wektor2D _Pos = Wektor2D(X_POS, Y_POS);

    /*!
    * \brief Kierunke ruchu lądownika
    */
    Wektor2D _Direction = Wektor2D(X_POS, Y_POS);

    /*!
    * \brief Pozycja maksymalna lądownika - prawy dolny róg
    */
    Wektor2D _MaxPos = Wektor2D(X_POS_MAX, Y_POS_MAX);

    /*!
    * \brief Pozycja minimalna lądownika - lewy górny róg
    */
    Wektor2D _MinPos = Wektor2D(POS_MIN, POS_MIN);

public:
    Lander(QWidget *wParent = nullptr);
    virtual void paintEvent( QPaintEvent * event ) override;
    /*!
    * \brief Zadanie wartości prywatnemu parametrowi
    */
    Wektor2D setDirection(const int direct, const int landing);

    /*!
    * \brief Funkcja sprawdzająca położenie statku
    */
    bool CheckBorder(Wektor2D pos);

    /*!
    * \brief Uruchamia Lądownik
    */
    void ConnectLander(bool connection);

public slots:
    /*!
    * \brief Sprawdza obecne parametry Lądownika
    */
    void updateLanderParameters();

};

#endif // LANDER_H
