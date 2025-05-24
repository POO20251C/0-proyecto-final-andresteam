#include "Mazmorra.h"
#include <iostream>
#include <memory>
#include <limits>

Mazmorra::Mazmorra() {
    salas.emplace_back(1, "mercado");
    salas.emplace_back(2, "combate", std::make_unique<Enemigo>("Goblin", "Soldado", 40, 5, 2, 3, 1));
    salas.emplace_back(3, "cofre");
    salas.emplace_back(4, "combate", std::make_unique<Enemigo>("Orco", "Soldado", 50, 6, 2, 4, 1));
    salas.emplace_back(5, "combate", std::make_unique<Enemigo>("Bandido", "Soldado", 55, 7, 3, 5, 2));
    salas.emplace_back(6, "tesoro");
    salas.emplace_back(7, "combate", std::make_unique<Enemigo>("Esqueleto", "Soldado", 60, 8, 4, 6, 2));
    salas.emplace_back(8, "santoGrial");
    salas.emplace_back(9, "combate", std::make_unique<Enemigo>("Brujo", "MiniJefe", 80, 10, 5, 7, 3));
    salas.emplace_back(10, "combate", std::make_unique<Enemigo>("Rey Demonio", "GranJefe", 100, 12, 6, 8, 4));
}

int Mazmorra::iniciarRecorrido(std::vector<Heroe*>& heroes) {
    int salaMaximaCompletada = 0;

    for (auto& sala : salas) {
        // Esperar confirmación del jugador
        std::cout << "\n--- Pulsa Enter para entrar a la Sala " << sala.getNumeroSala() << " ---";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        sala.iniciarSala(heroes);

        if (sala.estaCompletada()) {
            salaMaximaCompletada = sala.getNumeroSala();

            if (sala.getTipoEvento() == "combate") {
                // Pausa después del combate
                std::cout << "\n--- Pulsa Enter para continuar ---";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Mejora de stats
                for (auto& heroe : heroes) {
                    heroe->aumentarEstadisticasPorcentual(0.02f, 0.02f);
                }
            }
        } else {
            break; // Salir si la sala no se completó
        }
    }

    std::cout << "\n¡Has completado la mazmorra hasta la sala " << salaMaximaCompletada << "!\n";
    return salaMaximaCompletada;
}

int Mazmorra::obtenerSalaActual() const {
    for (size_t i = 0; i < salas.size(); ++i) {
        if (!salas[i].estaCompletada()) {
            return i + 1;
        }
    }
    return salas.size();
}