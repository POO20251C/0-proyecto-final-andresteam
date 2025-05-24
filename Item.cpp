#include <iostream>
#include "Item.h"
#include "Heroe.h"

Item::Item(std::string nombre, std::string tipo, int modATK, int modDEF, int modSPD, int modLCK, int curacion)
    : nombre(nombre), tipo(tipo), modATK(modATK), modDEF(modDEF), modSPD(modSPD), modLCK(modLCK), curacion(curacion) {
    validarAtributos();
}

void Item::validarAtributos() const {
    int contador = 0;
    if (modATK != 0) contador++;
    if (modDEF != 0) contador++;
    if (modSPD != 0) contador++;
    if (modLCK != 0) contador++;
    if (curacion != 0) contador++;
    if (contador > 2) {
        throw std::invalid_argument("Error: Un item no puede afectar mas de 2 atributos.");
    }
}

void Item::aplicarEfecto(Heroe& heroe) const {
    if (tipo == "pocion") {
        heroe.aumentarHP(curacion);
    } else {
        if (modATK != 0) heroe.aumentarATK(modATK);
        if (modDEF != 0) heroe.aumentarDEF(modDEF);
        if (modSPD != 0) heroe.aumentarSPD(modSPD);
        if (modLCK != 0) heroe.aumentarLCK(modLCK);
    }
}

void Item::mostrar() const {
    std::cout << "Item: " << nombre << " | Tipo: " << tipo;
    if (modATK != 0) std::cout << " | +ATK: " << modATK;
    if (modDEF != 0) std::cout << " | +DEF: " << modDEF;
    if (modSPD != 0) std::cout << " | +SPD: " << modSPD;
    if (modLCK != 0) std::cout << " | +LCK: " << modLCK;
    if (curacion != 0) std::cout << " | Cura: +" << curacion << " HP";
    std::cout << std::endl;
}
