#include <iostream>
#include "Enemigo.h"
using namespace std;

Enemigo::Enemigo(string nombre, string tipo, int hp, int atk, int def, int spd, int lck)
    : Personaje(nombre, hp, atk, def, spd, lck), tipo(tipo) {}

string Enemigo::getTipo() const {
    return tipo;
}

void Enemigo::mostrarStats() const {
    cout << "[Tipo: " << tipo << "] ";
    Personaje::mostrarStats();
}