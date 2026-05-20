// apenas definição de classe, sem implementar

#include <iostream>

using namespace std;

class ContaBancaria {
private:
    string nomeCliente;
    int numeroConta;
    float saldoAtual;

public:
    ContaBancaria();
    void imprimirDados();
    void depositar(int valorDeposito);
    void sacar(int valorSaque);
};