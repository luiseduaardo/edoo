#include <iostream>
#include <stdio.h>  // para o printf e scanf

using namespace std;

int main() {

    int num1, num2, num3;
    char nome[10];

    scanf("%d %s", &num1, &nome); // scanf aponta para o endereço da variável e armazena

    printf("Valor da variável num1: %d\nNome: %s", num1, nome);   // %d = decimal

    return 0;
}