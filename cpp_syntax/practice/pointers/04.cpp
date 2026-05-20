#include <iostream>

using namespace std;

void troca(int* pta, int* ptb);

int main() {

    int a;
    int b;

    cin >> a;
    cin >> b;

    cout << "\nAntes da mudança:";
    cout << "\na = " << a;
    cout << "\nb = " << b;

    troca(&a, &b);

    cout << "\nDepois da mudança:";
    cout << "\na = " << a;
    cout << "\nb = " << b;
    
    cout << "\n";

    return 0;
}

void troca(int* pta, int* ptb) {
    int temp = *pta;
    *pta = *ptb;
    *ptb = temp;
}