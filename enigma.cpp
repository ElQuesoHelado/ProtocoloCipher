#include "enigma.h"

Enigma::Enigma(int rtizq, int rtmed, int rtder, std::string rtpos, std::string rtlim, std::string rtsteck)
{
    //Rotores a usar
    abcrotizq = abecerotores[rtizq - 1];
    abcrotmed = abecerotores[rtmed - 1];
    abcrotder = abecerotores[rtder - 1];

    //Posiciones rotores
    origposrizq = int(alfaenigma.find(rtpos[0]));
    origposrmed = int(alfaenigma.find(rtpos[1]));
    origposrder = int(alfaenigma.find(rtpos[2]));

    //Limites rotores
    limizq = int(alfaenigma.find(rtlim[0]));
    limmed = int(alfaenigma.find(rtlim[1]));
    limder = int(alfaenigma.find(rtlim[2]));

    //Steckers
    steckers = rtsteck;
}

Enigma::Enigma(std::string rotores, std::string rtpos, std::string rtlim, std::string rtsteck)
{
    int rtizq = int(rotores[0] - '0');
    int rtmed = int(rotores[1] - '0');
    int rtder = int(rotores[2] - '0');

    //Rotores a usar
    abcrotizq = abecerotores[rtizq - 1];
    abcrotmed = abecerotores[rtmed - 1];
    abcrotder = abecerotores[rtder - 1];

    //Posiciones rotores
    origposrizq = int(alfaenigma.find(rtpos[0]));
    origposrmed = int(alfaenigma.find(rtpos[1]));
    origposrder = int(alfaenigma.find(rtpos[2]));

    //Limites rotores
    limizq = int(alfaenigma.find(rtlim[0]));
    limmed = int(alfaenigma.find(rtlim[1]));
    limder = int(alfaenigma.find(rtlim[2]));

    //Steckers
    steckers = rtsteck;
}

void Enigma::operar(std::string& x, const std::string& buscar, const std::string& reemplazar, int giros)
{
    int base = buscar.length();

    //abecedario es estatico
    //Suma de giro en el abecedario
    int columna = alfaenigma.find(x) + giros;
    columna = fmath::Modulo(columna, base);
    x = alfaenigma[columna];

    //busqueda y reemplazo con los abecedarios
    columna = buscar.find(x);
    x = reemplazar[columna];

    //Abecedario estatico
    //Se reduce giros
    columna = alfaenigma.find(x) - giros;
    columna = fmath::Modulo(columna, base);
    x = alfaenigma[columna];
}

std::string Enigma::cifrar(std::string input)
{
    std::string agregar;
    std::string result;
    int tamanio = input.length();
    int base = alfaenigma.length();

    //reset posiciones de rotores
    int posrder = origposrder,
        posrmed = origposrmed,
        posrizq = origposrizq;

    for (int i = 0; i < tamanio; i++) {
        agregar = input[i];

        //check steckers input
        if (agregar[0] == steckers[0])
            agregar[0] = steckers[1];
        else if (agregar[0] == steckers[1])
            agregar[0] = steckers[0];

        //step derecha
        posrder = fmath::Modulo(++posrder, base);
        if (posrder == limder) {
            posrmed = fmath::Modulo(++posrmed, base);

            //step medio
            if (posrmed == limmed) {
                posrizq = fmath::Modulo(++posrizq, base);
            }
        }

        //Rotor derecha
        operar(agregar, alfaenigma, abcrotder, posrder);

        //Rotor medio
        operar(agregar, alfaenigma, abcrotmed, posrmed);

        //Rotor izquierda
        operar(agregar, alfaenigma, abcrotizq, posrizq);

        //Reflector
        operar(agregar, alfaenigma, abecereflect, 0);

        //Rotor izquierda inversa
        operar(agregar, abcrotizq, alfaenigma, posrizq);

        //Rotor medio inversa
        operar(agregar, abcrotmed, alfaenigma, posrmed);

        //Rotor derecha inversa
        operar(agregar, abcrotder, alfaenigma, posrder);
        //        std::cout << agregar << " ";

        //        std::cout << "\n";

        //check steckers output
        if (agregar[0] == steckers[0])
            agregar[0] = steckers[1];
        else if (agregar[0] == steckers[1])
            agregar[0] = steckers[0];

        //append a result
        result += agregar;
    }
    return result;
}
