#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    
    int vidas = 6, tam = 0, i = 0, acertos = 0;
    char palavra[30];
    bool jogando = true, ganhou = false, acerto;

    cout << "Selecione a palavra secreta para o seu adversário: ";
    cin >> palavra;

    system("cls");

    while (palavra[i] != '\0') {
        i++;
        tam++;
    }

    char secreta[tam];
    for (int j = 0; j < tam; j++) {
        secreta[j] = '_';
    }

    while (jogando) {
        cout << "Chances restantes: " << vidas << "\n";
        cout << "Palavra secreta: ";

        for (int k = 0; k < tam; k++) {
            cout << secreta[k];
        }

        cout << "\n";
        acerto = false;

        char letra[1];
        cout << "Escolha uma letra: ";
        cin >> letra;

        for (int l = 0; l < tam; l++) {
            if (palavra[l] == letra[0]) {
                acerto = true;
                secreta[l] = palavra[l];
                acertos++;
            }
        }

        if (!acerto) {
            vidas--;
        }

        system("cls");

        if (vidas == 0) {
            jogando = false;
            cout << "Poxa que pena! Infelizmente você perdeu!\nA palavra correta era " << palavra;
        }
        if (acertos == tam) {
            jogando = false;
            cout << "Parabéns, você ganhou o jogo!\nA palavra correta era ";

            for (int m = 0; m < tam; m++) {
                cout << secreta[m];
            }
        }
    }

    return 0;
}