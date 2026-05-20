#include <cassert>
#include <utility>

using namespace std;

using uint = unsigned int;
using ipair = pair<int, int>;


// ---------------------------------------------------------------------------
//  Hash Table Base
// ---------------------------------------------------------------------------

class HashTable {
protected:
	// status da entrada da hashtable
    using Status = enum {
        FREE,	// entrada livre
        BUSY,   // entrada ocupada
        DEAD    // entrada apagada (tombstone)
    };

	// entradas da tabela	
	struct HashEntry {
		Status status; 
		uint   key;   	// chave (valor numerico)  da string
		string value; 	// placa
		uint   dist;  	// distancia para a posicao original na tabela
	};

public:
	// Converte a placa (string) numa chave numerica
	// Exemplo: 
	// k(ABCDEF) = A * 26^0 + B * 26^1 + C * 26^2 + D * 26^3 + E * 26^4 + F * 26^5
	//           = 0 * 26^0 + 1 * 26^1 + 2 * 26^2 + 3 * 26^3 + 4 * 26^4 + 5 * 26^5
	//        	 = 0 + 26 + 1352 + 52728 + 1827904 + 59406880 = 61288890
    static uint HashKey(string const &value)
    {
        uint pow = 1;
        uint res = 0;
        for (int i = 0; i < value.size(); i++) {
            res += (static_cast<uint>(value[i] - 'A') * pow);
            pow *= 26;
        }
        return res;
    }

protected:
	HashTable(uint initCap, uint aMin, uint aMax)
        : size(0), nUsed(0), minCap(initCap), cap(initCap), minLoad(aMin), maxLoad(aMax)
    {
		table = new HashEntry[cap];
		for (uint i = 0; i < cap; table[i++].status = FREE);
	}

	~HashTable() {
		delete[] table;
	}

	// verifica se a tabela precisa ser aumentada (dobrada)	ou 
	// diminuida (reduzida pela metade) e, caso necessario, 
	// realiza o rehasing
	virtual void checkAndDouble() = 0;
	virtual void checkAndHalf() = 0;
	
	HashEntry *table; 	// tabela com as entradas
	uint minCap;		// capacidade minima/inicial de vagas
	uint cap;        	// capacidade da tabela
	uint size;       	// numero logico de elementos da tabela (incluidos - excluidos)
	uint nUsed;       	// numero de posicoes usadas, incluindo as apagadas
	uint minLoad;   	// fator de carga minimo (em pontos percentuais)
	uint maxLoad;   	// fator de carga maximo (em pontos percentuais)
	
public:
	// Adiciona nova placa (string) 
	// Retorna um par (pos, dist) 
	virtual ipair add(string const &value) = 0;

	// Remove uma placa (string)
	// Retorna um par (pos, dist) 
	virtual ipair del(string const &value) = 0;

	// Consulta uma placa (string) 
	// Retorna um par (pos, dist) 
	virtual ipair get(string const &value) = 0;

};


// ---------------------------------------------------------------------------
// Linear Probing Hash Table
// ---------------------------------------------------------------------------

class LPHashTable: public HashTable { 
public:
	LPHashTable(uint initCap, uint minLoad, uint maxLoad):
		HashTable(initCap, minLoad, maxLoad)
	{
	}

	ipair add(string const &value) override;
	ipair del(string const &value) override;
	ipair get(string const &value) override;

protected:
	virtual void checkAndDouble() override; 
	virtual void checkAndHalf() override; 

};


// ADICIONE AS IMPLEMENTACOES AQUI

void LPHashTable::checkAndDouble() {
	if (nUsed * 100 > cap * maxLoad) {
		uint oldcap = cap;
		HashEntry* oldtable = table;

		cap *= 2;
		table = new HashEntry[cap];
		for (uint i = 0; i < cap; i++) table[i].status = FREE;

		size = 0;
		nUsed = 0;

		for (uint i = 0; i < oldcap; i++) {
			if (oldtable[i].status == BUSY) {
				this->add(oldtable[i].value);
			}
		}

		delete[] oldtable;
	}
}

void LPHashTable::checkAndHalf() {
	if (cap > minCap && size * 100 < cap * minLoad) {
		uint oldcap = cap;
		HashEntry* oldtable = table;

		cap /= 2;
		table = new HashEntry[cap];
		for (uint i = 0; i < cap; i++) table[i].status = FREE;

		size = 0;
		nUsed = 0;

		for (uint i = 0; i < oldcap; i++) {
			if (oldtable[i].status == BUSY) {
				this->add(oldtable[i].value);
			}
		}

		delete[] oldtable;
	}
}

