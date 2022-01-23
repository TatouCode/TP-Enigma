/**
 * @file encrypt.cpp
 * @author Lucas
 * @author Benjamin
 * @brief Implémente les fonctions de encrypt.h
 * @version 1.0
 * @date 2022-01-04
 * 
 */

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
				ligne.erase(std::remove(ligne.begin(), ligne.end(), ' '), ligne.end());
				std::transform(ligne.begin(), ligne.end(),
				ligne.begin(), [](unsigned char c){return std::tolower(c);});
				message += ligne;
      		}
			// Efface les caractères indésirables
			for(int i=0; i<message.size()-1; i++)
			{
				if((int)message.at(i)<97 || (int)message.at(i)>122)
				{
					message.erase(i, 1);
				}
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
