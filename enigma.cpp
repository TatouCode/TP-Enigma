#include "enigma.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


namespace Crypt{

    Enigma::Enigma(std::string cheminFichier)
    {
        srand(time(NULL));
        _cleChiffrement = melangeString(_alphabet);
        //_plain = read(cheminFichier);
    }

    std::string const Enigma::decode(std::string const nomFichier) 
    {}
    std::string const Enigma::encode(std::string const nomFichier)
    {}


    std::string melangeString(std::string message)
    {
        std::string messageMelange = "";
        int nbLettre = message.size()-1;
        for(int i=0; i<nbLettre; i++)
        {
            int lettre = rand()%(nbLettre-i);
            messageMelange += message.at(lettre);
            message.erase(std::string::size_type(lettre), 1);
            if(message.size() == 1)
            {
                messageMelange += message;
            }
        }
        return messageMelange;
    }

}