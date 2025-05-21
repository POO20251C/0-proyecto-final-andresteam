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
    if (hp < 0) hp = 0;
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

string Personaje::getNombre() const { return nombre; }
int Personaje::getHP() const { return hp; }
int Personaje::getATK() const { return atk; }
int Personaje::getDEF() const { return def; }
int Personaje::getSPD() const { return spd; }
int Personaje::getLCK() const { return lck; }

void Personaje::aumentarEstadisticasPorcentual(float porcentajeATK, float porcentajeDEF) {
    atk += static_cast<int>(atk * porcentajeATK);
    def += static_cast<int>(def * porcentajeDEF);
}
