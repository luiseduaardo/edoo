#include <iostream>
using namespace std;

int main() {
    
    int number;

    cout << "Type a random number: ";
    cin >> number;

    string parity = (number % 2 == 0) ? "even" : "odd";

    cout << "\nThe number " << number << " is " << parity << endl;

    return 0;
}