#include <string>
#include <fstream>

namespace Crypt{

class Encrypt {
public:
	Encrypt(string const _nomFichierRead, string const _nomFichierWrite, string _plain, string _cipher);
	std::string plain();
	std::string cipher();
	std::string const read(string const _nomFichier);
	std::string const write(string const _nomFichier);
	virtual std::string const decode(string const _nomFichier) = 0;
	virtual std::string const encode(string const _nomFichier) = 0;

private:
	string const _nomFichierRead;
	string const _nomFichierWrite;

protected:
	string _plain;
	string _cipher;


}

}