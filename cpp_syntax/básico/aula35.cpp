#include <iostream>

using namespace std;

struct Carro {
    string nome;
    string cor;
    int potencia;
    int vmax;
    int vel;

    void insere(string stnome, string stcor, int stpot, int stvmax) {
        nome = stnome;
        cor = stcor;
        potencia = stpot;
        vmax = stvmax;
        vel = 0;
    }

    void mostra() {
        cout << "\nNome.............: " << nome << "\n";
        cout << "Cor..............: " << cor << "\n";
        cout << "Potência.........: "<< potencia << "\n";
        cout << "Velocidade atual.: "<< vel << "\n";   
        cout << "Velocidade máxima: " << vmax << "\n";
    }

    void mudaVel(int mv) {
        vel = mv;
        if (vel > vmax) vel = vmax;
        if (vel < 0) vel = 0;

    }
};

int main() {

    Carro *carros=new Carro[5];

    Carro car1, car2, car3, car4, car5;

    carros[0] = car1;
    carros[1] = car2;
    carros[2] = car3;
    carros[3] = car4;
    carros[4] = car5;

    carros[0].insere("RB25", "azul", 1200, 370);
    carros[1].insere("SF25", "vermelho", 1150, 368);
    carros[2].insere("MP4/4", "vermelho e branco", 850, 300);
    carros[3].insere("Lotus xx", "preto", 980, 345);
    carros[4].insere("VCARB", "branco", 1100, 350);

    for (int i = 0; i < 5; i++) {
        carros[i].mostra();
    }

    return 0;
}