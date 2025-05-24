#include "Score.h"

// Constructor por defecto
Score::Score() : alias(""), salaMax(0), saludPerdida(0) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    fechaHora = ss.str();
}

Score::Score(std::string alias, int salaMax, int saludPerdida)
    : alias(alias), salaMax(salaMax), saludPerdida(saludPerdida) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    fechaHora = ss.str();
}

std::string Score::toString() const {
    std::stringstream ss;
    ss << alias << " | " << fechaHora << " | Sala: " << salaMax << " | Salud perdida: " << saludPerdida;
    return ss.str();
}

bool Score::operator<(const Score& other) const {
    if (salaMax != other.salaMax) return salaMax > other.salaMax;
    return saludPerdida < other.saludPerdida;
}