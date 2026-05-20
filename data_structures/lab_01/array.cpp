#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    int elementos;

    cin >> elementos;

    int arr[elementos];
    int arr_rev[elementos];

    int n = 0;

    int selected = -1;

    for (int i = 0; i < elementos; i++) {
        do {
            selected = rand() % 1000;
        } while (selected < n);

        arr[i] = selected;
        cout << arr[i] << ' ';
        n = selected;
    }

    cout << "\n\n";

    for (int j = 0; j < elementos; j++) {
        arr_rev[j] = arr[elementos - j - 1];
        cout << arr_rev[j] << ' ';
    }

    cout << "\n\n";

    return 0;
}

