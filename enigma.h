#ifndef ENIGMA_H
#define ENIGMA_H
#include "mathfunc.hpp"
#include <string>

class Enigma {
private:
    const std::string alfaenigma = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string abecereflect = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    const std::string abecerotores[7] = { "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",
        "VZBRGITYUPSDNHLXAWMJQOFECK",
        "JPGVOUMFYQBENHZRDKASXLICTW",
        "NZJHGRCXMYSWBOUFAIVLPEKQDT" };
    std::string abcrotizq, abcrotmed, abcrotder, steckers;
    int limizq, limmed, limder, origposrizq, origposrmed, origposrder;

public:
    void operar(std::string&, const std::string&, const std::string&, int);
    std::string cifrar(std::string inputs);
    Enigma(int rtizq, int rtmed, int rtder, std::string rtpos, std::string rtlim, std::string rtsteck);
    Enigma(std::string rotores, std::string rtpos, std::string rtlim, std::string rtsteck);
};

#endif // ENIGMA_H
