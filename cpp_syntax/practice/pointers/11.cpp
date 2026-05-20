#include <iostream>

using namespace std;

int main() {

    int arr[5];

    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    cin >> arr[3];
    cin >> arr[4];

    int* ptr;

    cout << "Valores pares: ";
    for (int i = 0; i < 5; i++) {
        ptr = &arr[i];
        if (*ptr % 2 == 0) {
            cout << *ptr << ' ';
        }
    }

    return 0;
}