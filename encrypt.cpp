#include "encrypt.h"
#include <iostream>

namespace Crypt{

	/*Encrypt::Encrypt(std::string plain) 
		: _plain(plain){}*/

	Encrypt::Encrypt(std::string cheminFichier) 
	{
		_plain = read(cheminFichier);
	}

	std::string Encrypt::getPlain()
	{
		return _plain;
	}

	std::string Encrypt::getCipher()
	{
		return _cipher;
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
