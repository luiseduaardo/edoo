#include <iostream>
using namespace std;

int main() {
    // Para a inicialização de variáveis, devemos dizer o seu tipo e nome, podendo ou não inicializar com um valor
    // Caso não inicializemos com um valor, teremos um garbage value

        // TIPO nome;
        // TIPO nome = valor;

    int vidas = 0;            // 10, 25
    char letra = 'b';         // 'b'
    char letras[20];          // cria um vetor com n letras
    double decimal = 2.5;     // 2.4999999999999
    float decimal2 = 2.5;     // 2.5
    bool vivo = true;         // true ou false
    string nome = "luis";     // "Luís"

    cout << "vidas (int):            " << vidas << endl;
    cout << "letra (char):           " << letra << endl;
    cout << "decimal (float/double): " << decimal << endl;
    cout << "vivo (bool):            " << vivo << endl;
    cout << "nome (string):          " << nome << endl;

    // Como inicializar as variáveis do teclado? Usando o cin

    cout << "Digite o número de vidas: ";
    cin >> vidas;

    cout << "vidas (input do teclado): " << vidas << endl;

    return 0;
}