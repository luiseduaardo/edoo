#include <cstddef>
#include <cassert>
#include <string>

using namespace std;

class LinkedList {
    // ADD CODE HERE
private:
    struct Node {
    string value;
    Node* next = nullptr;
    };

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
    LinkedList list;

public:
    size_t size();
    void push(string value);
    void pop();
    string top();
};

// ADD STACK IMPLEMENTATION

// Retorna o tamanho da stack (já deixei pronto a variável no private pra ser somente incrementada a medida que for adicionando itens na stack)
size_t Stack::size(){
    return list.size();
}

// Adiciona um elemento no topo da stack
void Stack::push(string value){
    return list.push_back(value);
}

// Tira o elemento do topo da stack mas sem retorná-lo
void Stack::pop(){
    list.remove(list.size() - 1);
}

// Retorna o elemento no topo da stack
string Stack::top(){
    return list.at(list.size() - 1);
}


class Queue {
    // ADD CODE HERE
private:
    LinkedList list;
public:
    size_t size();
    void push(string value);
    void pop();
    string front();
};

// ADD QUEUE IMPLEMENTATION

// Retorna o tamanho da fila
size_t Queue::size() {
    return list.size();
}

// Adiciona um elemento no final da fila
void Queue::push(string value){
    list.push_back(value);
}

// Remove um elemento do início da fila
void Queue::pop(){
    list.remove(0);
}

// Retorna o valor do elemento no início da fila
string Queue::front(){
    return list.at(0);
}


/* ---------------------------------------------------- */
/* CLASSE EXTRA PARA IMPLEMENTAR ARRAY DINÂMICA */
/* não pode usar #include <vector> */

class Vector {
private:
    int* arr;
    size_t sz;
    size_t cap;

    void checkAndDouble();

public:
    Vector();
    ~Vector();

    size_t size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    int& operator[](size_t pos) {
        return arr[pos];
    }

    void append(int val);

    void clear() {
        sz = 0;
    }
};

Vector::Vector() {
    cap = 1;
    sz = 0;
    arr = new int[cap];
}

Vector::~Vector() {
    delete[] arr;
}

void Vector::checkAndDouble() {
    if (sz < cap) return;

    size_t newCap = 2 * cap;

    int *newArr = new int[newCap];

    for (int i = 0; i < sz; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    cap = newCap;
}

void Vector::append(int val) {
    checkAndDouble();
    assert(sz < cap);
    arr[sz++] = val;
}
