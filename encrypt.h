/**
 * @file encrypt.h
 * @author Lucas 
 * @author Benjamin
 * @brief Fichier qui représente une classe abstraite de chiffrement
 * @version 1.0
 * @date 2022-01-04
 * 
 */

#include <string>
#include <fstream>

namespace Crypt{

class Encrypt {
	public:

		Encrypt();

		/**
		 * @brief Construit un nouvel objet Encrypt avec en paramètre les fichiers de lecture/écriture
		 * 
		 * @param cheminFichierLecture chemin vers le fichier de lecture
		 * @param cheminFichierEcriture chemin vers le fichier d'écriture
		 */
		Encrypt(std::string const cheminFichierLecture, std::string const cheminFichierEcriture);
		
		std::string getPlain();
		std::string getCipher();
		void setPlain(std::string plain);
		void setCipher(std::string cipher);
		
		/**
		 * @brief fonction purement virtuel pour décoder un code 
		 * 
		 * @return std::string const 
		 */
		virtual std::string const decode() = 0;
		
		/**
		 * @brief fonction purement virtuel pour encoder un code 
		 * 
		 * @return std::string const 
		 */
		virtual std::string const encode() = 0;

	protected:

		std::string _plain;
		std::string _cipher;

		std::string const _cheminFichierLecture = "plain.txt";
		std::string const _cheminFichierEcriture = "cipher.txt";

};

	/**
	 * @brief Fonction helper qui permet de lire un fichier texte
	 * 
	 * @param nomFichier nom du fichier a lire
	 * @return std::string const 
	 */
	std::string const read(std::string const nomFichier);

	/**
	 * @brief Fonction helper qui permet d'écrire dans un fichier
	 * 
	 * @param nomFichier nom du fichier à écrire
	 * @param message message à écrire dans le fichier
	 */
	void const write(std::string const nomFichier, std::string const message);

}	
