#include <iostream>

using namespace std;

int somadobro(int* pta, int* ptb);

int main() {

    int a, b;

    cin >> a;
    cin >> b;

    cout << "A soma dos dobros de " << a << " e " << b << " é igual a " << somadobro(&a, &b) << "\n\n";

    return 0;
}

int somadobro(int* pta, int* ptb) {
    *pta *= 2;
    *ptb *= 2;

    return *pta + *ptb;
}