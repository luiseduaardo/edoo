#include <iostream>

using namespace std;

int main() {

    enum armas {
        FUZIL = 100,
        REVOLVER = 8,
        RIFLE = 12,
        ESCOPETA = 1
    };

    armas armaSel;

    armaSel = RIFLE;

    cout << armaSel;

    return 0;
}