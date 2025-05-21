#include <sstream>
#include "Score.h"
using namespace std;

Score::Score(string alias, string fechaHora, int salaMax, int saludPerdida)
    : alias(alias), fechaHora(fechaHora), salaMax(salaMax), saludPerdida(saludPerdida) {}

string Score::getAlias() const { return alias; }
string Score::getFechaHora() const { return fechaHora; }
int Score::getSalaMax() const { return salaMax; }
int Score::getSaludPerdida() const { return saludPerdida; }

string Score::toString() const {
    stringstream ss;
    ss << alias << " | " << fechaHora << " | Sala alcanzada: " << salaMax
       << " | Salud perdida: " << saludPerdida;
    return ss.str();
}

bool Score::operator<(const Score& other) const {
    if (salaMax != other.salaMax)
        return salaMax > other.salaMax; // Más salas es mejor
    return saludPerdida < other.saludPerdida; // Menos daño es mejor
}