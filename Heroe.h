#ifndef HEROE_H
#define HEROE_H

#include <vector>
#include "Personaje.h"
#include "Item.h"
#include "Enemigo.h"

class Heroe : public Personaje {
private:
    std::vector<Item> inventario;
    int hpMaximo;

public:
    Heroe(std::string nombre, int hp, int atk, int def, int spd, int lck);

    // Getters
    int getHPMaximo() const { return hpMaximo; }
    const std::vector<Item>& getInventario() const { return inventario; }

    // Setters para stats
    void aumentarHP(int cantidad);
    void aumentarATK(int cantidad);
    void aumentarDEF(int cantidad);
    void aumentarSPD(int cantidad);
    void aumentarLCK(int cantidad);

    // Nuevo metodo añadido
    void aumentarEstadisticasPorcentual(float porcentajeHP, float porcentajeStats);

    // Gestión de ítems
    void agregarItem(const Item& item);
    void equiparItem(const Item& item);
    void usarPocion();
    void mostrarInventario() const;

    // Combate
    void atacar(Personaje& enemigo) const override;
};

#endif // HEROE_H