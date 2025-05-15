#include <iostream>
#include "Heroe.h"

using namespace std;

Heroe::Heroe(string nombre, int hp, int atk, int def, int spd, int lck)
    : Personaje(nombre, hp, atk, def, spd, lck) {}

void Heroe::agregarItem(const Item& item) {
    inventario.push_back(item);
    cout << nombre << " obtuvo el item: ";
    item.mostrar();
}

void Heroe::usarPocion() {
    for (const auto& item : inventario) {
        if (item.getTipo() == "pocion") {
            hp += item.getCuracion();
            cout << nombre << " usó una poción. Nueva HP: " << hp << endl;
            return;
        }
    }
    cout << nombre << " no tiene pociones." << endl;
}

void Heroe::mostrarInventario() const {
    cout << "Inventario de " << nombre << ":\n";
    for (const auto& item : inventario) {
        item.mostrar();
    }
}