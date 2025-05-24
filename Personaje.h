#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include <cstdlib> // Para rand()

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

    // Métodos de combate
    bool intentarEsquivar() const;
    int calcularDano(int atkBase) const;
    virtual void atacar(Personaje& objetivo) const = 0; // Metodo virtual puro
    virtual void recibirDano(int cantidad);

    // Getters y utilidades
    bool estaVivo() const { return hp > 0; } // Implementación directa
    virtual void mostrarStats() const; // Debe ser virtual para permitir override
    void aumentarEstadisticasPorcentual(float porcentajeATK, float porcentajeDEF);

    // Getters
    std::string getNombre() const { return nombre; }
    int getHP() const { return hp; }
    int getATK() const { return atk; }
    int getDEF() const { return def; }
    int getSPD() const { return spd; }
    int getLCK() const { return lck; }

    virtual ~Personaje() {}
};
#endif // PERSONAJE_H