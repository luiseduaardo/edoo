#include <iostream>
#include <string>

using namespace std;

struct Jogo {
    string nome;
    float preco;
    int horas;
    float custo;
};


Jogo adquirir(const string& titulo, float valor);
void atualizar(Jogo& jogo, float valor);
void jogar(Jogo& jogo, int tempo);
void exibir(const Jogo& jogo);


Jogo adquirir(const string& titulo, float valor) {
    Jogo novo;
    novo.nome = titulo;
    novo.preco = valor;
    novo.horas = 0;
    novo.custo = valor;

    return novo;
}

void atualizar(Jogo& jogo, float valor) {
    jogo.preco = valor;

    jogo.custo = jogo.horas > 0 ? (jogo.preco / jogo.horas) : jogo.custo;
}

void jogar(Jogo& jogo, int tempo) {
    jogo.horas += tempo;

    jogo.custo = jogo.horas > 0 ? (jogo.preco / jogo.horas) : jogo.custo;
}

void exibir(const Jogo& jogo) {
    cout << jogo.nome << " R$"
         << jogo.preco << " "
         << jogo.horas << "h = R$"
         << jogo.custo << "/h\n";
}

int main() {
    Jogo gow = adquirir("GOW", 160);
    exibir(gow);

    jogar(gow, 2);
    exibir(gow);

    jogar(gow, 14);
    exibir(gow);

    return 0;
}