#include <iostream>

using namespace std;

int main() {

    int a, *b, **c, ***d;
    b = &a;
    c = &b;
    d = &c;

    cin >> a;
    *b = *a *2;
    *c = *b *2;
    *d = *c *2;

    cout << 

    return 0;
}