#include <iostream>

using namespace std;

class Jogo {
private:
    string nome;
    float preco;
    int horas;
    float custo;

    void calcular() { if (horas > 0) custo = preco / horas; }

public:
    void adquirir(const string& titulo, float valor);
    void atualizar(float valor);
    void jogar(int tempo);
    void exibir();
};

void Jogo::adquirir(const string& titulo, float valor) {
    nome = titulo;
    preco = valor;
    horas = 0;
    custo = preco;
}

void Jogo::atualizar(float valor) {
    preco = valor;
    calcular();
}

void Jogo::jogar(int tempo) {
    horas += tempo;
    calcular();
}

void Jogo::exibir() {
    cout << nome << " R$"
         << preco << " "
         << horas << "h = R$"
         << custo << "/h\n";
}