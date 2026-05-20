#include <iostream>
using namespace std;

int main() {

    int number;

    cout << "Type a random number: ";
    cin >> number;

    if (number > 0){
        cout << "\nThe number " << number << " is positive\n";
    } else if (number < 0) {
        cout << "\nThe number " << number << " is negative\n";
    } else {
        cout << "\nThe number is zero\n";
    }

    return 0;
}