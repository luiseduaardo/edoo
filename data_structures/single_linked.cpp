// Implementação de uma Single Linked List e funções possíveis

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};


void listPrint(Node* head) {
    Node* cur = head;
    int i = 0;

    while (cur->next != nullptr) {
        cout << "list[" << i++ << "]: " << cur->val << endl;
        cur = cur->next;
    }
}

int listSize(Node* head) {
    Node* cur = head;
    int size = 0;

    while (cur->next != nullptr) {
        cur = cur->next;
        size++;
    }

    return size;
}

int listAt(Node* head, int pos) {
    if (pos > listSize(head)) return;

    Node* cur = head;
    int i = 0;

    while (i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    return cur->next->val;
}

int listFind(Node* head, int value) {
    Node* cur = head;
    int i = 0;

    while (cur->next->val != value && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    return i;
}

void listInsert(Node* head, int pos, int value) {
    if (pos > listSize(head)) return;

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

int listPop(Node* head, int pos) {
    if (pos > listSize(head)) return 1;

    Node* cur = head;
    int i = 0;

    while (i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }

    Node* toDie = cur->next;
    cur->next = toDie->next;
    int deletedValue = toDie->val;
    delete toDie;

    return deletedValue;

}

Node* listNew() {
    Node* head = new Node;
    head->next = nullptr;
    return head;
}

int main(int argc, char** argv) {
    Node* head = listNew();
    int size = stoi(argv[1]);

    for (int v = 0; v < 50; v+=10) {
        listInsert(head, size, v);
        size++;
    }

    listInsert(head, 3, 25);

    listPop(head, 2);

    listPrint(head);

    return 0;
}