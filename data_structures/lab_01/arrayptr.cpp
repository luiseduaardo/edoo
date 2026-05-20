#include <iostream>

using namespace std;

void trocaArray(int* pta, int* ptb);

int main() {
    int elementos;

    cin >> elementos;

    int arr[elementos];

    int n = 0;
    int selected = -1;

    cout << "Array antes da troca:\n";
    for (int i = 0; i < elementos; i++) {
        do {
            selected = rand() % 1000;
        } while (selected < n);

        arr[i] = selected;
        cout << arr[i] << ' ';
        n = selected;
    }

    cout << "\n\nArray depois da troca:\n";
    for (int i = 0; i < (elementos/2); i++) { // itera até a metade da lista
        trocaArray(&arr[i], &arr[elementos-i-1]);
    }

    for (int i = 0; i < elementos; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}

void trocaArray(int* pta, int* ptb) {
    int temp = *pta;
    *pta = *ptb;
    *ptb = temp;
}