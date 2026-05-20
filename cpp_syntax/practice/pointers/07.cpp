#include <iostream>

using namespace std;

void soma(int* pta, int* ptb);

int main() {

    int a, b;

    cin >> a;
    cin >> b;

    cout << "Resultado da soma de " << a << " com " << b << " é ";

    soma(&a, &b);

    cout << a;
    return 0;
}

void soma(int* pta, int* ptb) {
    *pta += *ptb;
}