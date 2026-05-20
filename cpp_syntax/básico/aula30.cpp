#include <iostream>
#include <queue>

using namespace std;

int main() {

    // queues (filas), por sua vez, atuam no sistema first in, first out (FIFO)
        // os comandos são exatamente iguais, apenas a fila que se comporta de maneira diferente
        // única diferença que ao invés de top, temos front e back
        // pop retira o elemento que está na primeira posição na fila

    queue<string> cartas;

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    while (!cartas.empty()) {
        cout << "Quantidade de cartas na fila: " << cartas.size() << "\n";
        
        if (cartas.size() > 1) {
            cout << "Carta da frente: " << cartas.front() << "\n";
            cout << "Carta de trás: " << cartas.back() << "\n\n";
        } else {
            cout << "Só existe uma carta na fila, que é a carta " << cartas.front() << "\n\n"; // poderia usar o back também
        }

        cartas.pop();
    }

    /*
    queue1.emplace(e_x);      - adiciona um elemento no topo, assim como o push;
    queue1.swap(queue2);      - troca o conteúdo de uma queue com outra queue;
    */

    return 0;
}