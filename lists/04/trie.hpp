#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Trie {
    struct Node {
        char label;       
        uint nchd;
        uint leafCount;  // number of leaves on subtreee rooted at this node
        Node *firstChd;
        Node *sibling;

        ~Node() {
            if (firstChd != nullptr) delete firstChd;
            if (sibling != nullptr)  delete sibling;
        }

        // Returns the child of this node with label c, if any, 
        // or else return nullptr
        Node *getChd(char c) {
            Node* filho = firstChd;

            while (filho != nullptr) {
                if (filho->label == c) {
                    return filho;
                }

                filho = filho->sibling;
            }

            return nullptr;
        }
       
        // Add a child node with label c to the current node
        Node *addChd(char c) {
            Node* filho = firstChd;

            if (firstChd == nullptr || c < filho->label) {
                Node* novoFilho = new Node {c, 0, 0, nullptr, firstChd};
                firstChd = novoFilho;
                this->nchd++;
                return novoFilho;
            }
            
            while (filho->sibling != nullptr && c > filho->sibling->label) {
                filho = filho->sibling;
            }

            Node* novoFilho = new Node {c, 0, 0, nullptr, filho->sibling};
            filho->sibling = novoFilho;
            this->nchd++;

            return novoFilho;
        }
   
        // Inserts the string word[start:] in the trie rooted at this node.
        // Returns true if the insertion was sucessful
        // or false if the trie already contained word[start:]
        bool insert(const string &word, int start = 0) {
            char caracterAtual = word[start];
            Node* nodo_filho = getChd(caracterAtual); // filho do caracter atual, se não tiver é nullptr
            
            if (caracterAtual == '$') { // caso base
                if (nodo_filho == nullptr) { // se o filho não existe
                    this->addChd(caracterAtual);
                    this->leafCount++;
                    return true;
                } else { // se o filho existe
                    return false;
                }
            } else {
                if (nodo_filho == nullptr) { // se o filho não existe
                    nodo_filho = this->addChd(caracterAtual);
                }

                bool resultado = nodo_filho->insert(word, start+1);
                if (resultado) this->leafCount++;

                return resultado;
            }
        }

        // Removes the string word[start:] from the trie rooted at this node.
        // Returns true if the removal was sucessful
        // or false if the trie did not contain word[start:]
        bool remove(const string &word, int start = 0) {
            char caracterAtual = word[start];
            Node* nodo_filho = getChd(caracterAtual);

            if (nodo_filho == nullptr) return false; // trie não contém a palavra

            if (caracterAtual == '$') {
                remover_no(nodo_filho);
                this->leafCount--;
                return true;
            } else {
                bool removeu = nodo_filho->remove(word, start+1);

                if (removeu) {
                    this->leafCount--;
                    if (nodo_filho->nchd == 0) {
                        remover_no(nodo_filho);
                    }
                }
                return removeu;
            }
        }

        void remover_no(Node* filho) {
            if (filho == firstChd) {
                firstChd = filho->sibling;
                filho->sibling = nullptr;
            } else {
                Node* cur = firstChd;

                while (cur->sibling != filho) {
                    cur = cur->sibling;
                }

                cur->sibling = filho->sibling;
                filho->sibling = nullptr;
            }
            delete filho;
            this->nchd--;
        }

        // Returns the k-th (k>=0) string represented in the subtrie
        // rooted at this node.
        string getKth(uint k, string prefix) {
            Node* cur = firstChd;

            while (cur != nullptr) {
                if (cur->label == '$') {
                    if (k == 0) return prefix + cur->label;
                    else k--; 
                } 
                else {
                    if (k < cur->leafCount) { // desce pro first chd do cur
                        return cur->getKth(k, prefix + cur->label);
                    } else { // segue pro irmão do cur e diminui a quantidade de nós filhos desse nó atual
                        k -= cur->leafCount;
                    }
                }
                cur = cur->sibling;
            }
            return "";
        }

    };
private:

    Node *root;   // trie root node
    
public:

    Trie();

    ~Trie();

    // Returns the number of words represented in this trie (# leaves)
    uint size();
  
    // Checks whether the trie contains the string word
    bool contains(const string &word);
   
    // Inserts the word in the trie.
    // Returns true if insertion succeeded or false if the trie
    // already contained the word.
    bool insert(const string &word);
    
    // Removes the word from the trie.
    // Returns true if deletion succeeded or false if the trie
    // did not contain the word.
    bool remove(const string &word);
  
    // Returns the k-th word represented in the trie 
    // in lexicographic order
    string getKth(uint k);

};

//
// ADD IMPLEMENTATION CODE HEHE
//

Trie::Trie() {
    root = new Node {'\0', 0, 0, nullptr, nullptr};
}

Trie::~Trie() {
    delete root;
}

uint Trie::size() {
    return root->leafCount;
}

bool Trie::contains(const string &word) {
    string word_search = word;
    Node* cur = root;

    for (int i = 0; i < word_search.length(); i++) {
        Node* resultado = cur->getChd(word_search[i]);
        
        if (resultado == nullptr) return false;
        
        cur = resultado;
    }

    return true;
}

bool Trie::insert(const string &word) {
    return root->insert(word);
}

bool Trie::remove(const string &word) {
    return root->remove(word);
}

string Trie::getKth(uint k) {
    return root->getKth(k, "");
}
