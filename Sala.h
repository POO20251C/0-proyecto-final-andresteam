#ifndef SALA_H
#define SALA_H

#include <vector>
#include <string>
#include "Enemigo.h"
#include "Heroe.h"

class Sala {
private:
    int numero;
    std::string tipoEvento; // "combate", "mercado", "cofre", "tesoro", "santoGrial"
    Enemigo* enemigo;
    bool completada;

public:
    Sala(int numero, std::string tipoEvento, Enemigo* enemigo = nullptr);

    void iniciarSala(std::vector<Heroe*>& heroes);
    bool estaCompletada() const;
    int getNumero() const;
    std::string getTipoEvento() const;
};

#endif //SALA_H
