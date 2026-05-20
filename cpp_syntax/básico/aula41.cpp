#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {

    int num = 15;

    cout << "Valor de num em dec: " << num << endl;
    cout << "Valor de num em hex: " << hex << num << endl;
    cout << "Valor de num em oct: " << oct << num << endl;
    cout << "Valor de num em bin: " << setbase(2) << num << endl;

    float pi = M_PI;

    cout.precision(3);
    cout << "\n\nValor de pi: " << pi << endl;

    cout.precision(-1);
    cout << "Valor de pi: " << std::scientific << pi << endl;

    int num2 = 2;
    cout << "Valor de num:" << setw(10) << setfill('.') << num << endl;

    return 0;
}