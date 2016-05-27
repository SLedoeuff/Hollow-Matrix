//!
//! \file libb.h
//! \brief regroupe les fonctions matricielles
//! \author DEMOGUE Bruno, HUOT Amaury, LE DOEUFF Sacha, BASTIDE Anthony
//! \version 1.0
//!
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <map>
#ifndef _lib
#define _lib




using namespace std;

//!
//! \class lcv
//! \brief élément de type ligne-colonne-valeur
//!
//!  Permet de remplir des listes contenant des matrices creuses, on ne garde de celle ci
//!  que ces coordonnées, ligne et colonne, ainsi que sa valeur différente de 0.
//!
class lcv
{
	private:
		int li;
		int co;
		int val;
		lcv* suiv;
      		friend class matrice;
      		friend class app;
      		friend class liste;

	public:
//!
//! \fn lcv::lcv()
//! \brief constructeur avec argument d'un element de type lcv
//!
//! \param int: ligne de l'element, int: colonne de l'element, int: valeur de l'element
//! \return Aucun
//!
		lcv(int,int,int);
		
		
};

//!
//! \class matrice
//! \brief liste des elements d'une matrice creuse, une liste de lcv
//!
//!  Pour ranger les elements d'une matrice creuse et ne garder que les valeurs différentes de 0
//!
class matrice
{
	private:
		string name;
		int largeur;
		int hauteur;
		lcv *tete;
      		friend class maillon;
      		friend class app;
      		friend class liste;

	public:
//!
//! \fn matrice(string,int,int);
//! \brief constructeur avec arguments d'une matrice
//!
//! \param string: nom de la matrice, int:hauteur de la matrice, int: largeur de la matrice
//! \return Aucun
//!
		matrice(string,int,int);
		
//!
//! \fn matrice();
//! \brief constructeur par defaut d'une matrice
//!
//! \param Aucun
//! \return Aucun
//!
		matrice();
		
//!
//! \fn void action(int,int,int,string);
//! \brief ajoute un element à la matrice
//!
//! \param int:valeur à ajouter à la matrice, int:ligne d'ajout, int:colonne d'ajout, string: nom de l'operation à effectuer
//! \return Aucun
//!
		void action(int,int,int,string);
		
//!
//! \fn void ajout(int,int,int);
//! \brief appelle la fonction action, pour ajouter un element a la matrice
//!
//! \param int:valeur à ajouter à la matrice, int:ligne d'ajout, int:colonne d'ajout
//! \return Aucun
//!
		void ajout(int,int,int);
		
//!
//! \fn void affiche();
//! \brief Affiche le contenu d'une matrice
//!
//! \param Aucun
//! \return Aucun
//!
		void affiche();
		
//!
//! \fn void addition(matrice);
//! \brief permet d'additionner deux matrices
//!
//! \param matrice: la deuxième matrice à additionner
//! \return Aucun, le resultat va remplacer l'objet (matrice) appellant la fonction
//!
		void addition(matrice);
		
//!
//! \fn void soustraction(matrice);
//! \brief permet de soustraire deux matrices
//!
//! \param matrice: la deuxième matrice à soustraire
//! \return Aucun, le resultat va remplacer l'objet (matrice) appellant la fonction
//!
		void soustraction(matrice);
		
//!
//! \fn matrice multiplication(matrice);
//! \brief prmet de multiplier deux matrices
//!
//! \param matrice: la deuxième matrice à multiplier
//! \return Un resultat de type matrice
//!
		matrice multiplication(matrice);
		
//!
//! \fn matrice carre();
//! \brief appelle la fonction multiplication sur elle même pour faire le carré d'une matrice
//!
//! \param Aucun
//! \return Un resultat de type matrice
//!
		matrice carre();
		
//!
//! \fn void transposition();
//! \brief fait la transposé d'une matrice
//!
//! \param Aucun
//! \return Aucun
//!
		void transposition();
		

//!
//! \fn void lecture(string);
//! \brief permet de récupéré une matrice enregistré sur un document texte (.txt)
//!
//! \param string: nom du fichier
//! \return Aucun
//!
		void lecture(string);
		
//!
//! \fn void ecriture(string);
//! \brief permet d'enregistrer une matrice dans un document texte (.txt)
//!
//! \param string: nom du fichier
//! \return Aucun
//!
		void ecriture(string);
		
//!
//! \fn void remplir_test();
//! \brief Prépare une batterie de test des fonctionnalités de la librairie en remplissant au préalable une matrice avec des valeurs
//!
//! \param Aucun
//! \return Aucun
//!
		void remplir_test();
		
//!
//! \fn void battery_test();
//! \brief Effectue une batterie de test afin de voir le fonctionnement des opérations matricielles
//!
//! \param Aucun
//! \return Aucun
//!
		void battery_test();
		
};


#endif
