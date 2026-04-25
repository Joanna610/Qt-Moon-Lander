#ifndef GASES_H
#define GASES_H

/*!
* \file
* \brief Definicja klasy Gas
*
* Plik zawiera definicję klasy Gas - ma ona zdefiniowane
* położenie, ruch oraz inne animacje pojedyńczej cząstki gazów
*
*/

#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QTime>

#include "wektor2d.h"

/*!
* \brief Wartość przeskalowania osi x dla lądownika
*/
#define X_SIZE 0.32
/*!
* \brief Wartość przeskalowania osi y dla lądownika
*/
#define Y_SIZE 0.32

/*!
* \brief Maksymalna linia do jakiej może dojść kuleczka
*/
#define MAX_LINE_GAS 45000

/*!
* \brief Wartość minimalna na osi x
*/
#define MIN_x 60000

/*!
* \brief Wartość minimalna na osi y
*/
#define MIN_y 100

/*!
* \brief Wartość offset x - wartość przesunięcia położenia kuleczek względem środka silnika dla osi x
*/
#define X_OFFSET 200
/*!
* \brief Wartość offset y - wartość przesunięcia położenia kuleczek względem środka silnika dla osi y
*/
#define Y_OFFSET 400

/*!
* \brief Wizualizuje pojedyńczy strumień gazów odrzutowych - jego ruch oraz to jak się zachowuje
*/
class gas: public QWidget
{
    Q_OBJECT

    /*!
     * \brief Zmienna, w której znajduje się wczytany obraz
     */
    QImage  _Gas;

    /*!
     * \brief Zmienna odmierzająca czas
     */
    QTimer _Timer;

    /*!
     * \brief Pozycja na jakiej znajduje się dana kuleczka
     */
    Wektor2D _Pos = Wektor2D(700+X_OFFSET, 1000+Y_OFFSET);
    /*!
     * \brief Pozycja maksymalna na jakiej może znajdować się dana kuleczka
     */
    Wektor2D _MaxPos = Wektor2D(1890, 1400);
    /*!
     * \brief Pozycja minimalna na jakiej może znajdować się dana kuleczka
     */
    Wektor2D _MinPos = Wektor2D(10, 10);

    /*!
     * \brief Wektor przechowujący aktualną pozycję lądownika
     */
    Wektor2D _currentLanderPosition = Wektor2D(700+X_OFFSET, 1000+Y_OFFSET);
    /*!
     * \brief Czas trwania kuleczki - określony w konstruktorze
     */
    int _Duration;

    /*!
     * \brief Pozycja kuleczki - w jakim miejscu względem otworu silnika się znajduje
     */
    int offset;
    /*!
     * \brief Obecny czas trwania kuleczki - od zera do wartości _Duration
     */
    int timer;

    /*!
     * \brief Interwał czasowy jaki zlicza timer
     */
    int interval;


public:
    gas() = default;

    /*!
    * \brief Inicjalizuje dane dotyczące położenia
    */
    gas(QWidget *wParent = nullptr, int duration = 0, int offset = 0);
    virtual void paintEvent( QPaintEvent * event ) override;
    /*!
     * \brief Aktualizuje pozycję lątownika
     */
    void setPosition(Wektor2D pos);
    /*!
     * \brief Aktualizuje kolor kuleczek
     */
    void updatePicture(int time);
    /*!
    * \brief Załącza silniki - razpoczęcia animacji
    */
    void startEngine();
    /*!
    * \brief Wyłącza silniki - zatrzymywana jest animacja
    */
    void stopEngine();

public slots:

    /*!
    * \brief Sprawdza obecne parametry wiązki gazów
    */
    void updateGasParameters();
};

#endif // GAS_H
