#include "coord.hpp"

using namespace std;

int main() {

    Coord ponto;
    ponto.moveto(10, 10);
    ponto.exibir();

    ponto.moveto(2000, 2000);
    ponto.exibir();

    ponto.translate(2, 5);
    ponto.exibir();

    return 0;
}