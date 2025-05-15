#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(string nombre, string tipo, int atk, int def, int spd, int lck, int cura)
    : nombre(nombre), tipo(tipo), modATK(atk), modDEF(def), modSPD(spd), modLCK(lck), curacion(cura) {}

void Item::mostrar() const {
    cout << "Item: " << nombre << " | Tipo: " << tipo
              << " | ATK: +" << modATK
              << " | DEF: +" << modDEF
              << " | SPD: +" << modSPD
              << " | LCK: +" << modLCK
              << " | Cura: +" << curacion << endl;
}