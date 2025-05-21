#include <fstream>
#include <algorithm>
#include <iostream>
#include "ScoreManager.h"
using namespace std;

void ScoreManager::cargarDesdeArchivo(const string& archivo) {
    scores.clear();
    ifstream in(archivo);
    if (!in) return;

    string alias, fecha;
    int sala, perdida;

    while (in >> alias >> fecha >> sala >> perdida) {
        scores.emplace_back(alias, fecha, sala, perdida);
    }
    in.close();
}

void ScoreManager::guardarEnArchivo(const string& archivo) {
    ofstream out(archivo);
    for (const auto& s : scores) {
        out << s.getAlias() << " " << s.getFechaHora() << " "
            << s.getSalaMax() << " " << s.getSaludPerdida() << endl;
    }
    out.close();
}

void ScoreManager::agregarScore(const Score& nuevo) {
    scores.push_back(nuevo);
    sort(scores.begin(), scores.end());
    if (scores.size() > 5) scores.resize(5); // mantener solo los mejores 5
}

void ScoreManager::mostrarTop5() const {
    cout << "\n===== TOP 5 PUNTUACIONES =====\n";
    if (scores.empty()) {
        cout << "Aún no hay registros.\n";
        return;
    }

    for (size_t i = 0; i < scores.size(); ++i) {
        cout << i + 1 << ". " << scores[i].toString() << endl;
    }
}
