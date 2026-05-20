#include <iostream>

using namespace std;

int main() {

    string veiculo = "carro";
    string *pv;       // o ponteiro deve ser do mesmo tipo da variável que ele vai apontar
    pv = &veiculo;    // o ponteiro pv recebe o endereço da variável veículo

    cout << veiculo << "\n";         // imprime a variável
    cout << pv << "\n";              // imprime o endereço
    cout << &veiculo << "\n";        // imprime o endereço
    cout << *pv << "\n\n";           // imprime a variável

    *pv = "Moto";    // no endereço apontado por *pv, mude adicione moto

    cout << veiculo << "\n";         // imprime a variável
    cout << pv << "\n";              // imprime o endereço
    cout << &veiculo << "\n";        // imprime o endereço
    cout << *pv << "\n\n";           // imprime a variável

    return 0;
}