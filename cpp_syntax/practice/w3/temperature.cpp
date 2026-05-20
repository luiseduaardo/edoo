#include <iostream>

using namespace std;

float convertTemperature(float tmp, int escala, int destino);

int main() {

    float tmpOrigem;
    int escalaOrigem, escalaFinal;
    string escalaOrigem_str, escalaFinal_str;

    cout << "Digite a sua temperatura atual: ";
    cin >> tmpOrigem;

    cout << "Em qual escala você está medindo sua temperatura?\n";
    cout << "[ 1 ] CELSIUS   [ 2 ] FAHRENHEIT   [ 3 ] KELVIN\n";
    cin >> escalaOrigem;

    destino:
    cout << "Para qual temperatura você deseja mudar?\n";
    cout << "[ 1 ] CELSIUS   [ 2 ] FAHRENHEIT   [ 3 ] KELVIN\n";
    cin >> escalaFinal;

    if (escalaFinal == escalaOrigem) goto destino;

    if (escalaOrigem == 1) escalaOrigem_str = "Celsius";
    else if (escalaOrigem == 2) escalaOrigem_str = "Fahrenheit";
    else if (escalaOrigem == 3) escalaOrigem_str = "Kelvin";

    if (escalaFinal == 1) escalaFinal_str = "Celsius";
    else if (escalaFinal == 2) escalaFinal_str = "Fahrenheit";
    else if (escalaFinal == 3) escalaFinal_str = "Kelvin";

    float tmpFinal = convertTemperature(tmpOrigem, escalaOrigem, escalaFinal);

    cout << "\nO valor de " << tmpOrigem << " graus na escala " << escalaOrigem_str << " equivale a " << tmpFinal << " graus na escala " << escalaFinal_str;

    return 0;
}

float convertTemperature(float tmp, int escala, int destino) {
    int code = 10 * escala + destino;
    float tmpNew;

    if (code == 12) { // celsius para fahrenheit
        tmpNew = tmp * 9 / 5 + 32;
    } else if (code == 13) { // celsius para kelvin
        tmpNew = tmp + 273;
    } else if (code == 21) { // fahrenheit para celsius
        tmpNew = (tmp - 32) * 5/9;
    } else if (code == 23) { // fahrenheit para kelvin
        tmpNew = (tmp - 32) * 5/9 + 273;
    } else if (code == 31) { // kelvin para celsius
        tmpNew = tmp - 273;
    } else if (code == 32) { // kelvin para fahrenheit
        tmpNew = (tmp - 273) * 9/5 + 32;
    }

    return tmpNew;
}