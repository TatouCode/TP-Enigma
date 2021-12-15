#include <string>

namespace Crypt{

    class Enigma : public Encrypt{
        public:
            Enigma(std::string cheminFichier);
            std::string const decode(std::string const nomFichier) override;
		    std::string const encode(std::string const nomFichier) override;

        private:
            std::string _cleChiffrement; 
            std::string initCle();
    };

}
