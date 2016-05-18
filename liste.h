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
#include "libb.h"
#ifndef _liste
#define _liste

using namespace std;


class maillon
{
	private:
		string name;
		matrice mat;
		maillon* suiv;
      		friend class liste; 
      		friend class app;
      		friend class libb;

	public:
		maillon(string,matrice);
		
		
};

class liste
{
	private:
		maillon*tete;
		maillon*queue;
      		friend class app;
      		friend class libb;

	public:
		liste();
		void ajoute(string,matrice);
		
		
};


#endif
