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
#include "liste.h"	//

using namespace std;

maillon::maillon(string A , matrice B)
{
	name=A;
	mat=B;
}
liste::liste()
{
	tete=NULL;
	queue=NULL;
}

void liste::ajoute(string A,matrice B)
{
	if (tete==NULL)
	{
		maillon *C=new maillon(A,B);
		tete=C;
		queue=C;
	}
	else
	{
		queue->suiv=new maillon(A,B);
		queue=queue->suiv;
	}
}

