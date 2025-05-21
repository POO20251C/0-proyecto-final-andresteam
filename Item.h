#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string nombre;
    std::string tipo; // "arma", "armadura", "pocion", "accesorio"
    int modATK;
    int modDEF;
    int modSPD;
    int modLCK;
    int curacion; // Si es una poción, cuánta vida recupera

public:
    Item(std::string nombre, std::string tipo,
         int modATK = 0, int modDEF = 0, int modSPD = 0, int modLCK = 0, int curacion = 0);

    void mostrar() const;

    std::string getNombre() const;
    std::string getTipo() const;
    int getModATK() const;
    int getModDEF() const;
    int getModSPD() const;
    int getModLCK() const;
    int getCuracion() const;
};

#endif //ITEM_H
