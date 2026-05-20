// If the loop passes the values ranging from 1 to 5, it prints "No Yatzy". Whenever it passes the value 6, it prints "Yatzy!".

#include <iostream>
using namespace std;

int main() {

    int number = 0;

    while (number <= 6) {
        if (number < 6) {
            cout << "No Yatzy - " << number << "\n";
        } else {
            cout << "Yatzy!\n";
        }

        number++;
    }

    return 0;
}