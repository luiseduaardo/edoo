#include <iostream>

using namespace std;

class Coord {
private:
    int x = 0;
    int y = 0;

    bool valid(int ax, int ay) { return (x + ax <= 1920 || y + ay <= 1080); }

public:
    void translate(int dx, int dy);
    void moveto(int px, int py);
    void exibir();
};

void Coord::translate(int dx, int dy) {
    if (valid(dx, dy)) {
        x += dx;
        y += dy;
    }
}

void Coord::moveto(int px, int py) {
    if (valid(px, py)) {
        x = px;
        y = py;
    }
}

void Coord::exibir(){
    cout << "(" << x << ", " << y << ")\n";
}