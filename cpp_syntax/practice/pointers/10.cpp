#include <iostream>

using namespace std;

int main() {

    int arr[5];

    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    cin >> arr[3];
    cin >> arr[4];

    cout << "\nArray original: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }

    int* ptr;
    for (int i = 0; i < 5; i++) {
        ptr = &arr[i];
        *ptr *= 2;
    }

    cout << "\n\nArray duplicada: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}