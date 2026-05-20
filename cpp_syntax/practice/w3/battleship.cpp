#include <iostream>
using namespace std;

int main() {

    bool ships[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };

    int hits = 0;
    int turns = 0;

    while (hits < 4) {
        int row, column;

        cout << "Selecting coordinates\n";

        cout << "Choose a row between 1 and 4: ";
        cin >> row;

        cout << "Choose a row between 1 and 4: ";
        cin >> column;

        row -= 1;
        column -= 1;

        if (ships[row][column]) {
            hits++;
            ships[row][column] = 0;
            cout << "Hit! " << (4 - hits) << " left to complete!\n\n"; 
        } else {
            cout << "Miss!\n\n";
        }

        turns++;
    }

    cout << "Victory\n";
    cout << "You won in " << turns << " turns!\n\n";

    return 0;
}