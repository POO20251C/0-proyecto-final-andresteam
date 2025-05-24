#include <iostream>
#include "Personaje.h"

Personaje::Personaje(std::string nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck) {}

bool Personaje::intentarEsquivar() const {
    return (rand() % 100) < lck; // LCK% de probabilidad de esquivar
}

int Personaje::calcularDano(int atkBase) const {
    bool critico = (rand() % 100) < (lck / 2); // LCK/2% de probabilidad de crítico
    return critico ? atkBase * 2 : atkBase;
}

void Personaje::recibirDano(int cantidad) {
    if (intentarEsquivar()) {
        std::cout << nombre << " esquivo el ataque!\n";
        return;
    }
    int danoFinal = std::max(0, cantidad - def); // Daño mínimo 0
    hp -= danoFinal;
    std::cout << nombre << " recibe " << danoFinal << " de dano. HP restante: " << hp << "\n";
}

void Personaje::mostrarStats() const {
    std::cout << "Nombre: " << nombre << " | HP: " << hp << " | ATK: " << atk
              << " | DEF: " << def << " | SPD: " << spd << " | LCK: " << lck << "\n";
}

void Personaje::aumentarEstadisticasPorcentual(float porcentajeATK, float porcentajeDEF) {
    atk += static_cast<int>(atk * porcentajeATK);
    def += static_cast<int>(def * porcentajeDEF);
}