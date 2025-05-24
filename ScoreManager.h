#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include "Score.h"

class ScoreManager {
private:
    std::vector<Score> scores;

public:
    void cargarDesdeArchivo(const std::string& archivo);
    void guardarEnArchivo(const std::string& archivo) const;
    void agregarScore(const Score& nuevo);
    void mostrarTop5() const;
};

#endif // SCOREMANAGER_H