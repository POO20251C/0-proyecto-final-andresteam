#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <stdexcept> // Para std::invalid_argument

class Heroe; // Declaración adelantada para evitar includes circulares

class Item {
private:
    std::string nombre;
    std::string tipo; // "arma", "armadura", "pocion", "accesorio"
    int modATK;
    int modDEF;
    int modSPD;
    int modLCK;
    int curacion;

    void validarAtributos() const;

public:
    Item(std::string nombre, std::string tipo,
         int modATK = 0, int modDEF = 0, int modSPD = 0, int modLCK = 0, int curacion = 0);

    void aplicarEfecto(Heroe& heroe) const;
    void mostrar() const;

    // Getters
    std::string getNombre() const { return nombre; }
    std::string getTipo() const { return tipo; }
    int getModATK() const { return modATK; }
    int getModDEF() const { return modDEF; }
    int getModSPD() const { return modSPD; }
    int getModLCK() const { return modLCK; }
    int getCuracion() const { return curacion; }
};
#endif // ITEM_H