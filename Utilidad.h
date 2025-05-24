#ifndef UTILIDAD_H
#define UTILIDAD_H

#include <limits>
#include <iostream>

inline void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif //UTILIDAD_H
