#include <iostream>
#include <jogo.hpp>

using namespace std;

int main() {

    Jogo gow;

    gow.adquirir("gow", 160);
    gow.exibir();

    gow.jogar(5);
    gow.exibir();

    gow.jogar(3);
    gow.exibir();

    gow.jogar(8);
    gow.exibir();

    return 0;
}