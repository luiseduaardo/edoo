#include <iostream>
#include <cassert>
#include <string>

// arr = array de strings 
// size = no de elementos de arr
// pos = posicao do corte
void cut (string **arr, size_t size, size_t pos) 
{
	// ADD CODE HERE

	if (pos == 0 || pos == size) return; 

	string **temp = new string*[pos];

	// popula a array temporária com os elementos à esquerda da posição de corte
	for (size_t i = 0; i < pos; i++) {
		temp[i] = arr[i];
	}

	// faz o desvio para a esquerda dos elementos que ficaram na array original
	for (size_t j = 0; j < size - pos; j++) {
		arr[j] = arr[j + pos];
	}

	// coloca os elementos da array temporária no final da array original
	size_t copy = size - pos;
	for (size_t k = 0; k < pos; k++) {
		arr[copy + k] = temp[k];
	}

	delete[] temp;
}

// arr = array de strings 
// size = no de elementos de arr
// pos = posicao do corte
void shf (string **arr, size_t size, size_t pos) 
{
	// ADD CODE HERE
	
	if (pos == 0 || pos == size) return; 

	size_t sizeL = pos;
	size_t sizeR = size - pos;

	string **tempL = new string*[sizeL];
	string **tempR = new string*[sizeR];

	// popula a array temporária com os elementos à ESQUERDA (left) da posição de corte
	for (size_t i = 0; i < sizeL; i++) {
		tempL[i] = arr[i];
	}

	// popula a array temporária com os elementos à DIREITA (right) da posição de corte
	for (size_t j = 0; j < sizeR; j++) {
		tempR[j] = arr[j + sizeL];
	}
	
	size_t contadorL = 0;
    size_t contadorR = 0;
    size_t k = 0;

	// usa a lógica de paridade do index para identificar qual elemento irá voltar para a array original
		// se o index for par e ainda tiver elementos da subarray da esquerda para colocar, adiciona, senão, adiciona um da subarray da direita
		// se o index for ímpar e ainda tiver elementos da subarray da direita para colocar, adiciona, senão, adiciona um da subarray da esquerda
	for (size_t k = 0; k < size; k++) {
		if (k % 2 == 0) {
			if (contadorL < sizeL) {
				arr[k] = tempL[contadorL++];
			} else {
				arr[k] = tempR[contadorR++];
			}
		} else {
			if (contadorR < sizeR) {
				arr[k] = tempR[contadorR++];
			} else {
				arr[k] = tempL[contadorL++];
			}
		}
	}

	delete[] tempL;
	delete[] tempR;
}

// arr = array de strings 
// size = no de elementos de arr
// pos = posicao do corte
void shb (string **arr, size_t size, size_t pos) 
{
	// ADD CODE HERE

	if (pos == 0 || pos == size) return; 

	size_t sizeL = pos;
	size_t sizeR = size - pos;

	string **tempL = new string*[sizeL];
	string **tempR = new string*[sizeR];

	// popula a array temporária com os elementos à ESQUERDA (left) da posição de corte
	for (size_t i = 0; i < sizeL; i++) {
		tempL[i] = arr[i];
	}

	// popula a array temporária com os elementos à DIREITA (right) da posição de corte
	for (size_t j = 0; j < sizeR; j++) {
		tempR[j] = arr[sizeL + j];
	}

	size_t contadorL = 0;
    size_t contadorR = 0;

	// vai colocando os elementos alternados do fim pro começo da array até que uma das subarrays acabe (seja a da esquerda ou a da direita)
	while (contadorL < sizeL && contadorR < sizeR) {
		arr[size - (contadorL + contadorR) - 1] = tempR[sizeR - contadorR - 1];
		contadorR++;
		arr[size - (contadorL + contadorR) - 1] = tempL[sizeL - contadorL - 1];
		contadorL++;
	}

	// aqui, a array que ainda tiver elementos para adicionar irá continuar adicionando (ainda do fim pro começo)
	while (contadorL < sizeL) {
		arr[size - (contadorL + contadorR) - 1] = tempL[sizeL - contadorL - 1];
		contadorL++;
	}

	while (contadorR < sizeR) {
		arr[size - (contadorL + contadorR) - 1] = tempR[sizeR - contadorR - 1];
		contadorR++;
	}

	delete[] tempL;
	delete[] tempR;
}
