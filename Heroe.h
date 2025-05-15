#ifndef HEROE_H
#define HEROE_H

#include <vector>
#include <string>
#include "Personaje.h"
#include "Item.h"


class Heroe : public Personaje {
private:
    std::vector<Item> inventario;

public:
    Heroe(std::string nombre, int hp, int atk, int def, int spd, int lck);
    void agregarItem(const Item& item);
    void usarPocion();
    void mostrarInventario() const;
};

#endif //HEROE_H
