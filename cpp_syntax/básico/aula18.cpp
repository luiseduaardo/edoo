#include <iostream>
using namespace std;

int main() {

    int tamanho = 7;
    int vetor[tamanho];

    /*
    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;
    vetor[3] = 40;
    vetor[4] = 50;
    vetor[5] = 60;
    vetor[6] = 70;
    */

    for (int k = 0; k < tamanho; k++) {
        if (k == 0) {
            vetor[k] = 10;
        } else {
            vetor[k] = vetor[k-1] + 10;
        }
    }

    /*
    cout << vetor[0] << "\n";
    cout << vetor[1] << "\n";
    cout << vetor[2] << "\n";
    cout << vetor[3] << "\n";
    cout << vetor[4] << "\n";
    */

    for (int num : vetor) {
        cout << num << "\n";
    }

    return 0;
}