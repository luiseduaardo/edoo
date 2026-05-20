#include <iostream>
using namespace std;

int main() {

    int linha = 3, coluna = 4;
    int matriz[linha][coluna];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}