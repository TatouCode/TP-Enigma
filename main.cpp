/**
 * @file main.cpp
 * @author Lucas 
 * @author Benjamin
 * @brief main du TP
 * @version 1.0
 * @date 2022-01-04
 * 
 */

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "enigma.h"

int main (){

    //Codage du message dans le fichier plain.txt
    Crypt::Enigma enigma;
    enigma.setPlain(Crypt::read("plain.txt"));
    enigma.setCipher(enigma.encode());
    Crypt::write("cipher.txt", enigma.getCipher());
    std::cout << enigma.getPlain() << std::endl;
    std::cout << enigma.getCipher() << std::endl;
    std::cout << std::endl;


    //Decodage du message dans le fichier cipher.txt
    enigma.setCipher(Crypt::read("cipher.txt"));
    enigma.setPlain(enigma.decode());
    std::cout << enigma.getCipher() << std::endl;
    std::cout << enigma.getPlain() << std::endl;
    std::cout << std::endl;

}