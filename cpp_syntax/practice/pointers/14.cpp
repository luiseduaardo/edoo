// Crie uma func ̧  ̃ao que receba dois par ˆametros: um array e um valor do mesmo tipo do array. A func ̧  ̃ao dever  ́a preencher os elementos de array com esse valor. Nãoo utilize indices para percorrer o array, apenas aritm  ́etica de ponteiros

#include <iostream>

using namespace std;

void percorreArray(char* arr, char v);

int main() {
    char array[5];
    char valor = 'b';

    percorreArray(array, valor);
    
    for (char val : array) {
        cout << valor << ' ';
    }

    return 0;
}

void percorreArray(char* arr, char v) {
    while (*arr != '\0') {
        *arr = v;
        arr++;
    }
}