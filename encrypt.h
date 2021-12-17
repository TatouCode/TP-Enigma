#include <string>
#include <fstream>

namespace Crypt{

class Encrypt {
	public:
		Encrypt();
		Encrypt(std::string const cheminFichierLecture, std::string const cheminFichierEcriture);
		std::string getPlain();
		std::string getCipher();
		void setPlain(std::string plain);
		void setCipher(std::string cipher);
		virtual void const decode() = 0;
		virtual void const encode() = 0;

	protected:
		std::string _plain;
		std::string _cipher;
		std::string const _cheminFichierLecture = "plain.txt";
		std::string const _cheminFichierEcriture = "cipher.txt";

};

	std::string const read(std::string const nomFichier);
	void const write(std::string const nomFichier, std::string const message);

}
