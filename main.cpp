#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Heroe.h"
#include "Enemigo.h"
#include "Item.h"
#include "Sala.h"
#include "Mazmorra.h"
#include "Score.h"
#include "ScoreManager.h"
using namespace std;

string obtenerFechaHoraActual() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d_%H:%M");
    return ss.str();
}

int calcularSaludPerdidaTotal(const vector<Heroe*>& heroes) {
    int perdida = 0;
    for (const auto& h : heroes) {
        perdida += (60 - h->getHP()); // asumimos HP inicial 60
    }
    return perdida;
}

void mostrarMenuPrincipal() {
    cout << "===============================\n";
    cout << "     B I E N V E N I D O       \n";
    cout << "       NATAL COMBAT            \n";
    cout << "===============================\n";
    cout << "1. Iniciar nueva partida\n";
    cout << "2. Ver mejores puntajes\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    ScoreManager scoreManager;
    scoreManager.cargarDesdeArchivo("scores");

    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string alias;
            cout << "Ingrese su alias: ";
            getline(cin, alias);

            // Crear héroes base
            vector<Heroe*> heroes;
            heroes.push_back(new Heroe("Aegon", 60, 6, 3, 4, 1));
            heroes.push_back(new Heroe("Lyanna", 60, 5, 4, 5, 2));
            heroes.push_back(new Heroe("Duncan", 60, 7, 2, 3, 1));

            // Mostrar stats iniciales
            for (auto& h : heroes) {
                h->mostrarStats();
            }

            // Iniciar mazmorra
            Mazmorra mazmorra;
            mazmorra.iniciarRecorrido(heroes);

            // Calcular y guardar score
            int salaMax = 10; // porque se recorrieron todas
            int saludPerdida = calcularSaludPerdidaTotal(heroes);
            string fecha = obtenerFechaHoraActual();
            Score score(alias, fecha, salaMax, saludPerdida);
            scoreManager.agregarScore(score);
            scoreManager.guardarEnArchivo("scores");

            // Liberar memoria
            for (auto& h : heroes) delete h;

        } else if (opcion == 2) {
            scoreManager.mostrarTop5();
        } else if (opcion == 3) {
            cout << "Gracias por jugar. ¡Hasta pronto!\n";
        } else {
            cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 3);

    return 0;
}