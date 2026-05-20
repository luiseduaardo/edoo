#include "Rect.h"

Rect::Rect() {
    a = Point(0, 0);
    b = Point(0, 0);
}

Rect::Rect(Point x, Point y) {
    a = x;
    b = y;
}

Rect::Rect(int ax, int ay, int bx, int by) {
    a = Point(ax, ay);
    b = Point(bx, by);
}

void Rect::translate(int dx, int dy) {
    a.Translate(dx, dy);
    b.Translate(dx, dy);
}