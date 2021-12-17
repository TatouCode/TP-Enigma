#include "enigma.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


namespace Crypt{

    Enigma::Enigma() : Encrypt{}
    {
        srand(time(NULL));
        _cleChiffrement = melangeString(_alphabet);
    }

    Enigma::Enigma(std::string const cheminFichierLecture, std::string const cheminFichierEcriture) : Encrypt{cheminFichierLecture, cheminFichierEcriture}
    {
        srand(time(NULL));
        _cleChiffrement = melangeString(_alphabet);
    }

    void const Enigma::decode() 
    {
        std::string messageDecode = "";
        std::string cleTemp = _cleChiffrement;
        for(int i=0; i<=_cipher.size()-1; i++)
        {
            int j = 0;
            while(_cipher.at(i) != _alphabet.at(j))
            {
                j += 1;
            }
            messageDecode += cleTemp.at(j);
            cleTemp = decalageStringDroit(cleTemp);
        }
        _plain = messageDecode;
    }

    void const Enigma::encode()
    {
        std::string messageEncode = "";
        std::string cleTemp = _cleChiffrement;
        for(int i=0; i<=_plain.size()-1; i++)
        {
            int j = 0;
            while(_plain.at(i) != _alphabet.at(j))
            {
                j += 1;
            }
            messageEncode += cleTemp.at(j);
            cleTemp = decalageStringGauche(cleTemp);
        }
        _cipher = messageEncode;
    }


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

    std::string decalageStringGauche(std::string message)
    {
        std::string messageDecale = "";
        int nbLettre = message.size()-1;
        char premiereLettre = message.at(0);
        for(int i=1; i<=nbLettre; i++)
        {
            messageDecale += message.at(i);
        }
        messageDecale += premiereLettre;
        return messageDecale;
    }

    std::string decalageStringDroit(std::string message)
    {
        std::string messageDecale = "";
        int nbLettre = message.size()-1;
        char derniereLettre = message.at(message.size()-1);
        messageDecale += derniereLettre;
        for(int i=0; i<nbLettre; i++)
        {
            messageDecale += message.at(i);
        }
        return messageDecale;
    }

}