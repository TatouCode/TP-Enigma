#include <string>
#include "encrypt.h"

namespace Crypt{

    class Enigma : public Encrypt{
        public:
            Enigma();
            Enigma(std::string const cheminFichierLecture, std::string const cheminFichierEcriture);
            void const decode() override;
		    void const encode() override;

        private:
            std::string _cleChiffrement; 
            std::string const _alphabet = "abcdefghijklmnopqrstuvwxyz";
    };

    std::string melangeString(std::string message);
    std::string decalageStringGauche(std::string message);
    std::string decalageStringDroit(std::string message);

}
