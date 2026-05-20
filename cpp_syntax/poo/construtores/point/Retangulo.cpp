#include "Rect.h"
#include <iostream>

int main() {

    Point x {1, 3};
    Point y {2, 4};

    Rect a;
    Rect b { x, y };
    Rect c { 4, 7, 8, 3 };

    return 0;
}