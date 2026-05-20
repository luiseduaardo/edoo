#include <iostream>
#include "hashtable.hpp"

using namespace std;

int main()
{
	// ADICIONE CODIGO AQUI
	int Mmin, Fmin, Fmax;
	int Dmax0 = -1, Dmax1 = -1;
	int J0, J1, D0, D1;
	
	cin >> Mmin >> Fmin >> Fmax;

	LPHashTable lp(Mmin, Fmin, Fmax);
	RHHashTable rh(Mmin, Fmin, Fmax);

	string operacao, placa;

	while (1) {
		cin >> operacao;
		if (operacao == "END") break;
		cin >> placa;

		uint key = HashTable::HashKey(placa);

		cout << key << " ";

		if (operacao == "IN") {
			auto [J0, D0] = lp.add(placa);
			auto [J1, D1] = rh.add(placa);

			cout << J0 << " " << D0 << " " << J1 << " " << D1 << endl;

		} else if (operacao == "OUT") {
			auto [J0, D0] = lp.del(placa);
			auto [J1, D1] = rh.del(placa);

			cout << J0 << " " << D0 << " " << J1 << " " << D1 << endl;

		} else if (operacao == "SCH") {
			auto [J0, D0] = lp.get(placa);
			auto [J1, D1] = rh.get(placa);

			if (J0 == -1) cout << "-1 -1 ";
			else cout << J0 << " " << D0 << " ";

			if (J1 == -1) cout << "-1 -1" << endl;
			else cout << J1 << " " << D1 << endl;

			if (J1 != -1 && J0 != -1) {
				if (D0 > Dmax0) Dmax0 = D0;
				if (D1 > Dmax1) Dmax1 = D1;
			}

		}
	}

	cout << Dmax0 << " " << Dmax1;

	return 0;
}
