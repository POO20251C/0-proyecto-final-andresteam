#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

class Personaje {
protected:
    std::string nombre;
    int hp, atk, def, spd, lck;

public:
    Personaje(std::string nombre, int hp, int atk, int def, int spd, int lck);

    virtual void recibirDano(int cantidad);
    virtual bool estaVivo() const;
    virtual void mostrarStats() const;

    int getSPD() const { return spd; }
    int getHP() const { return hp; }
    int getLCK() const { return lck; }
    std::string getNombre() const { return nombre; }

    virtual ~Personaje() {}
};

#endif //PERSONAJE_H
