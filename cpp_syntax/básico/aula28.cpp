#include <iostream>
#include <stack>

using namespace std;

// stacks funcionam sob a estrutura last-in, first-out (primeiro que entra é o último que sai)

int main() {

    stack<string> cartas;

    
    // tem como origem a POO:
        // cartas é uma classe com o método push (adiciona cartas) que tem herança de uma classe chamada stack
    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    while (!cartas.empty()) {
        // para verificar se a nossa pilha está vazia, usamos o método .empty()
        if (cartas.empty()) { // também podemos usar if (cartas.size() == 0)
            cout << "\nPilha vazia.\n\n"; 
            // esse comando nem chega a ser executado aqui porque quando a stack fica vazia, o while já encerra o loop e não chega nessa condicional
        } else {
            cout << "\nPilha com cartas.\n\n";
        }


        cout << "Tamanho da pilha: " << cartas.size() << "\n";

        cout << "Carta do topo: " << cartas.top() << "\n";

        // retirando um elemento da pilha: método pop()
            // retira o elemento do topo, no nosso caso, é o Rei de Paus, já que ele foi adicionado por último
        cartas.pop();
    }

    /*
    stack1.emplace(e_x);      - adiciona um elemento no topo, assim como o push;
    stack1.swap(stack2);      - troca o conteúdo de uma stack com outra stack;
    */

    return 0;
}