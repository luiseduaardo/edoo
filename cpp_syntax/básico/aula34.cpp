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

    Carro car1, car2, car3, car4;

    car1.insere("RB25", "azul", 1200, 370);
    car2.insere("SF25", "vermelho", 1150, 368);
    car3.insere("MP4/4", "vermelho e branco", 850, 300);
    car4.insere("Lotus xx", "preto", 980, 345);

    car1.mostra();
    car1.mudaVel(150);
    car1.mostra();

    return 0;
}