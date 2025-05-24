#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

class Score {
private:
    std::string alias;
    std::string fechaHora;
    int salaMax;
    int saludPerdida;
public:
    Score();
    Score(std::string alias, int salaMax, int saludPerdida);
    std::string toString() const;
    bool operator<(const Score& other) const;

    // Getters
    std::string getAlias() const { return alias; }
    std::string getFechaHora() const { return fechaHora; }
    int getSalaMax() const { return salaMax; }
    int getSaludPerdida() const { return saludPerdida; }
};

#endif // SCORE_H