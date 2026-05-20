#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n1, n2, res;
    char opc;

    inicio: // label pré definida para usar no goto posteriormente
    system("cls");

    cout << "Digite o valor da nota 1: ";
    cin >> n1;

    cout << "Digite o valor da nota 2: ";
    cin >> n2;

    res = n1 + n2;

    /* 
    Notas maiores ou iguais a 60, o aluno vai estar aprovado;
    Notas entre 40 e 59, o aluno vai estar de recuperação;
    Menor que 40, está reprovado.
    */

    if (res >= 60) {
        cout << "\nAluno aprovado!\n";
    } else if (res >= 40) {
        cout << "\nAluno de recuperação!\n";
    } else {
        cout << "\nAluno reprovado\n";
    }

    cout << "Digitar outras notas? (s/n) ";
    cin >> opc;

    if (opc == 's' or opc == 'S') {
        goto inicio; // vai para label definida inicialmente
    }

    return 0;
}
