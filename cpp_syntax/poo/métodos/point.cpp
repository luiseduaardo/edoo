#include "Point.hpp"

void Point::moveTo(int px, int py) {
    x = px;
    y = py;
}

void Point::translate(int dx, int dy) {
    x += dx;
    y += dy;
}

int Point::getx() { return x; }

int Point::gety() { return y; }

void Point::setx(int val) { x = val; }

void Point::sety(int val) { y = val; }