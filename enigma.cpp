#include "enigma.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


namespace Crypt{

    Enigma::Enigma(std::string cheminFichier)
    {
        srand(time(NULL));
    }

    std::string Enigma::initCle()
    {
        std::string cle = "";
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        int nbLettre = 26;
        for(int i=0; i<26; i++)
        {
            int lettre = rand()%(26-i);
            cle += alphabet.at(lettre);
            alphabet.erase(lettre);
        }
        _cleChiffrement = cle;
    }

    std::string const Enigma::decode(std::string const nomFichier) 
    {}
    std::string const Enigma::encode(std::string const nomFichier)
    {}

}