ipair LPHashTable::add(string const &value) {
	checkAndDouble();

	uint k = HashKey(value);
	uint h = k % cap;
	uint dist = 0;

	while (table[h].status != FREE) {
		dist++;
		h = (h + 1) % cap;
	}

	table[h].dist = dist;
	table[h].key = k;
	table[h].value = value;
	table[h].status = BUSY;

	size++;
	nUsed++;

	return { h, dist };
}

ipair LPHashTable::del(string const &value) {
	uint k = HashKey(value);
	uint h = k % cap;
	uint dist = 0;

	while (table[h].status != FREE) {
		if (table[h].value == value && table[h].status == BUSY) {
			table[h].status = DEAD;
			size--;
			checkAndHalf();

			return { h, dist };
		}
		dist++;
		h = (h + 1) % cap;
	}

	return { -1, -1 };
}

ipair LPHashTable::get(string const &value) {
	uint k = HashKey(value);
	uint h = k % cap;
	uint dist = 0;

	while (table[h].status != FREE) {
		if (table[h].value == value && table[h].status == BUSY) {
			return { h, dist };
		}
		dist++;
		h = (h + 1) % cap;
	}

	return { -1, dist };
}

// ----------------------------------------------------------------
// Robin Hood Hash Table
// ----------------------------------------------------------------

class RHHashTable: public HashTable {
public:
	RHHashTable(uint initCap, uint minLoad, uint maxLoad):
		HashTable(initCap, minLoad, maxLoad)
	{
	}

	ipair add(string const &value) override;
	ipair del(string const &value) override;
	ipair get(string const &value) override;

protected:
	virtual void checkAndDouble() override; 
	virtual void checkAndHalf() override; 
};

// ADICIONE AS IMPLEMENTACOES AQUI

void RHHashTable::checkAndDouble() {
	if (nUsed * 100 > cap * maxLoad) {
		uint oldcap = cap;
		HashEntry* oldtable = table;

		cap *= 2;
		table = new HashEntry[cap];
		for (uint i = 0; i < cap; i++) table[i].status = FREE;

		size = 0;
		nUsed = 0;

		for (uint i = 0; i < oldcap; i++) {
			if (oldtable[i].status == BUSY) {
				this->add(oldtable[i].value);
			}
		}

		delete[] oldtable;
	}
}

void RHHashTable::checkAndHalf() {
	if (cap > minCap && size * 100 < cap * minLoad) {
		uint oldcap = cap;
		HashEntry* oldtable = table;

		cap /= 2;
		table = new HashEntry[cap];
		for (uint i = 0; i < cap; i++) table[i].status = FREE;

		size = 0;
		nUsed = 0;

		for (uint i = 0; i < oldcap; i++) {
			if (oldtable[i].status == BUSY) {
				this->add(oldtable[i].value);
			}
		}

		delete[] oldtable;
	}
}

ipair RHHashTable::add(string const &value) {
	checkAndDouble();
	
	string val = value;
	uint k = HashKey(value);
	uint h = k % cap;
	uint dist = 0;

	int finalPos = -1, finalDist = -1;

	while (table[h].status != FREE) {
		if (table[h].status == BUSY && dist > table[h].dist) {
			if (finalPos == -1) {
				finalPos = h;
				finalDist = dist;
			}

			swap(dist, table[h].dist);
			swap(k, table[h].key);
			swap(val, table[h].value);
		}
		
		dist++;
		h = (h + 1) % cap;
	}

	table[h].dist = dist;
	table[h].key = k;
	table[h].value = val;
	table[h].status = BUSY;

	size++;
	nUsed++;

	if (finalPos == -1) return { h, dist };
	else return { finalPos, finalDist };
}

ipair RHHashTable::del(string const &value) {
	uint k = HashKey(value);
	uint h = k % cap;
	uint dist = 0;

	while (table[h].status != FREE) {
		if (table[h].status == BUSY && table[h].dist < dist) {
			return { -1, -1 };
		}

		if (table[h].value == value && table[h].status == BUSY) {
			table[h].status = DEAD;
			size--;
			checkAndHalf();

			return { h, dist };
		}
		dist++;
		h = (h + 1) % cap;
	}

	return { -1, -1 };
}

ipair RHHashTable::get(string const &value) {
	uint k = HashKey(value);
	uint h = k % cap;
	uint dist = 0;

	while (table[h].status != FREE) {
		if (table[h].status == BUSY && table[h].dist < dist) {
			return { -1, dist };
		}
		
		if (table[h].value == value && table[h].key == k && table[h].status == BUSY) {
			return { h, dist };
		}

		dist++;
		h = (h + 1) % cap;
	}

	return { -1, dist };
}
