#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>
#include "Personaje.h"

class Enemigo : public Personaje {
private:
    std::string tipo; // "Soldado", "MiniJefe", "GranJefe"

public:
    Enemigo(std::string nombre, std::string tipo, int hp, int atk, int def, int spd, int lck);
    std::string getTipo() const;
};

#endif //ENEMIGO_H
