#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
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

	public:
		lcv(int,int,int);
		
		
};

class matrice
{
	private:
		string name;
		int largeur;
		int hauteur;
		lcv *tete;

	public:
		matrice(string,int,int);
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
		void remplir_test();
		void battery_test();
		
		
};


#endif
