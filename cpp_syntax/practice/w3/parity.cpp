#include <iostream>
using namespace std;

int main() {

    int number;

    cout << "Type a random number: ";
    cin >> number;

    if (number % 2 == 0) {
        cout << "\nThe number " << number << " is even!\n";
    } else {
        cout << "\nThe number " << number << " is odd!\n";
    }

    return 0;
}