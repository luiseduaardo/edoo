#include <iostream>
using namespace std;

int main()
{
    
    int votingAge = 18;
    int myAge;

    cout << "How old are you? ";
    cin >> myAge;

    if (myAge >= votingAge) {
        cout << "\nYou are allowed to vote!\n";
    } else {
        cout << "\nYou are not allowed to vote!\n";
    }

    return 0;
}
