#include <iostream>

using namespace std;

int ordenar(int* a, int* b, int* c);

int main() {

    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    cout << "a: " << a << "\nb: " << b << "\nc: " << c;

    ordenar(&a, &b, &c);

    cout << "\n\na: " << a << "\nb: " << b << "\nc: " << c;

    return 0;
}

int ordenar(int* a, int* b, int* c) {
    int tmp;
    bool sorted;
    if (*a == *b && *a == *c && *b == *c) {
        return 1;
    } else {
        while (sorted) {
            sorted = true;
            if (*c < *b) {
                tmp = *c;
                *c = *b;
                *b = tmp;
                sorted = false;
            } if (*b < *a) {
                tmp = *a;
                *a = *b;
                *b = tmp;
                sorted = false;
            }
        }
        return 0;
    }
}