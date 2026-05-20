#include <iostream>

using namespace std;

int main() {

    float arr[10];

    for (int i = 0; i < 10; i++) {
        cout << "Endereço da posição " << i << ": " << &arr[i] << "\n";
    }

    return 0;
}