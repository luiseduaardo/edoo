#include <iostream>

using namespace std;

int fibonacci(int num);

int main() {
    int n;

    cout << "Digite a quantidade de termos da sequência de Fibonacci que você deseja: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << fibonacci(i) << ' ';
    }

    cout << "O " << n << "-ésimo número da sequência de Fibonacci é igual a " << fibonacci(n-1);

    return 0;
}

int fibonacci(int num) {
    if (num <= 1) return num;
    else return fibonacci(num - 1) + fibonacci(num - 2);
}