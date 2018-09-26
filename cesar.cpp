#include "cesar.h"

Cesar::Cesar(int x)
{
    clave = fmath::Modulo(x, alfacesar.length());
    size = int(alfacesar.length());
}

Cesar::Cesar()
{
//    srand(unsigned(time(NULL)));
    size = int(alfacesar.length());
    clave = fmath::Modulo(rand(), alfacesar.length());
}

std::string Cesar::cifrar(std::string input)
{
    int temp;
    std::string result;
    for (unsigned long i = 0; i < input.length(); i++) {
        temp = fmath::Modulo(int(alfacesar.find(input[i])) + clave, size);
        result += alfacesar[unsigned(temp)];
    }
    return result;
}

std::string Cesar::descifrar(std::string input)
{
    int temp;
    std::string result;
    for (unsigned long i = 0; i < input.length(); i++) {
        temp = fmath::Modulo(int(alfacesar.find(input[i])) - clave, size);
        result += alfacesar[unsigned(temp)];
    }
    return result;
}
