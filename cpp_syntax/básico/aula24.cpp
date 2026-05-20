#include <iostream>

using namespace std;

void imp(string txt = "luis"); // coloca o argumento padrão somente no protótipo.

int main() {

    imp();
    imp("hello, world");

    return 0;
}

void imp(string txt) {
    cout << "\n" << txt << "\n\n";
}