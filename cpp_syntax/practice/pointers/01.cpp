#include <iostream>

using namespace std;

int main() {

    int a = 1;
    float b = 2.50;
    char c = 'c';

    int* pta;
    float* ptb;
    char* ptc;

    pta = &a;
    ptb = &b;
    ptc = &c;

    cout << "\nAntes da mudança:";
    
    cout << "\nInteiro a: " << a; // ao invés de a, poderia colocar *pta
    cout << "\nFloat b: " << b;    // ao invés de b, poderia colocar *ptb
    cout << "\nChar c: " << c;     // ao invés de c, poderia colocar *ptc

    *pta = 3;
    *ptb = 7.50;
    *ptc = 'i';

    cout << "\n\nDepois da mudança:";
    
    cout << "\nInteiro a: " << a; // ao invés de a, poderia colocar *pta
    cout << "\nFloat b: " << b;    // ao invés de b, poderia colocar *ptb
    cout << "\nChar c: " << c;     // ao invés de c, poderia colocar *ptc

    cout << "\n";

    return 0;
}