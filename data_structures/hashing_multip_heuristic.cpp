#include <iostream>
#include <cmath>

using namespace std;


#define A 89
// w = word size
// k = key
// A = multiplication constant
// r = size of the final result

int dec_to_bin(int value) {
    long long binary = 0;
    int remainder, i=1;

    while (value != 0) {
        remainder = value % 2;
        value /= 2;
        binary += remainder * i;
        i *= 10;
    }

    return binary;
}

// h(k) = ((A.k) mod 2^w) rsh(w-r)
int hash_function(int number, int r) {
    int product = number * A;
    int w = (int)log2(number) + 1;

    int module = product % (int)pow(2, w);

    return module >> (w - r);
}

int main() {

    int original, final;
    cin >> original;
    final = hash_function(original, 3);

    cout    << "unencrypted:        " << original << endl
            << "unencrypted binary: " << dec_to_bin(original) << endl
            << "encrypted:          " << final << endl
            << "encrypted binary:   " << dec_to_bin(final) << endl;

    return 0;
}