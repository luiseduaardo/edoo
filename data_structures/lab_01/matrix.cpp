#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    int m, n, p;

    cin >> m;
    cin >> n;
    cin >> p;

    int A[m][n];
    int B[n][p];
    int C[m][p];

    cout << "\nMatriz A (" << m << "x" << p << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            cout << A[i][j] << ' ';
        }
        cout << "\n";
    }

    cout << "\nMatriz B (" << n << "x" << p << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            B[i][j] = rand() % 10;
            cout << B[i][j] << ' ';
        }
        cout << "\n";
    }

    cout << "\nMatriz C (" << m << "x" << p << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << ' ';
        }
        cout << "\n";
    }


    return 0;
}   