#include <iostream>

using namespace std;

// protótipo das funções: declara as funções antes do main
void texto();
void soma(int a, int b);
int soma_retorna (int a, int b);
void tr(string tra[4]);

int main() {

    /*
    for (int i = 0; i < 10; i++) {
        texto();
    }

    soma(15, 5);
    */

    int res = soma_retorna(15, 5);

    cout << "valor de res: " << soma << "\n";
    cout << "valor de res: " << soma_retorna(175, 25) << "\n";

    string transp[4] = {"carro", "moto", "barco", "avião"};

    tr(transp);

    return 0;
}

void texto() {
    cout << "hello, world\n";
}

void soma(int a, int b) {
    cout << "soma dos valores: " << a + b << "\n";
}

int soma_retorna (int a, int b) {
    return a + b;
}

void tr(string tra[4]) {
    for (int i = 0; i < 4; i++) {
        cout << tra[i] << "\n";
    }
}