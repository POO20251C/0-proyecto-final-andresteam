#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <vector>
#include <memory>  // Para std::unique_ptr
#include "Sala.h"

class Mazmorra {
private:
    std::vector<Sala> salas;

public:
    Mazmorra();
    int iniciarRecorrido(std::vector<Heroe*>& heroes);
    int obtenerSalaActual() const;
};

#endif // MAZMORRA_H