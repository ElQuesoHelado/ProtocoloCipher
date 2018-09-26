#ifndef CESAR_H
#define CESAR_H
#include "mathfunc.hpp"
#include <string>

class Cesar {
private:
    const std::string alfacesar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int size;

public:
    int clave;
    std::string cifrar(std::string);
    std::string descifrar(std::string);
    Cesar(int);
    Cesar();
};

#endif // CESAR_H
