#include <iostream>
using namespace std;

int main() {

    int valor;

    cout << "Selecione um transporte:\n";
    cout << "[ 1 ] CARRO; [ 2 ] MOTO; [ 3 ] AVIÃO; [ 4 ] HELICÓPTERO;\n";
    cin >> valor;

    switch(valor) {
        case 1:
        case 2:
            cout << "\nTransporte terrestre selecionado\n";
            switch(valor) {
                case 1:
                    cout << "Carro selecionado\n";
                    break;
                case 2:
                    cout << "Moto selecionada\n";
                    break;
            }
            break;

        case 3:
        case 4:
            cout << "\nTransporte aéreo selecionado\n";
            switch(valor) {
                case 3:
                    cout << "Avião selecionado\n";
                    break;
                case 4:
                    cout << "Helicóptero selecionado\n";
                    break;
            }
            break;
        
        default:
            cout << "\nTransporte inválido selecionado\n";
    }

    return 0;
}