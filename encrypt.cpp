#include "encrypt.h"

namespace Crypt{

Encrypt::Encrypt(string const _nomFichierRead, string const _nomFichierWrite, string _plain, string _cipher) {
	: _nomFichierRead(nomFichierRead), FichierWrite(nomFichierWrite) _plain(plain), _cipher(cipher)
}

	std::string Encrypt::plain(){

		ifstream fichier(_nomFichierWrite)
		if(fichier)

   		{
      		string ligne; 
      			while(getline(fichier, ligne)) 
      		{

        	 cout << ligne << endl;
      		}

   		}

   		else

   		{

      		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

   		}

	}

	std::string Encrypt::cipher(){

		ifstream fichier(_nomFichierRead)
		if(fichier)

   		{


      		string ligne; 
      		while(getline(fichier, ligne)) 

      		{

         		cout << ligne << endl;
      		}

   		}

   		else

   		{

      		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

   		}

	}


	std::string const Encrypt::read(string const _nomFichier){

		ifstream fichier(_nomFichierRead)
		if(fichier)

   		{


      		string ligne; 
      		while(getline(fichier, ligne)) 

      		{

         		cout << ligne << endl;
      		}

   		}

   		else

   		{

      		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

   		}
	}

	std::string const Encrypt::write(string const _nomFichier){

			ofstream monFlux(_nomFichierWrite.c_str());
			if(monFlux) 

			{
				std::cin >> monFlux;

			}

			else

			{

   				 cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;

			}
	}

}