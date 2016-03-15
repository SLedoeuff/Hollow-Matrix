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
		lcv *tete;

	public:
		matrice(string);
		void ajout(int,int,int,string);
		void affiche();
		void addsous(int,int,int);
		void addition(matrice);
		void soustraction(matrice);
		void multiplication(matrice);
		//void carre();
		void transposition();


		void lecture();
		void ecriture();
		
		
};


#endif
