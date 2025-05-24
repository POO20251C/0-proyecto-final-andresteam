#include <iostream>
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()
#include "Heroe.h"

Heroe::Heroe(std::string nombre, int hp, int atk, int def, int spd, int lck)
    : Personaje(nombre, hp, atk, def, spd, lck), hpMaximo(hp) {}

// --- Setters para atributos ---
void Heroe::aumentarHP(int cantidad) {
    hp += cantidad;
    if (hp < 0) hp = 0;
    std::cout << nombre << " ahora tiene " << hp << " HP.\n";
}

void Heroe::aumentarATK(int cantidad) {
    atk += cantidad;
    std::cout << nombre << " ahora tiene " << atk << " ATK.\n";
}

void Heroe::aumentarDEF(int cantidad) {
    def += cantidad;
    std::cout << nombre << " ahora tiene " << def << " DEF.\n";
}

void Heroe::aumentarSPD(int cantidad) {
    spd += cantidad;
    std::cout << nombre << " ahora tiene " << spd << " SPD.\n";
}

void Heroe::aumentarLCK(int cantidad) {
    lck += cantidad;
    std::cout << nombre << " ahora tiene " << lck << " LCK.\n";
}

// --- Gestión de ítems ---
void Heroe::agregarItem(const Item& item) {
    if (inventario.size() >= 50) {
        std::cout << "¡Inventario lleno!\n";
        return;
    }
    inventario.push_back(item);
}

void Heroe::equiparItem(const Item& item) {
    try {
        item.aplicarEfecto(*this); // Usa los setters internamente
        std::cout << nombre << " ha equipado " << item.getNombre() << ".\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error al equipar: " << e.what() << "\n";
    }
}

void Heroe::usarPocion() {
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->getTipo() == "pocion") {
            aumentarHP(it->getCuracion());
            inventario.erase(it);
            return;
        }
    }
    std::cout << nombre << " no tiene pociones.\n";
}

void Heroe::mostrarInventario() const {
    std::cout << "Inventario de " << nombre << ":\n";
    for (const auto& item : inventario) {
        item.mostrar();
    }
}

// --- Combate ---
void Heroe::atacar(Personaje& enemigo) const {
    // Verificar si el enemigo esquiva (basado en su LCK)
    if ((rand() % 100) < enemigo.getLCK()) {
        std::cout << nombre << " ataca pero " << enemigo.getNombre() << " lo esquiva!\n";
        return;
    }

    // Calcular daño base (ATK del héroe - DEF del enemigo)
    int danoBase = atk - enemigo.getDEF();
    danoBase = std::max(1, danoBase); // Asegurar mínimo 1 de daño

    // Verificar golpe crítico
    if ((rand() % 100) < (lck / 2)) {
        danoBase *= 2;
        std::cout << "¡Golpe critico! ";
    }

    // Aplicar daño al enemigo
    std::cout << nombre << " ataca a " << enemigo.getNombre()
              << " y le inflige " << danoBase << " de dano.\n";
    enemigo.recibirDano(danoBase);
}

void Heroe::aumentarEstadisticasPorcentual(float porcentajeHP, float porcentajeStats) {
    // Aumentar HP máximo y actual
    int aumentoHP = static_cast<int>(hpMaximo * porcentajeHP);
    hpMaximo += aumentoHP;
    hp += aumentoHP;

    // Aumentar otras estadísticas
    atk += static_cast<int>(atk * porcentajeStats);
    def += static_cast<int>(def * porcentajeStats);
    spd += static_cast<int>(spd * porcentajeStats);
    lck += static_cast<int>(lck * porcentajeStats);

    std::cout << nombre << " ha mejorado sus estadisticas!\n";
    std::cout << "HP: +" << aumentoHP
              << " | ATK: +" << static_cast<int>(atk * porcentajeStats)
              << " | DEF: +" << static_cast<int>(def * porcentajeStats)
              << " | SPD: +" << static_cast<int>(spd * porcentajeStats)
              << " | LCK: +" << static_cast<int>(lck * porcentajeStats) << "\n";
}