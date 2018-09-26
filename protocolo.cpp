#include "protocolo.h"

Protocolo::Protocolo()
{
    srand(unsigned(time(NULL)));
}

std::string Protocolo::formatint(int x)
{
    std::string result;
    if (x < 10)
        result = '0' + std::to_string(x);
    else
        result = std::to_string(x);
    return result;
}

void Protocolo::cifrado(std::string input)
{
    std::string agregar,
        result,
        solmen,
        mc;

    //Genera claves rand de Cesar y Afin
    Cesar CesarCipher;
    Afin AfinCipher;

    //Agrega codigo a mensaje cifrado
    mc += input.substr(0, 3);
    //Cesar cifra input, excepto codigo
    mc += CesarCipher.cifrar(input.substr(3));

    //Solo el mensaje
    solmen = mc.substr(11);

    //Construye enigma con llaves cifradas por Cesar
    Enigma EnigCipher(mc.substr(0, 3), mc.substr(3, 3), mc.substr(6, 3), mc.substr(9, 2));

    //Enigma cifra solo el mensaje
    solmen = EnigCipher.cifrar(solmen);

    //Afin cifra solo el mensaje
    solmen = AfinCipher.cifrar(solmen);

    mc.replace(mc.begin() + 11, mc.end(), solmen);

    //String a escribir
    result = formatint(AfinCipher.a) + formatint(AfinCipher.b)
        + mc.substr(0, 3) + mc.substr(3, 3) + mc.substr(6, 3) + mc.substr(9, 2)
        + formatint(CesarCipher.clave) + solmen;

    //    result = formatint(AfinCipher.a) + formatint(AfinCipher.b)
    //        + mc.substr(3, 3) + mc.substr(0, 3) + mc.substr(6, 3) + mc.substr(9, 2)
    //        + formatint(CesarCipher.clave) + solmen;

    //Escribe result a .txt
    std::ofstream archivo("mensaje.txt");
    archivo << result;
    archivo.close();
}

std::string Protocolo::descifrado(std::string nomarch)
{
    std::string linea, mensaje;
    //Leer cifrado.txt
    std::ifstream archivoin(nomarch);
    archivoin >> linea;
    archivoin.close();

    //Separar mensaje de linea
    mensaje = linea.substr(17);

    //Construccion de Afin, Enigma, Cesar
    Afin AfinDeCipher(std::stoi(linea.substr(0, 2)), std::stoi(linea.substr(2, 2)));
    Enigma EnigDeCipher(linea.substr(4, 3), linea.substr(7, 3), linea.substr(10, 3), linea.substr(13, 2));
    //      Enigma EnigDeCipher(linea.substr(7, 3), linea.substr(4, 3), linea.substr(10, 3), linea.substr(13, 2));
    Cesar CesarDeCipher(std::stoi(linea.substr(15, 2)));

    //Descifra Afin
    mensaje = AfinDeCipher.descifrar(mensaje);

    //Descifra Enigma
    mensaje = EnigDeCipher.cifrar(mensaje);

    //Descifra Cesar
    mensaje = CesarDeCipher.descifrar(mensaje);

    //Codigo alumno + Parametros enigma(Cesar) + mensaje
    mensaje = linea.substr(4, 3) + CesarDeCipher.descifrar(linea.substr(7, 8)) + mensaje;

    return mensaje;
}
