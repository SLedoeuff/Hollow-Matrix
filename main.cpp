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
	/*matrice A ("A");
	A.ajout(1,2,3,"ajj");
	A.ajout(4,5,6,"ajj");
	A.ajout(1,2,4,"ajj");
	
	A.affiche();*/

/*-----------------test addition/soustraction mat---------*/
	matrice A ("A");
	matrice B ("B");
	A.ajout(1,2,3,"ajj");
	A.ajout(4,5,6,"ajj");
	B.ajout(4,5,7,"ajj");
	B.ajout(7,8,9,"ajj");
	A.affiche();
	B.affiche();
	A.addition(B);
	A.affiche();
	matrice C ("C");
	C.ajout(1,2,4,"ajj");
	C.ajout(7,8,5,"ajj");
	C.affiche();
	A.soustraction(C);
	A.affiche();
  return 0;
}	

