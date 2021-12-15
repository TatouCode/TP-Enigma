#include <string>
#include <fstream>

namespace Crypt{

class Encrypt {
	public:
		Encrypt(std::string plain);
		Encrypt(std::string fichier);
		std::string getPlain();
		std::string getCipher();
		virtual std::string const decode(std::string const nomFichier) = 0;
		virtual std::string const encode(std::string const nomFichier) = 0;

	/*private:
		std::string const _nomFichierRead;
		std::string const _nomFichierWrite;*/

	protected:
		std::string _plain;
		std::string _cipher;
};

	std::string const read(std::string const nomFichier);
	void const write(std::string const nomFichier, std::string const message);

}
