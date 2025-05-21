#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(string nombre, string tipo, int modATK, int modDEF, int modSPD, int modLCK, int curacion)
    : nombre(nombre), tipo(tipo), modATK(modATK), modDEF(modDEF), modSPD(modSPD), modLCK(modLCK), curacion(curacion) {}

void Item::mostrar() const {
    cout << "Item: " << nombre << " | Tipo: " << tipo;
    if (modATK) cout << " | +ATK: " << modATK;
    if (modDEF) cout << " | +DEF: " << modDEF;
    if (modSPD) cout << " | +SPD: " << modSPD;
    if (modLCK) cout << " | +LCK: " << modLCK;
    if (curacion) cout << " | Cura: +" << curacion;
    cout << endl;
}

string Item::getNombre() const { return nombre; }
string Item::getTipo() const { return tipo; }
int Item::getModATK() const { return modATK; }
int Item::getModDEF() const { return modDEF; }
int Item::getModSPD() const { return modSPD; }
int Item::getModLCK() const { return modLCK; }
int Item::getCuracion() const { return curacion; }