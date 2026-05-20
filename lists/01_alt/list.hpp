#include <cstddef>
#include <cassert>
#include <string>

using namespace std;

struct Node {
    string value;
    Node* next = nullptr;
};

class LinkedList {
    // ADD CODE HERE
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    size_t size();
    string at(size_t pos);
    void insert(size_t pos, string value);
    void push_back(string value);
    void remove(size_t pos);

};


// ADD LINKEDLIST IMPLEMENTATION

// Função construtora
LinkedList::LinkedList(){
    head = new Node;
    head->next = nullptr;
}

// Função destrutora
LinkedList::~LinkedList(){
    Node* cur = head;
    Node* next;

    while (cur != nullptr) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}

// Retorna o tamanho atual da linked list
size_t LinkedList::size() {
    Node* cur = head;
    size_t size = 0;

    while (cur->next != nullptr) {
        cur = cur->next;
        size++;
    }

    return size;
}

// Retorna o elemento na posição pos da linked list
string LinkedList::at(size_t pos){
    assert(pos < size());

    Node* cur = head;
    int i = 0;

    while (i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    return cur->next->value;
}

// Insere um elemento de valor val na posição pos da linked list
void LinkedList::insert(size_t pos, string value){
    assert(pos <= size());

    Node* cur = head;
    int i = 0;

    while (i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    Node* newnode = new Node;
    newnode->value = value;

    newnode->next = cur->next;
    cur->next = newnode;
}

// Insere um elemento de valor val na última posição da linked list
void LinkedList::push_back(string value){
    return insert(size(), value);
}

// Remove o elemento da posição pos da linked list
void LinkedList::remove(size_t pos){
    assert(pos < size());

    Node* cur = head;
    int i = 0;

    while (i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    Node* toDie = cur->next;
    cur->next = toDie->next;
    delete toDie;
}


class Stack {
    // ADD CODE HERE
private:
    Node* tp;
    size_t sz;

public:
    Stack();
    ~Stack();
    size_t size();
    void push(string value);
    void pop();
    string top();
};

// ADD STACK IMPLEMENTATION

Stack::Stack() {
    tp = nullptr;
    sz = 0;
}

Stack::~Stack() {
    while (sz > 0) {
        pop();
    }
}

// Retorna o tamanho da stack (já deixei pronto a variável no private pra ser somente incrementada a medida que for adicionando itens na stack)
size_t Stack::size(){
    return sz;
}

// Adiciona um elemento no topo da stack
void Stack::push(string value){
    Node* newNode = new Node;
    newNode->next = tp;
    newNode->value = value;
    tp = newNode;

    sz++;
}

// Tira o elemento do topo da stack mas sem retorná-lo
void Stack::pop(){
    assert(sz > 0);

    Node* poppedNode = tp;
    tp = poppedNode->next;
    delete poppedNode;

    sz--;
}

string Stack::top(){
    assert(sz > 0);

    return tp->value;
}


class Queue {
    // ADD CODE HERE
private:
    Node* frnt;
    Node* back;
    size_t sz;
public:
    Queue();
    ~Queue();
    size_t size();
    void push(string value);
    void pop();
    string front();
};

// ADD QUEUE IMPLEMENTATION

Queue::Queue(){
    frnt = nullptr;
    back = nullptr;
    sz = 0;
}

Queue::~Queue(){
    while (sz > 0) {
        pop();
    }
}

// Retorna o tamanho da fila
size_t Queue::size() {
    return sz;
}

// Adiciona um elemento no final da fila
void Queue::push(string value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (sz == 0) {
        frnt = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }

    sz++;
}

// Remove um elemento do início da fila
void Queue::pop(){
    assert(sz > 0);

    Node* poppedNode = frnt;
    frnt = frnt->next;
    delete poppedNode;

    sz--;

    if (sz == 0) {
        back = nullptr;
    }
}

// Retorna o valor do elemento no início da fila
string Queue::front(){
    assert(sz > 0);

    return frnt->value;
}
