#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score {
private:
    std::string alias;
    std::string fechaHora;
    int salaMax;
    int saludPerdida;

public:
    Score(std::string alias, std::string fechaHora, int salaMax, int saludPerdida);

    std::string getAlias() const;
    std::string getFechaHora() const;
    int getSalaMax() const;
    int getSaludPerdida() const;

    std::string toString() const;

    // Para ordenar: primero por salaMax, luego por menor salud perdida
    bool operator<(const Score& other) const;
};

#endif //SCORE_H
