#include <iostream>

using namespace std;

void contador(int num, int cont=0);

int main() {

    contador(10);

    return 0;
}

void contador(int num, int cont) {
    cout << cont << "\n";

    if (num > cont) {
        contador(num, ++cont);
    }
}

/* FUNÇÃO IMPLEMENTADA SEM RECURSIVIDADE
void contador(int num) {
    for (int i = 0; i < num; i++) {
        cout << i << "\n";
    }
}
*/