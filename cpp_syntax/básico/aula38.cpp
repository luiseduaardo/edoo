#include <iostream>

using namespace std;

void somar(float *var, float valor);
void iniVetor(float *v); 

int main() {

    float num = 0;
    float vetor[5];

    somar(&num, 15);      // mesmo em escopos diferentes, ao passar o endereço eu consigo mudar a variável
    iniVetor(vetor);      // como eu estou passando o vetor, não preciso usar o & (a não ser que eu passe &vetor[0])

    cout << num << "\n\n";

    for (int i = 0; i < 5; i++) {
        cout << vetor[i] << ' ';
    }

    return 0;
}

void somar(float *var, float valor) {
    *var+=valor;
}

void iniVetor(float *v) { // se eu não inicializar v como vetor, a parte de baixo nem é lida como array, mas como float
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
}