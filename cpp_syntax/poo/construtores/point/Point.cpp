#include "Point.h"
#include <iostream>

// -----------------------------------------------
// Definição da Classe Point
// -----------------------------------------------

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int ax, int ay) {
    x = ax;
    y = ay;
}

void Point::MoveTo(int px, int py)
{
	x = px;
	y = py;
}

void Point::Translate(int dx, int dy)
{
	x += dx;
	y += dy;
}

void Point::print() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

// -----------------------------------------------