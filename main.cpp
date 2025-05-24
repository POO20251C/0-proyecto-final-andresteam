#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm> // Para std::random_shuffle
#include "Heroe.h"
#include "Mazmorra.h"
#include "ScoreManager.h"

using namespace std;

// --- Prototipos de funciones nuevas ---
vector<Heroe> crearPoolHeroes();
vector<Heroe*> seleccionarHeroes(vector<Heroe>& pool);
void mostrarHeroesDisponibles(const vector<Heroe>& heroes);
void limpiarBuffer();

int calcularSaludPerdidaTotal(const vector<Heroe*>& heroes) {
    int perdida = 0;
    for (const auto& h : heroes) {
        perdida += (h->getHPMaximo() - h->getHP());
    }
    return perdida;
}

void mostrarMenuPrincipal() {
    cout << "\n===============================\n";
    cout << "     B I E N V E N I D O       \n";
    cout << "       NATAL COMBAT            \n";
    cout << "===============================\n";
    cout << "1. Iniciar nueva partida\n";
    cout << "2. Ver mejores puntajes\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
}

// --- Nuevas funciones implementadas ---
vector<Heroe> crearPoolHeroes() {
    return {
        Heroe("Cristiano Ronaldo", 60, 6, 3, 4, 1),
        Heroe("Leo Messi", 60, 5, 4, 5, 2),
        Heroe("Neymar Jr", 60, 7, 2, 3, 1),
        Heroe("Toni Kroos", 65, 4, 5, 3, 2),
        Heroe("Gareth Bale", 55, 8, 2, 6, 1),
        Heroe("Luka Modric", 70, 3, 6, 2, 3)
    };
}

vector<Heroe*> seleccionarHeroes(vector<Heroe>& pool) {
    vector<Heroe*> equipo;
    int opcion;

    cout << "\n=== SELECCIONA 3 HEROES ===\n";
    mostrarHeroesDisponibles(pool);

    cout << "7. Seleccion aleatoria\n";

    for (int i = 0; i < 3; ++i) {
        cout << "Elige el heroe " << i + 1 << " (1-6 o 7 para aleatorio): ";
        while (!(cin >> opcion) || (opcion < 1 || opcion > 7)) {
            cout << "Opcion invalida. Elige 1-6 o 7: ";
            limpiarBuffer();
        }

        if (opcion == 7) {
            random_shuffle(pool.begin(), pool.end());
            equipo.push_back(&pool[i]);
            cout << "¡" << pool[i].getNombre() << " anadido al equipo!\n";
        } else {
            equipo.push_back(&pool[opcion - 1]);
            cout << "¡" << pool[opcion - 1].getNombre() << " anadido al equipo!\n";
        }
    }
    return equipo;
}

void mostrarHeroesDisponibles(const vector<Heroe>& heroes) {
    for (size_t i = 0; i < heroes.size(); ++i) {
        cout << i + 1 << ". ";
        heroes[i].mostrarStats();
    }
}

// --- Main actualizado ---
int main() {
    srand(time(nullptr));

    ScoreManager scoreManager;
    try {
        scoreManager.cargarDesdeArchivo("scores.txt");
    } catch (const exception& e) {
        cout << "\nAdvertencia: No se encontraron puntuaciones previas.\n";
    }

    int opcion;
    do {
        mostrarMenuPrincipal();

        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese un numero: ";
            limpiarBuffer();
        }
        limpiarBuffer();

        if (opcion == 1) {
            string alias;
            cout << "Ingrese su alias (max 15 caracteres): ";
            getline(cin, alias);

            if (alias.empty()) alias = "JugadorAnonimo";
            else if (alias.length() > 15) alias = alias.substr(0, 15);

            // Crear pool y seleccionar héroes
            vector<Heroe> pool = crearPoolHeroes();
            vector<Heroe*> equipo = seleccionarHeroes(pool);

            cout << "\n=== TU EQUIPO ===";
            for (const auto& h : equipo) h->mostrarStats();

            // Iniciar mazmorra con interacción manual
            Mazmorra mazmorra;
            int salaFinal = mazmorra.iniciarRecorrido(equipo);

            if (salaFinal > 0) {
                int saludPerdida = calcularSaludPerdidaTotal(equipo);
                scoreManager.agregarScore(Score(alias, salaFinal, saludPerdida));
                scoreManager.guardarEnArchivo("scores.txt");
            }

        } else if (opcion == 2) {
            scoreManager.mostrarTop5();
        } else if (opcion != 3) {
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);

    cout << "\nGracias por jugar. ¡Hasta pronto!\n";
    return 0;
}