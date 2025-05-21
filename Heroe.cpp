#include <iostream>
#include "Heroe.h"
using namespace std;

Heroe::Heroe(string nombre, int hp, int atk, int def, int spd, int lck)
    : Personaje(nombre, hp, atk, def, spd, lck) {}

void Heroe::agregarItem(const Item& item) {
    inventario.push_back(item);
    cout << nombre << " ha obtenido el item: " << item.getNombre() << endl;
}

void Heroe::mostrarInventario() const {
    cout << "Inventario de " << nombre << ":\n";
    if (inventario.empty()) {
        cout << "  (Vacío)\n";
        return;
    }
    for (const auto& item : inventario) {
        item.mostrar();
    }
}

void Heroe::usarPocion() {
    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].getTipo() == "pocion") {
            hp += inventario[i].getCuracion();
            cout << nombre << " usó una poción. HP restaurado a " << hp << endl;
            inventario.erase(inventario.begin() + i);
            return;
        }
    }
    cout << nombre << " no tiene pociones disponibles.\n";
}