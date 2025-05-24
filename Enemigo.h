#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"
#include <string>

class Enemigo : public Personaje {
private:
    std::string tipo;
public:
    Enemigo(std::string nombre, std::string tipo, int hp, int atk, int def, int spd, int lck);
    std::string getTipo() const;
    void mostrarStats() const override;
    void atacar(Personaje& objetivo) const override;
};

#endif // ENEMIGO_H