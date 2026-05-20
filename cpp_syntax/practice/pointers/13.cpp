#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

bool checkString(char* str1, char* str2);

int main() {

    // aloca dinamicamente a memória para a string
    char* string1 = (char *) malloc(sizeof(char));
    gets(string1);

    char* string2 = (char *) malloc(sizeof(char));
    gets(string2);

    if (checkString(string1, string2)){
        cout << "\nA Segunda String ocorre na Primeira\n";
    } else {
        cout << "\nA Segunda String não ocorre na Primeira\n";
    }

    return 0;
}

bool checkString(char* str1, char* str2) {

    while (*str1 != '\0') {
        char *temp1 = str1;
        char *temp2 = str2;

        // entra no loop se a letra da string 1 for igual a string 2 e se o caracter da string 2 não for null
        while (*temp1 == *temp2 && *temp2 != '\0') {
            temp1++;
            temp2++;
        }
        // se o ponteiro da segunda string chegar no null character, quer dizer que a sequência da string 2 foi totalmente mapeada dentro da string 1, logo retorna verdadeiro
        if (*temp2 == '\0') {
            return true;
        }
        str1++;
    }

    // se chegar ao final da string 1 e não mapear a string 2, retorna falso
    return false;
}