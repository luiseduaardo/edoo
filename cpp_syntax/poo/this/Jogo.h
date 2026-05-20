#include <string>
using std::string;

// -----------------------------------------------
// Declaração da Classe Jogo
// -----------------------------------------------

class Jogo
{
private:
	string nome;									// nome do jogo
	float preco;									// preço do jogo
	int horas;										// quantidade de horas jogadas
	float custo;									// valor por hora jogada
	
	void calcular();								// calcular custo da hora jogada
	
public:
	Jogo();											// construtor padrão
	Jogo(const string& titulo,						// construtor da classe
		 float valor = 0, 
		 int tempo = 0);	
	~Jogo();										// destrutor

	const Jogo& comparar(const Jogo& jogo) const;	// compara dois jogos
	void atualizar(float valor);					// atualizar preço do jogo
	void jogar(int tempo);							// registrar horas jogadas
	void exibir() const;							// mostrar informações
    int TempoJogado();
    float Custo();
    float Preco();
};

// -----------------------------------------------
// Métodos Inline
// -----------------------------------------------

inline void Jogo::calcular()
{
	if (horas > 0)
		custo = preco / horas;
}

inline int Jogo::TempoJogado() {
    return horas;
}

inline float Jogo::Custo() {
    return custo;
}

inline float Jogo::Preco() {
    return preco;
}


// -----------------------------------------------