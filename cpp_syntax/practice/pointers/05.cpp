#include <iostream>

using namespace std;

void verificacao(int* p1, int* p2);

int main() {

    int v1, v2;

    cin >> v1;
    cin >> v2;

    int* ptv1;
    int* ptv2;

    ptv1 = &v1;
    ptv2 = &v2;

    cout << "\nAntes da verificação\nv1: " << v1 << "\nv2: " << v2;

    verificacao(ptv1, ptv2);

    cout << "\nDepois da verificação\nv1: " << v1 << "\nv2: " << v2;

    return 0;
}

void verificacao(int* p1, int* p2) {
    if (*p1 < *p2){
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}