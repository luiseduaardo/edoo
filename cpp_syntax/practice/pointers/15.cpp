#include <iostream>

using namespace std;

void printArray(char* arr);

int main() {

    char array[5] = {'a', 'b', 'c', 'd', 'e'};

    printArray(array);

    return 0;
}

void printArray(char* arr) {
    while (*arr != '\0') {
        cout << *arr << ' ';
        arr++;
    }
}