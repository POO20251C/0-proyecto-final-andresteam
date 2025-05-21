#include <iostream>
#include "Sala.h"
using namespace std;

Sala::Sala(int numero, string tipoEvento, Enemigo* enemigo)
    : numero(numero), tipoEvento(tipoEvento), enemigo(enemigo), completada(false) {}

bool Sala::estaCompletada() const {
    return completada;
}

int Sala::getNumero() const {
    return numero;
}

string Sala::getTipoEvento() const {
    return tipoEvento;
}

void Sala::iniciarSala(vector<Heroe*>& heroes) {
    cout << "\n--- Ingresando a la Sala " << numero << " (" << tipoEvento << ") ---\n";

    if (tipoEvento == "combate" && enemigo != nullptr) {
        cout << "¡Combate contra enemigo tipo " << enemigo->getTipo() << "!\n";
        enemigo->mostrarStats();
        // Aquí luego irá la lógica completa de combate por turnos
        cout << "(Simulando victoria automática para avance...)\n";
        completada = true;
    } else if (tipoEvento == "mercado") {
        cout << "Has llegado al mercado. Puedes comprar ítems (por implementar).\n";
        completada = true;
    } else if (tipoEvento == "cofre") {
        cout << "¡Cofre encontrado! Puedes obtener suerte o pociones (por implementar).\n";
        completada = true;
    } else if (tipoEvento == "tesoro") {
        cout << "¡Tesoro conseguido! Se otorgan armas raras (por implementar).\n";
        completada = true;
    } else if (tipoEvento == "santoGrial") {
        cout << "¡Santo Grial! Todos tus héroes recuperan su salud.\n";
        for (auto& h : heroes) {
            cout << "Curando a " << h->getNombre() << " al 100% de HP.\n";
            // Asumimos un método setHP() o restauración total (puede añadirse si se necesita)
        }
        completada = true;
    } else {
        cout << "Evento desconocido.\n";
    }
}