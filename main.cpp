#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "libb.h"

using namespace std;


int main() {
	cout<<endl;
/*--------------test ajout--------------*/
	/*matrice A ("A",10,10);
	A.ajout(1,2,3);
	A.ajout(4,5,6);
	A.ajout(1,2,4);
	
	A.affiche();*/

/*-----------------test addition/soustraction mat---------*/
	/*matrice A ("A",10,10);
	matrice B ("B",10,10);
	A.ajout(1,2,3);
	A.ajout(4,5,6);
	B.ajout(4,5,7);
	B.ajout(7,8,9);
	A.affiche();
	B.affiche();
	A.addition(B);
	A.affiche();
	matrice C ("C",10,10);
	C.ajout(1,2,4);
	C.ajout(7,8,5);
	C.affiche();
	A.soustraction(C);
	A.affiche();*/

/*-----------------test mult mat---------*/
	matrice A ("A",3,3);
	matrice B ("B",3,3);
	A.ajout(1,1,2);
	A.ajout(2,1,2);
	B.ajout(1,1,2);
	B.ajout(1,2,2);
	A.affiche();
	B.affiche();
	matrice C=A.multiplication(B);
	C.affiche();
	C=C.carre();
	C.affiche();

  return 0;
}	
