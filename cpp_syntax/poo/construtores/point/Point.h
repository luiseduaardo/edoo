
// -----------------------------------------------
// Declaração da Classe Point
// -----------------------------------------------

class Point {
private:
	int x;											// posição no eixo x
	int y;											// posição no eixo y

public:
    Point();                                        // construtor padrão
    Point(int ax, int ay);                          // construtor com valor
	void MoveTo(int px, int py);		            // move ponto para posição (px,py)
	void Translate(int dx, int dy);					// desloca ponto por (dx,dy)
	int X();										// retorna coordenada x do ponto
	int Y();										// retorna coordenada y do ponto
    void print();
};

// -----------------------------------------------
// Métodos Inline
// -----------------------------------------------

inline int Point::X() { return x; }
inline int Point::Y() { return y; }

// -----------------------------------------------