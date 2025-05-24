#include "Enemigo.h"
#include "Heroe.h"
#include <iostream>

Enemigo::Enemigo(std::string nombre, std::string tipo, int hp, int atk, int def, int spd, int lck)
    : Personaje(nombre, hp, atk, def, spd, lck), tipo(tipo) {}

std::string Enemigo::getTipo() const { return tipo; }

void Enemigo::mostrarStats() const {
    std::cout << "[Tipo: " << tipo << "] ";
    Personaje::mostrarStats();
}

void Enemigo::atacar(Personaje& objetivo) const {
    // Verificar si el objetivo esquiva
    if ((rand() % 100) < objetivo.getLCK()) {
        std::cout << nombre << " ataca pero " << objetivo.getNombre() << " lo esquiva!\n";
        return;
    }

    // Calcular daño base
    int danoBase = atk - objetivo.getDEF();
    danoBase = std::max(1, danoBase);

    // Verificar golpe crítico
    if ((rand() % 100) < (lck / 2)) {
        danoBase *= 2;
        std::cout << "¡Golpe critico enemigo! ";
    }

    // Aplicar daño
    std::cout << nombre << " ataca a " << objetivo.getNombre()
              << " y le inflige " << danoBase << " de dano.\n";
    objetivo.recibirDano(danoBase);
}