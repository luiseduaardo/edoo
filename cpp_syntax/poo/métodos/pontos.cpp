#include "Point.hpp"
#include <iostream>

using namespace std;

int main() {

    Point p;
    cout << sizeof(p) << endl;    // output esperado: 8 (espaço do x e do y)

    p.moveTo(10, 20);
    cout << "(" << p.getx() << ", " << p.gety() << ")" << endl;

    p.translate(2, 5);
    cout << "(" << p.getx() << ", " << p.gety() << ")" << endl;

    return 0;
}