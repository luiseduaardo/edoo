#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> aula;
    int tam = 10;
    list<int>::iterator it = aula.begin();

    for (int i = 0; i < tam; i++) {
        aula.push_back(i);             // o método push_front adiciona no começo da lista, enquanto o push_back no final
    }

    // adicionando o número 0 na posição 5 por meio do iterator que criamos anteriormente
    advance(it, 5);
    aula.insert(it, 0);

    // assim como no insert, o erase remove o elemento na posição que eu escolher (definida pelo iterator)
    advance(it, 3);
    aula.erase(--it);

    tam = aula.size();
    cout << "Tamanho da lista: " << tam << "\n\n";

    for (int i = 0; i < tam; i++) {
        cout << aula.front() << " ";
        aula.pop_front();
    }
    cout << "\n\n";

    return 0;
}