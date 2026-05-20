#include <iostream>

using namespace std;

int main() {

    int a;
    int b;

    int* pta;
    int* ptb;

    pta = &a;
    ptb = &b;

    // compara o maior endereço, mas não necessariamente é o maior conteúdo
    if (pta > ptb) {
        cout << *pta;
    } else {
        cout << *ptb;
    }

    return 0;
}