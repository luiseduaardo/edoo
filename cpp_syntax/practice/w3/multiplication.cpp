// create a program that prints the multiplication table for a specified number

#include <iostream>
using namespace std;

int main() {
    
    int n;

    cout << "Type a random number: ";
    cin >> n;

    for (int i = 0; i <= 10; i++) {
        cout << n << " x " << i << " = " << i * n << "\n";
    }

    return 0;
}