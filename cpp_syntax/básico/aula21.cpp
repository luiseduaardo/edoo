#include <iostream>
#include <string.h>

using namespace std;

// argc = argument count (quantidade de argumentos)
// argv = argument vector (array of pointers to arrays of character objects)
    // ponteiro para uma matriz de ponteiros de caracteres
    // cada elemento aponta para um argumento

// no momento, apenas se ligas que argc diz o número de argumentos e argv quais são os argumentos

int main(int argc, char *argv[]) {

    if (argc > 1) {
        if (!strcmp(argv[1], "sol")) {
            cout << "Vou ao clube\n\n";
        } else if (!strcmp(argv[1], "nublado")) {
            cout << "Vou ao cinema\n\n";
        } else {
            cout << "Vou ficar em casa\n\n";
        }
    }

    return 0;
}