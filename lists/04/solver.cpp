#include <iostream>
#include "trie.hpp"

#include <cassert>

int main() {

    // ADD CODE HERE

    Trie trie;

    while (1) {
        char operation;
        string word;

        cin >> operation;
        if (operation == '#') break;
        cin >> word;

        if (operation == 'I' || operation == 'D' || operation == 'Q') {
            word += '$';
        }

        if (operation == 'I') { // operação de inserção
            trie.insert(word);
            cout << trie.size() << endl;
        }
        else if (operation == 'D') { // operação de remoção
            trie.remove(word);
            cout << trie.size() << endl;
        }
        else if (operation == 'Q') { // operação de consultar palavra
            if (trie.contains(word)) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if (operation == 'L') { // consulta a K-ésima palavra em ordem lexicográfica
            int k = stoi(word);
            string result = trie.getKth(k);

            // tem que tirar o $ porque o sanity exige que o resultado seja retornado com $
            if (result != "" && result.back() == '$') {
                result.pop_back(); 
            }

            cout << result << endl;
        }
    }
}
