#include <iostream>

using namespace std;

class LinkedList {

struct Node {
    int val;
    Node* next;
};

private:
    Node* head;
    size_t sz;

public:
    LinkedList(); // construtor da classe

    size_t size() {
        return sz;
    }

    void print();

    int at(size_t pos);

    size_t find(int value);

    void insert(size_t pos, int value);

    void remove(size_t pos);
};



LinkedList::LinkedList() {
    head = new Node;
    head->val = -1;
    head->next = nullptr;
    sz = 0;
}

void LinkedList::print() { // função construtora
    Node* cur = head;
    int i = 0;

    while (cur->next != nullptr) {
        cout << "list[" << i++ << "]: " << cur->val << endl;
        cur = cur->next;
    }
}

int LinkedList::at(size_t pos) {
    if (pos > sz) return;

    Node* cur = head;
    int i = 0;

    while (i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    return cur->next->val;
}

size_t LinkedList::find(int value) {
    Node* cur = head;
    int i = 0;

    while (cur->next->val != value && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    return i;
}

void LinkedList::insert(size_t pos, int value) {
    if (pos > sz) return;

    Node* cur = head;
    int i = 0;

    while (i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    Node* newnode = new Node;
    newnode->val = value;

    newnode->next = cur->next;
    cur->next = newnode;
}

void LinkedList::remove(size_t pos) {
    if (pos > sz) return;

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


int main() {

    LinkedList list;

    size_t size = 0;
    for (int val = 10; val < 100; val+=10) {
		list.insert(size, val);
		size++;
    }

    list.insert(3, 25);

    list.remove(4);

    list.print();

    return 0;
}
