#include <iostream>
#include <stdio.h>  // função gets
#include <stdlib.h> // função malloc

using namespace std;

int main() {

    //char vnome[50]; // se o nome tiver menos de 50 chars, o espaço restante está sendo desperdiçado

    char* vnome = (char *) malloc(sizeof(char)); 
    // aloca de maneira dinâmica a memória para o vnome, sem desperdiçar espaços de memória
    // como a função malloc tem return value de void, temos que "converter" anteriormente usando (tipo *)

    gets(vnome);

    cout << vnome;

    return 0;
}