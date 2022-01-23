/**
 * @file Enigma.h
 * @author Lucas 
 * @author Benjamin
 * @brief Fichier qui contient une classe représentant Enigma 
 * @version 1.0
 * @date 2022-01-04
 * 
 */

#include <string>
#include "encrypt.h"

namespace Crypt{

/**
 * @brief La classe Enigma hérite de Encrypt
 * 
 */
    class Enigma : public Encrypt{
        public:
            Enigma();

            /**
             * @brief Construit un nouvel objet Enigma avec les fichiers lecture/ecriture en paramètre
             * 
             * @param cheminFichierLecture chemin vers le fichier de lecture
             * @param cheminFichierEcriture chemin vers le fichier d'écriture
             */
            Enigma(std::string const cheminFichierLecture, std::string const cheminFichierEcriture);

            /**
             * @brief Fonction hérité de Encrypt qui decode à la façon d'Enigma
             * 
             * @return std::string const le message décodé
             */
            std::string const decode() override;

            /**
             * @brief Fonction hérité de Encrypt qui encode à la façon d'Enigma
             * 
             * @return std::string const le message encodé
             */
		    std::string const encode() override;

        private:
            std::string _cleChiffrement; // 1 rotor
            std::string _cleChiffrement2; // 2 rotor
            std::string const _alphabet = "abcdefghijklmnopqrstuvwxyz";

            /**
             * @brief code le message avec 2 rotors
             * 
             * @return std::string const 
             */
            std::string const encode2Rotor();

            /**
             * @brief decode le message avec 2 rotors
             * 
             * @return std::string const 
             */
            std::string const decode2Rotor();
    };

    /**
     * @brief Mélange le message passé en paramètre
     * 
     * @param message message à mélanger
     * @return std::string 
     */
    std::string melangeString(std::string message);

    /**
     * @brief code le message avec l'algorithme de Vigenère
     * 
     * @param message message à coder
     * @param cle cle pour l'algorithme de Vigenère
     * @return std::string 
     */
    std::string vigenereCode(std::string message, std::string cle);

    /**
     * @brief decode le message avec l'algorithme de Vigenère
     * 
     * @param message message à decoder
     * @param cle cle pour l'algorithme de Vigenère
     * @return std::string 
     */
    std::string vigenereDecode(std::string message, std::string cle);

}
