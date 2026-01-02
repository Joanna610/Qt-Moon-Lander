#ifndef WEKTOR2D_H
#define WEKTOR2D_H

/*!
* \file
* \brief Definicja klasy Wektor2D
*/

class Wektor2D
{
    int x;
    int y;
public:
    /*!
    * \brief Konstruktor
    */
    Wektor2D();

    /*!
    * \brief Konstruktor parametryczny
    */
    Wektor2D(const int _x, const int _y);

    /*!
    * \brief Destruktor
    */
    ~Wektor2D();

    /*!
    * \brief Konstruktor kopjujący
    */
    Wektor2D(const Wektor2D & wek);

    /*!
    * \brief Operator przypisania
    */
    Wektor2D& operator=(const Wektor2D & wek);

    /*!
    * \brief Przeciążenie dodawania
    */
    Wektor2D& operator+=(const Wektor2D & wek);

    /*!
    * \brief Konstruktor przenoszenia
    */
    Wektor2D(Wektor2D && wek);

    /*!
    * \brief Operator przenoszenia
    */
    Wektor2D& operator=(const Wektor2D && wek);

    bool operator < (const Wektor2D & wek) const;
    bool operator > (const Wektor2D & wek) const;

    void operator()(int x, int y) { this->x = x; this->y = y; }
    int getX(){return this->x;}
    int getY(){return this->y;}

    /*!
    * \brief Funkcja set nadająca wartość y
    */
    void setLanding(const int y){this->y+=y;}

    /*!
    * \brief Funkcja set nadająca wartość x
    */
    void setDirection(const int x){this->x+=x;}

};

#endif // WEKTOR2D_H
