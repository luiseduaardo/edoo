#include <iostream>
using namespace std;

int main() {

    int doorCode = 327;
    int userInput;

    password:

    cout << "Write the code to open the door: ";
    cin >> userInput;

    if (userInput == doorCode) {
        cout << "Correct code!\n" << "The door is now open\n";
    } else {
        cout << "Wrong code!\n" << "The door remains closed\n";
        goto password;
    }

    return 0;
}