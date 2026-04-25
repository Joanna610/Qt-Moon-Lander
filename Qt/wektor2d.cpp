#include "wektor2d.h"

Wektor2D::Wektor2D() {
    this->x = 0;
    this->y = 0;
}

Wektor2D::Wektor2D(const int _x, const int _y){
    this->x = _x;
    this->y = _y;
}

Wektor2D::~Wektor2D(){
}

Wektor2D::Wektor2D(const Wektor2D & wek){
    this->x = wek.x;
    this->y = wek.y;
}

Wektor2D& Wektor2D::operator=(const Wektor2D & wek){
    this->x = wek.x;
    this->y = wek.y;
    return *this;
}

Wektor2D& Wektor2D::operator+=(const Wektor2D & wek){
    //Wektor2D wek2;
    this->x += wek.x;
    this->y += wek.y;
    return *this;
}

bool Wektor2D::operator < (const Wektor2D & wek) const{
    return this->x < wek.x && this->y < wek.y;
}

bool Wektor2D::operator > (const Wektor2D & wek) const{
    return this->x > wek.x && this->y > wek.y;
}
