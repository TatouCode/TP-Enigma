#include "enigma.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>



namespace Crypt{

    Enigma::Enigma() : Encrypt{}
    {
        srand(time(NULL));
        //_cleChiffrement = _alphabet;
        //_cleChiffrement2 = _alphabet;
        _cleChiffrement = melangeString(_alphabet);
        _cleChiffrement2 = melangeString(_alphabet);
    }

    Enigma::Enigma(std::string const cheminFichierLecture, std::string const cheminFichierEcriture) : Encrypt{cheminFichierLecture, cheminFichierEcriture}
    {
        srand(time(NULL));
        _cleChiffrement = melangeString(_alphabet);
        _cleChiffrement2 = melangeString(_alphabet);
    }

    std::string const Enigma::decode() 
    {
        //return vigenereDecode(_cipher, _cleChiffrement);
        return decode2Rotor();
    }

    /*std::string const Enigma::decode1Rotor() 
    {
        std::string messageDecode = "";
        std::string cleTemp = _cleChiffrement;
        for(int i=0; i<=_cipher.size()-1; i++)
        {
            int j = 0;
            while(_cipher.at(i) != cleTemp.at(j))
            {
                j += 1;
            }
            messageDecode += _alphabet.at(j);
            cleTemp = decalageStringGauche(cleTemp);
        }
        return messageDecode;
    }*/

    std::string const Enigma::decode2Rotor() 
    {
        std::string messageDecode = "";
        std::string cleTemp = _cleChiffrement;
        std::string cleTemp2 = _cleChiffrement2;
        int j = 0;
        int k = 0;
        for(int i=0; i<=_cipher.size()-1; i++)
        {
            int nb = _cipher.at(i)-97;
            int nbCle1 = cleTemp.at(j)-97;
            int nbCle2 = cleTemp2.at(k)-97;
            int nbCode1 = (nb - nbCle1) % 26;
            if(nbCode1 < 0)
            {
                nbCode1 = 26 - (-nbCode1);
            }
            int nbCode2 = (nbCode1 - nbCle2) % 26;
            if(nbCode2 < 0)
            {
                nbCode2 = 26 - (-nbCode2);
            }
            char lettreCode = char(nbCode2+97);
            j = (j+1) % cleTemp.size();
            if(j == 0)
            {
                k = (k+1) % cleTemp.size();
            }
            messageDecode += lettreCode;
        }
        return messageDecode;
 
    }

    std::string const Enigma::encode()
    {
        //return vigenereCode(_plain, _cleChiffrement);
        return encode2Rotor();
    }

    /*std::string const Enigma::encode1Rotor()
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
        return messageEncode;
    }*/

    std::string const Enigma::encode2Rotor()
    {
        std::string messageEncode = "";
        std::string cleTemp = _cleChiffrement;
        std::string cleTemp2 = _cleChiffrement2;
        int j = 0;
        int k = 0;
        for(int i=0; i<=_plain.size()-1; i++)
        {
            int nb = _plain.at(i)-97;
            int nbCle1 = cleTemp.at(j)-97;
            int nbCle2 = cleTemp2.at(k)-97;
            
            int nbCode1 = (nb + nbCle1) % 26;
            int nbCode2 = (nbCode1 + nbCle2) % 26;
            char lettreCode = char(nbCode2+97);
            j = (j+1) % cleTemp.size();
            if(j == 0)
            {
                k = (k+1) % cleTemp.size();
            }
            messageEncode += lettreCode;
        }
        return messageEncode;


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

    std::string vigenereCode(std::string message, std::string cle)
    {
        std::string messageEncode = "";
        //std::string cleTemp = _cleChiffrement;
        int j = 0;
        for(int i=0; i<=message.size()-1; i++)
        {
            int nb = message.at(i)-97;
            int nbCle = cle.at(j)-97;
            int nbCode = (nb + nbCle) % 26;
            char lettreCode = char(nbCode+97);
            j = (j+1) % cle.size();
            messageEncode += lettreCode;
            //std::cout << (int)lettreCode << std::endl;
        }
        return messageEncode;
    }

    std::string vigenereDecode(std::string message, std::string cle)
    {
        std::string messageEncode = "";
        int j = 0;
        for(int i=0; i<=message.size()-1; i++)
        {
            int nb = message.at(i)-97;
            int nbCle = cle.at(j)-97;
            int nbCode = (nb - nbCle) % 26;
            if(nbCode < 0)
            {
                nbCode = 26 - (-nbCode);
            }
            char lettreCode = char(nbCode+97);
            //std::cout << nbCode  << std::endl;
            j = (j+1) % cle.size();
            messageEncode += lettreCode;
        }
        return messageEncode;
    }

}