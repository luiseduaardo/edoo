#ifndef AULA46_H_INCLUDED
#define AULA46_H_INCLUDED

class Veiculo {
public:
    int velMax;
    int tipo;

    Veiculo(int tp);
    
private:
    string nome;
    int vel;
    bool ligado;

};

Veiculo::Veiculo(int tp) {
    
}

#endif