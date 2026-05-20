#include <iostream>

using namespace std;

void soma();
void soma(int n1, int n2);

int main() {

    soma();
    soma(20, 30);

    return 0;
}

void soma() {
    int n1 = 10, n2 = 20, res;
    res = n1 + n2;

    cout << "Soma de " << n1 << " com " << n2 << " = " << res << "\n\n";
}

void soma(int n1, int n2) {
    int res = n1 + n2;

    cout << "Soma de " << n1 << " com " << n2 << " = " << res << "\n\n";
}