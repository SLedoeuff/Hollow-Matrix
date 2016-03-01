#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#ifndef _test
#define _test

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
		lcv *tete;

	public:
		matrice();
		void ajout(int,int,int);
		void affiche();
		void addition(matrice);
		void soustraction();
		void multiplication();
		//void carré();
		void transposition();


		void lecture();
		void ecriture();
		
		
};


#endif
