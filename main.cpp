#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "test.h"

using namespace std;


int main() {
	matrice A;
	matrice B;
	A.ajout(1,2,3);
	A.ajout(4,5,6);
	B.ajout(4,5,6);
	B.ajout(7,8,9);
	A.affiche();
	B.affiche();
	A.addition(B);
	A.affiche();
}
