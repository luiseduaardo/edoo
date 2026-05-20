#include <iostream>
using namespace std;

int main() {

    int numbers = 12345;
    int reversedNumbers = 0;

    while (numbers) {
        reversedNumbers = reversedNumbers * 10 + numbers % 10;
        numbers /= 10;
    }

    cout << "Reversed numbers: " << reversedNumbers << "\n";

    return 0;
}