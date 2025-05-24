#include "Sala.h"
#include <iostream>
#include <algorithm>
#include "Utilidad.h"
#include "Item.h"

Sala::Sala(int numero, std::string tipoEvento, std::unique_ptr<Enemigo> enemigo)
    : numero(numero), tipoEvento(tipoEvento), enemigo(std::move(enemigo)), completada(false) {
    // Implementación del constructor
}

void Sala::iniciarSala(std::vector<Heroe*>& heroes) {
    std::cout << "\n=== SALA " << numero << " (" << tipoEvento << ") ===\n";

    if (tipoEvento == "combate" && enemigo != nullptr) {
        std::cout << "¡Enemigo: " << enemigo->getNombre() << " (" << enemigo->getTipo() << ")!\n";
        enemigo->mostrarStats();

        while (enemigo->estaVivo() && std::any_of(heroes.begin(), heroes.end(), [](Heroe* h) { return h->estaVivo(); })) {
            // Turno del jugador
            std::cout << "\n--- TURNO DEL JUGADOR ---\n";
            for (size_t i = 0; i < heroes.size(); ++i) {
                if (heroes[i]->estaVivo()) {
                    std::cout << i+1 << ". " << heroes[i]->getNombre()
                              << " (HP: " << heroes[i]->getHP() << "/" << heroes[i]->getHPMaximo() << ")\n";
                }
            }

            int heroeIndex, accion;
            std::cout << "Elige heroe (1-" << heroes.size() << "): ";
            std::cin >> heroeIndex;
            heroeIndex--;

            if (heroeIndex >= 0 && heroeIndex < heroes.size() && heroes[heroeIndex]->estaVivo()) {
                std::cout << "1. Atacar\n2. Usar pocion\n3. Ver stats\nElige accion: ";
                std::cin >> accion;
                limpiarBuffer();

                switch (accion) {
                    case 1:
                        heroes[heroeIndex]->atacar(*enemigo);
                        break;
                    case 2:
                        heroes[heroeIndex]->usarPocion();
                        break;
                    case 3:
                        heroes[heroeIndex]->mostrarStats();
                        enemigo->mostrarStats();
                        break;
                    default:
                        std::cout << "Acción invalida\n";
                }
            } else {
                std::cout << "Selección invalida\n";
                limpiarBuffer();
            }

            // Turno del enemigo
            if (enemigo->estaVivo()) {
                std::cout << "\n--- TURNO DEL ENEMIGO ---\n";
                for (auto& heroe : heroes) {
                    if (heroe->estaVivo()) {
                        enemigo->atacar(*heroe);
                        break;
                    }
                }
            }
        }
        completada = !enemigo->estaVivo();
        std::cout << (completada ? "¡Victoria!" : "¡Derrota!") << "\n";

    } else if (tipoEvento == "mercado") {
        std::cout << "Bienvenido al mercado. Proximamente podras comprar items.\n";
        completada = true;

    } else if (tipoEvento == "cofre") {
        std::cout << "¡Has encontrado un cofre con una pocion!\n";
        for (auto& heroe : heroes) {
            heroe->agregarItem(Item("Pocion", "consumible", 30, 0, 0));
        }
        completada = true;

    } else if (tipoEvento == "tesoro") {
        std::cout << "¡Tesoro descubierto! Todos obtienen una espada mejorada.\n";
        for (auto& heroe : heroes) {
            heroe->agregarItem(Item("Espada Mejorada", "arma", 0, 5, 0));
        }
        completada = true;

    } else if (tipoEvento == "santoGrial") {
        std::cout << "¡Santo Grial! Todos los heroes recuperan toda su salud.\n";
        for (auto& heroe : heroes) {
            heroe->aumentarHP(heroe->getHPMaximo() - heroe->getHP());
        }
        completada = true;
    }
}