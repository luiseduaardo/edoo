#include <iostream>
using namespace std;

int main() {

    int cont;

    cont = 0;
    while(cont < 20) {
        cout << cont << "\n";
        cont++;

        if (cont == 10) {
            break;
        }
    }

    cout << "\nRotina finalizada\n";

    return 0;
}