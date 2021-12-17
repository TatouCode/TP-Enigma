#include "encrypt.h"
#include <iostream>
#include <algorithm>
#include <cctype>

namespace Crypt{

	Encrypt::Encrypt(std::string const cheminFichierLecture, std::string const cheminFichierEcriture)
		: _cheminFichierLecture(cheminFichierLecture), _cheminFichierEcriture(cheminFichierEcriture)
	{
		_plain = read(_cheminFichierLecture);
	}

	Encrypt::Encrypt() {}

	std::string Encrypt::getPlain()
	{
		return _plain;
	}

	void Encrypt::setPlain(std::string plain)
	{
		_plain = plain;
	}

	std::string Encrypt::getCipher()
	{
		return _cipher;
	}

	void Encrypt::setCipher(std::string cipher)
	{
		_cipher = cipher;
	}

	std::string const read(std::string const cheminFichier)
	{
		std::ifstream monFlux(cheminFichier);
		std::string ligne;
		std::string message = "";
		if(monFlux)
   		{ 
      		while(getline(monFlux, ligne)) 
      		{
				std::transform(ligne.begin(), ligne.end(),
				ligne.begin(), [](unsigned char c){return std::tolower(c);});
				message += ligne;
      		}
   		}
   		else
   		{
      		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;

   		}
		return message;
	}

	void const write(std::string const cheminFichier, std::string const message)
	{
		std::ofstream monFlux(cheminFichier.c_str());
		if(monFlux) 
		{
			monFlux << message << std::endl;
		}
		else
		{
				std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
		}
	}
}
