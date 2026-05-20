#include <iostream>
using namespace std;

int main() {

    int n1, n2, nota;
    string res;

    cout << "Digite a primeira nota: ";
    cin >> n1;
    cout << "Digite a segunda nota: ";
    cin >> n2;

    nota = n1 + n2;

    /*
    >= 60  aprovado
    < 60   reprovado
    */

    // (expressao) ? valor1 : valor1;
            //   verdadeiro    falso
    (nota >= 60) ? res = "Aprovado" : res = "Reprovado";

    /* nesse caso, a string não é atribuida ao valor do res, é apenas um valor de retorno
        res será true ou false, a depender do teste lógico
        
    res=(nota >= 60) ? "Aprovado" : "Reprovado";*/


    cout << "\nSituação: " << res << "\n\n";
    
    return 0;
}