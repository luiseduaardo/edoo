#include <iostream>

using namespace std;

class Aviao {
    public:
        int vel = 0;
        int velMax;
        string tipo;

        void ini(int tp) {
            if (tp == 1) {
                this->velMax = 800;
                this->tipo = "Jato";
            } else if (tp = 2) {
                this->velMax = 350;
                this->tipo = "Monomotor";
            } else if (tp = 3) {
                this->velMax = 180;
                this->tipo = "Planador";
            }
        };

    private:
};

int main() {

    Aviao *av1 = new Aviao();
    av1->ini(1);

    Aviao *av2 = new Aviao();
    av2->ini(2);

    cout << av1->vel << endl << av1->velMax << endl << av1->tipo << "\n\n";
    cout << av2->vel << endl << av2->velMax << endl << av2->tipo;

    return 0;
}