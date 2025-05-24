#ifndef SALA_H
#define SALA_H

#include <memory>
#include <vector>
#include "Enemigo.h"
#include "Heroe.h"

class Sala {
private:
    int numero;
    std::string tipoEvento;
    std::unique_ptr<Enemigo> enemigo;
    bool completada;

public:
    Sala(int numero, std::string tipoEvento, std::unique_ptr<Enemigo> enemigo = nullptr);

    void iniciarSala(std::vector<Heroe*>& heroes);
    bool estaCompletada() const { return completada; }
    std::string getTipoEvento() const { return tipoEvento; }
    Enemigo* getEnemigo() const { return enemigo.get(); }

    // Nuevo metodo añadido
    int getNumeroSala() const { return numero; }
};

#endif // SALA_H