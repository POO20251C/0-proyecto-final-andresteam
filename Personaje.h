#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>

class Personaje {
protected:
    std::string nombre;
    int hp;
    int atk;
    int def;
    int spd;
    int lck;

public:
    Personaje(std::string nombre, int hp, int atk, int def, int spd, int lck);

    virtual void recibirDano(int cantidad);
    virtual bool estaVivo() const;
    virtual void mostrarStats() const;

    std::string getNombre() const;
    int getHP() const;
    int getATK() const;
    int getDEF() const;
    int getSPD() const;
    int getLCK() const;

    void aumentarEstadisticasPorcentual(float porcentajeATK, float porcentajeDEF);
    virtual ~Personaje() {}
};
#endif //PERSONAJE_H
