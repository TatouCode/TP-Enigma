#include <string>
#include <fstream>

namespace Crypt{

class Encrypt {
public:
	Encrypt(std::string const _nomFichierRead, std::string const _nomFichierWrite, std::string _plain, std::string _cipher);
	std::string getPlain();
	std::string getCipher();
	std::string const read(std::string const _nomFichier);
	std::string const write(std::string const _nomFichier);
	virtual std::string const decode(std::string const _nomFichier) = 0;
	virtual std::string const encode(std::string const _nomFichier) = 0;

private:
	std::string const _nomFichierRead;
	std::string const _nomFichierWrite;

protected:
	std::string _plain;
	std::string _cipher;


}

}
