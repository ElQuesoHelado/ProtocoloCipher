#include "afin.h"

//Constr para encriptar
Afin::Afin()
{
    //Size alfabeto
    size = int(alfaafin.length());

    //Seed rand() con time.h
    //    srand(unsigned(time(NULL)));

    //Genera a y b al azar
    a = fmath::Modulo(rand(), size);
    b = fmath::Modulo(rand(), size);

    //Check si mcd(a,N)=1
    while (fmath::mcd(a, size) != 1)
        a = fmath::Modulo(rand(), size);
}

//Constr para desencriptar
Afin::Afin(int x, int y)
{
    //Size alfabeto
    size = int(alfaafin.length());

    a = x;
    b = y;
    //halla inversa de a
    ai = fmath::Modulo(inversa(a, size), size);
}

//Inversa llama euclides extendido
int Afin::inversa(int a, int b)
{
    return fmath::euclext(a, b)[1];
}

std::string Afin::cifrar(std::string m)
{
    std::string mc;
    int temp;
    for (int i = 0; i < m.length(); i++) {
        //busca letra en el abecedario
        temp = alfaafin.find(m[i]);
        //Se aplica funcion a la letra en numero
        temp = fmath::Modulo(temp * a, size);
        temp = fmath::Modulo(temp + b, size);

        //Se pasa numero a letra en el abecedario
        //Append a resultado
        mc += alfaafin[temp];
    }
    return mc;
}

std::string Afin::descifrar(std::string mcifra)
{
    std::string men;
    int temp = 0;

    for (int i = 0; i < mcifra.length(); i++) {
        temp = alfaafin.find(mcifra[i]);
        temp = fmath::Modulo(temp - b, size);
        temp = fmath::Modulo(temp * ai, size);
        men += alfaafin[temp];
    }
    return men;
}
