#ifndef PROTOCOLO_H
#define PROTOCOLO_H
#include "afin.h"
#include "cesar.h"
#include "enigma.h"
#include <fstream>
#include <string>

class Protocolo {
private:
    std::string formatint(int);

public:
    Protocolo();
    void cifrado(std::string); //crea el txt
    std::string descifrado(std::string); //devuelve el string original
};

#endif // PROTOCOLO_H
