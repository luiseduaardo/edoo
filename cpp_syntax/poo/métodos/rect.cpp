#include "rect.hpp"

void Rect::create(int ax, int ay, int bx, int by) {
    a.setx(ax);
    b.setx(bx);

    a.sety(ay);
    a.sety(by);
}

void Rect::translate(int dx, int dy) {
    a.translate(dx, dy);
    b.translate(dx, dy);
}