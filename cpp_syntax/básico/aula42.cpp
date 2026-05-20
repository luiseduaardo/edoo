#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> num1;
    vector<int> num2;
    int tam;

    // push_back: adiciona um elemento ao vector
    num1.push_back(1); num1.push_back(2); num1.push_back(3); num1.push_back(4);

    tam = num1.size(); // retorna o tamanho do vector

    cout << "Tamanho do vector: " << tam << endl;

    num2.push_back(5); num2.push_back(6); num2.push_back(7); num2.push_back(8);

    cout << endl << "Antes do swap: " << endl;
    for (int i = 0; i < tam; i++) {
        cout << num1[i] << ' ';
    }

    cout << endl;
    for (int i = 0; i < tam; i++) {
        cout << num2[i] << ' ';
    }

    num1.swap(num2); // troca os valores dos vectors

    cout << endl << "Depois do swap: " << endl;
    for (int i = 0; i < tam; i++) {
        cout << num1[i] << ' ';
    }

    cout << endl;
    for (int i = 0; i < tam; i++) {
        cout << num2[i] << ' ';
    }

    cout << endl;
    cout << "\nPrimeiro valor de num1: " << num1.front() << endl;
    cout << "Último valor de num1..: " << num1.back() << endl;
    cout << "Valor do meio.........: " << num1.at(tam/2) << endl;

    num1.insert(num1.begin(), 888); // adiciona em uma posição específica (usa iterator, mas será visto mais pra frente)

    return 0;
}