#include "Point.h"

class Rect {
private:
    Point a;
    Point b;

public:
    Rect();
    Rect(Point x, Point y);
    Rect(int ax, int ay, int bx, int by);
    void translate(int dx, int dy);
};