#include "encrypt.h"
#include <iostream>

namespace Crypt{

Encrypt::Encrypt(std::string const _nomFichierRead, std::string const _nomFichierWrite, std::string _plain, std::string _cipher) {
	: _nomFichierRead(nomFichierRead), FichierWrite(nomFichierWrite) _plain(plain), _cipher(cipher)
}

	std::string Encrypt::getPlain(){

		std::ifstream fichier(_nomFichierWrite);
		if(fichier)

   		{
      		std::string ligne; 
      			while(getline(fichier, ligne)) 
      		{

        	 std::cout << ligne << std::endl;
      		}

   		}

   		else

   		{

      		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;

   		}

	}

	std::string Encrypt::getCipher(){

		std::ifstream fichier(_nomFichierRead);
		if(fichier)

   		{


      		std::string ligne; 
      		while(getline(fichier, ligne)) 

      		{

         		std::cout << ligne << std::endl;
      		}

   		}

   		else

   		{

      		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;

   		}

	}


	std::string const Encrypt::read(std::string const _nomFichier){

		std::ifstream fichier(_nomFichierRead);
		if(fichier)

   		{


      		std::string ligne; 
      		while(getline(fichier, ligne)) 

      		{

         		std::cout << ligne << std::endl;
      		}

   		}

   		else

   		{

      		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;

   		}
	}

	std::string const Encrypt::write(std::string const _nomFichier){

			std::ofstream monFlux(_nomFichierWrite.c_str());
			if(monFlux) 

			{
				std::cin >> monFlux;

			}

			else

			{

   				 std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;

			}
	}

}
