#include <string>
#include <iostream>
#include "Personaje.h"

using namespace std;

Personaje::Personaje(string nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck) {}

void Personaje::recibirDano(int cantidad) {
    int danoFinal = cantidad - def;
    if (danoFinal < 0) danoFinal = 0;
    hp -= danoFinal;
    cout << nombre << " recibe " << danoFinal << " de daño. HP restante: " << hp << endl;
}

bool Personaje::estaVivo() const {
    return hp > 0;
}

void Personaje::mostrarStats() const {
    cout << "Nombre: " << nombre
              << " | HP: " << hp
              << " | ATK: " << atk
              << " | DEF: " << def
              << " | SPD: " << spd
              << " | LCK: " << lck << endl;
}
