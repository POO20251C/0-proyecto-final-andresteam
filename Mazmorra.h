#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <vector>
#include "Sala.h"
#include "Heroe.h"
#include "Enemigo.h"

class Mazmorra {
private:
    std::vector<Sala> salas;

public:
    Mazmorra();
    void iniciarRecorrido(std::vector<Heroe*>& heroes);
    int obtenerSalaActual() const;
};

#endif //MAZMORRA_H
