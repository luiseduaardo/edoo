#include "Point.hpp"

class Rect {
private:
    Point a;
    Point b;

public:
    void create(int ax, int ay, int bx, int by);
    void translate(int dx, int dy);
};