#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string nombre;
    std::string tipo;
    int modATK, modDEF, modSPD, modLCK, curacion;

public:
    Item(std::string nombre, std::string tipo, int atk = 0, int def = 0, int spd = 0, int lck = 0, int cura = 0);
    void mostrar() const;

    std::string getTipo() const { return tipo; }
    int getCuracion() const { return curacion; }
};

#endif //ITEM_H
