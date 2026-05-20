#include <iostream>
using namespace std;

int main() {

    int num;

    /*
    1 2 3 4 5 6 7 8 9 10
    >4 e <7: {5, 6}
    */

    cin >> num;

    if (num > 4 && num < 7) {
        cout << "\nValor aceito\n";
    } else {
        cout << "\nNão aceito!\n";
    }

    /*
    1 2 3 4 5 6 7 8 9 10
    <3 ou >8: {1, 2, 9, 10}
    */

    cin >> num;

    if (num < 3 || num > 8) {
        cout << "\nValor aceito\n";
    } else {
        cout << "\nNão aceito!\n";
    }

    return 0;
}