#include <iostream>

using namespace std;

struct Carro {
    string nome;
    string cor;
    int potencia;
    int vmax;  
};

int main() {

    Carro car1;
    Carro car2;

    car1.nome = "MP4/4";
    car1.cor = "vermelho";
    car1.potencia = 800;
    car1.vmax = 287;

    cout << "Nome.............: " << car1.nome << "\n";
    cout << "Cor..............: " << car1.cor << "\n";
    cout << "Potência.........: "<< car1.potencia << "\n";
    cout << "Velocidade máxima: " << car1.vmax << "\n";

    car2.nome = "RB25";
    car2.cor = "azul";
    car2.potencia = 1200;
    car2.vmax = 372;

    cout << "Nome.............: " << car2.nome << "\n";
    cout << "Cor..............: " << car2.cor << "\n";
    cout << "Potência.........: "<< car2.potencia << "\n";
    cout << "Velocidade máxima: " << car2.vmax << "\n";

    return 0;
}