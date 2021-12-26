#include <string>
#include "encrypt.h"

namespace Crypt{

    class Enigma : public Encrypt{
        public:
            Enigma();
            Enigma(std::string const cheminFichierLecture, std::string const cheminFichierEcriture);
            std::string const decode() override;
		    std::string const encode() override;

        private:
            std::string _cleChiffrement;
            std::string _cleChiffrement2; 
            std::string const _alphabet = "abcdefghijklmnopqrstuvwxyz";
            /*std::string const encode1Rotor();
            std::string const decode1Rotor();*/
            std::string const encode2Rotor();
            std::string const decode2Rotor();
    };

    std::string melangeString(std::string message);
    //std::string decalageStringGauche(std::string message);
    //std::string decalageStringDroit(std::string message);
    std::string vigenereCode(std::string message, std::string cle);
    std::string vigenereDecode(std::string message, std::string cle);

}
