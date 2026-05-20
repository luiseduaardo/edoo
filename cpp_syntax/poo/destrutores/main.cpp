#include "Jogo.h"
#include <iostream>
using namespace std;

int main()
{   
    // destruição é feita de maneira inversa à criação
        // variáveis locais são armazenadas na pilha e por esse motivo isso acontece
	{
        Jogo sackboy { "Sackboy", 150 };
        Jogo spiderman { "Spiderman", 200 };
        Jogo horizon { "Horizon", 199 };
    }

    cout << "\n ---------------------------------- \n";

    // destruição não ocorre de maneira automática porque é feito uma alocação dinâmica
    
    Jogo* fifa = new Jogo { "fifa", 300 };
    Jogo* overwatch = new Jogo { "overwatch", 0 };
    Jogo* mario = new Jogo { "mario", 50 };
}