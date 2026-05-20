#include <iostream>

using namespace std;

int main() {

    int *p;
    int arr[10];
    p = arr;
    // isso é equivalente a &arr[0], logo o ponteiro aponta para o endereço do primero elemento da array
    // no fundo, arrays funcionam como ponteiros

    p = &arr[0];
    cout << "\n" << p << "\n";     // retorna o endereço do primeiro elemento

    p = &arr[1];  // *(p+=1) - faz o incremento de 4 bytes
    cout << "\n" << p << "\n";

    p = &arr[2];  // *(p+=1) - faz o incremento de 4 bytes
    cout << "\n" << p << "\n";

    *p = 10;      // o ponteiro atual aponta para o endereço de arr[2], logo arr[2] = 10
    cout << "\n" << arr[2] << "\n";

    *(p+=1);
    *p = 20;      // o ponteiro atual aponta para o endereço de arr[3], logo arr[3] = 20
    cout << "\n" << arr[3] << "\n";
    
    return 0;
}