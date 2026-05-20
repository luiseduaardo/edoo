#include <iostream>

using namespace std;

int main() {

    int arr[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Endereço de memória do elemento na linha " << i << " e na coluna " << j << ": " << &arr[i][j] << "\n";
        }
    }

    return 0;
}