#include <fstream>
#include <iostream>
#include <string>
#include "strgen.hpp"
#include "shuffler.hpp"


int main() {
	// ADD CODE HERE

	// IMPORTANTE:
	// Incluir uma chamada a StringGen::reset() no inicio de cada caso

	size_t k;
	std::cin >> k;

	size_t n, p, idx;
	std::string op;

	for (size_t i = 0; i < k; i++) {
		std::cin >> n >> p;

		StringGen::reset();

		std::string **arr = new std::string*[n];
		for (size_t e = 0; e < n; e++) {
			arr[e] = new std::string(StringGen::randomString());
		}

		for (size_t j = 0; j < p; j++) {
			cin >> op >> idx;

			if (op == "CUT") {
				cut(arr, n, idx);
			} else if (op == "SHF") {
				shf(arr, n, idx);
			} else if (op == "SHB") {
				shb(arr, n, idx);
			} else if (op == "REA") {
				std::cout << *arr[idx] << std::endl;
			}
		}

		std::cout << *arr[0] << " " << *arr[n-1] << "\n";

		std::cout << "\n";

		for (size_t e = 0; e < n; e++) {
            delete arr[e]; 
        }
		delete[] arr;
	}
	
	return 0;
}
