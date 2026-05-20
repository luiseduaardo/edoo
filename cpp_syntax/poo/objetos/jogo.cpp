#include <iostream>
#include "../encapsulamento/jogo.hpp"

using namespace std;

int main() {
    
    Jogo gears;
    Jogo doom;

    gears.adquirir("Gears", 75);
    gears.jogar(5);
    gears.exibir();
    cout << "Mem: " << &gears << "\n";

    cout << "-----------------------------------------------\n";
    
    doom.adquirir("Doom", 90);
    doom.jogar(3);
    doom.exibir();
    cout << "Mem: " << &doom << "\n";

    return 0;
}