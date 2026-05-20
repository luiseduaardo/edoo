#include <iostream>
using namespace std;

int main() {

    int cont;

    // na prática, a diferença é que o do while executa pelo menos uma vez antes de realizar a verificação
    cont = 20;
    do {
        cout << cont << endl;
        cont++;
    } while (cont < 20);

    cout << "\nRotina finalizada\n";

    return 0;
}