#include "ScoreManager.h"
#include <iostream>
#include <algorithm>

void ScoreManager::cargarDesdeArchivo(const std::string& archivo) {
    scores.clear();
    std::ifstream in(archivo);
    if (!in) {
        return;
    }

    std::string linea;
    while (std::getline(in, linea)) {
        // Eliminar espacios en blanco al inicio y final
        linea.erase(0, linea.find_first_not_of(" \t\n\r\f\v"));
        linea.erase(linea.find_last_not_of(" \t\n\r\f\v") + 1);

        if (linea.empty()) continue; // Saltar líneas vacías

        size_t pos1 = linea.find('|');
        size_t pos2 = linea.find('|', pos1 + 1);

        if (pos1 == std::string::npos || pos2 == std::string::npos) {
            std::cerr << "Error: Formato invalido en linea: " << linea << "\n";
            continue;
        }

        try {
            // Extraer y limpiar los componentes
            std::string alias = linea.substr(0, pos1);
            alias.erase(0, alias.find_first_not_of(" \t\n\r\f\v"));
            alias.erase(alias.find_last_not_of(" \t\n\r\f\v") + 1);

            int salaMax = std::stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
            int saludPerdida = std::stoi(linea.substr(pos2 + 1));

            // Construir el objeto Score correctamente
            scores.push_back(Score(alias, salaMax, saludPerdida));
        } catch (const std::exception& e) {
            std::cerr << "Error al procesar linea: " << e.what() << "\n";
        }
    }
}

void ScoreManager::guardarEnArchivo(const std::string& archivo) const {
    std::ofstream out(archivo);
    if (!out) {
        throw std::runtime_error("No se pudo guardar el archivo de puntuaciones");
    }

    for (const auto& s : scores) {
        out << s.getAlias() << "|" << s.getSalaMax() << "|"
            << s.getSaludPerdida() << "\n";
    }
}

void ScoreManager::agregarScore(const Score& nuevo) {
    scores.push_back(nuevo);

    // Ordenar de mayor a menor por salaMax, luego por menor saludPerdida
    std::sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
        if (a.getSalaMax() != b.getSalaMax()) {
            return a.getSalaMax() > b.getSalaMax();
        }
        return a.getSaludPerdida() < b.getSaludPerdida();
    });

    // Mantener solo el top 5 (usando erase en lugar de resize)
    if (scores.size() > 5) {
        scores.erase(scores.begin() + 5, scores.end());
    }
}

void ScoreManager::mostrarTop5() const {
    std::cout << "\n=== TOP 5 PUNTUACIONES ===" << std::endl;
    if (scores.empty()) {
        std::cout << "No hay puntuaciones registradas aun." << std::endl;
        return;
    }

    for (size_t i = 0; i < scores.size() && i < 5; ++i) {
        std::cout << i+1 << ". " << scores[i].toString() << std::endl;
    }
}