#ifndef AULA45_H_INCLUDED
#define AULA45_H_INCLUDED

class Aviao {
    public:
        int vel = 0;
        int velMax;
        std::string tipo;
        
        Aviao(int tp) {
            if (tp == 1) {
                velMax = 800;
                tipo = "Jato";
            } else if (tp == 2) {
                velMax = 350;
                tipo = "Monomotor";
            } else if (tp == 3) {
                velMax = 180;
                tipo = "Planador";
            };
        }

        void imprimir() {
            std::cout << "Tipo .............: " << tipo << std::endl;
            std::cout << "Velocidade máxima: " << velMax << std::endl;
            std::cout << "Velocidade atual..: " << vel << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
        }
};

#endif