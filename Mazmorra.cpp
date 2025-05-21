#include <iostream>
#include "Mazmorra.h"
using namespace std;

Mazmorra::Mazmorra() {
    // Crear 10 salas con distintos tipos de eventos y enemigos simulados
    salas.push_back(Sala(1, "mercado"));
    salas.push_back(Sala(2, "combate", new Enemigo("Goblin", "Soldado", 40, 5, 2, 3, 1)));
    salas.push_back(Sala(3, "cofre"));
    salas.push_back(Sala(4, "combate", new Enemigo("Orco", "Soldado", 50, 6, 2, 4, 1)));
    salas.push_back(Sala(5, "combate", new Enemigo("Bandido", "Soldado", 55, 7, 3, 5, 2)));
    salas.push_back(Sala(6, "tesoro"));
    salas.push_back(Sala(7, "combate", new Enemigo("Esqueleto", "Soldado", 60, 8, 4, 6, 2)));
    salas.push_back(Sala(8, "santoGrial"));
    salas.push_back(Sala(9, "combate", new Enemigo("Brujo", "MiniJefe", 80, 10, 5, 7, 3)));
    salas.push_back(Sala(10, "combate", new Enemigo("Rey Demonio", "GranJefe", 100, 12, 6, 8, 4)));
}

void Mazmorra::iniciarRecorrido(vector<Heroe*>& heroes) {
    for (auto& sala : salas) {
        sala.iniciarSala(heroes);
        // Cada victoria aumenta 2% ATK y DEF a cada héroe
        for (auto& h : heroes) {
            h->aumentarEstadisticasPorcentual(0.02f, 0.02f);
        }
    }

    cout << "\n¡Has completado la mazmorra!" << endl;
}

int Mazmorra::obtenerSalaActual() const {
    for (size_t i = 0; i < salas.size(); ++i) {
        if (!salas[i].estaCompletada()) {
            return i + 1;
        }
    }
    return 10; // Si todas están completadas
}