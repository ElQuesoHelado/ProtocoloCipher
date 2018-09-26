#ifndef AFIN_H
#define AFIN_H
#include "mathfunc.hpp"
#include <string>
#include <vector>

class Afin {
private:
    const std::string alfaafin = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int size;
    int ai;
    int inversa(int, int);

public:
    int a, b;
    std::string cifrar(std::string);
    std::string descifrar(std::string);
    Afin();
    Afin(int a, int b);
};

#endif // AFIN_H
