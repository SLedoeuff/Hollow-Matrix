#include <iostream>	//
#include <math.h>	//
#include <stdlib.h>	//
#include <string>	//
#include <string.h>	//
#include <fstream>	//
#include <iomanip>	//
#include <cstdlib>	//
#include <typeinfo>	//
#include <map>          //
#ifndef _lib
#define _lib

using namespace std;


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
		lcv(int,int,int);
		lcv();
		
		
};

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
		matrice(string,int,int);
		matrice();
		void action(int,int,int,string);
		void ajout(int,int,int);
		void affiche();
		void addition(matrice);
		void soustraction(matrice);
		matrice multiplication(matrice);
		matrice carre();
		void transposition();


		void lecture();
		void ecriture();
		
		
};


#endif
