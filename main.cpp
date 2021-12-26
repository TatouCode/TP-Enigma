#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "enigma.h"

int main (){

    
    Crypt::Enigma enigma;
    //std::cout << Crypt::read("plain.txt") << std::endl;
    enigma.setPlain(Crypt::read("plain.txt"));
    //Crypt::Enigma enigma("plain.txt", "cipher.txt");
    //std::cout << enigma.getPlain() << std::endl;
    enigma.setCipher(enigma.encode());
    //std::cout << enigma.getCipher() << std::endl;
    Crypt::write("cipher.txt", enigma.getCipher());

    std::cout << enigma.getPlain() << std::endl;
    std::cout << enigma.getCipher() << std::endl;
    std::cout << std::endl;

    //enigma.setCipher(Crypt::read("cipher.txt"));
    enigma.setPlain(enigma.decode());
    std::cout << enigma.getCipher() << std::endl;
    std::cout << enigma.getPlain() << std::endl;
    //Crypt::write("plain.txt", enigma.getCipher());

}