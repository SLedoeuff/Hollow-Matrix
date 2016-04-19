#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
//#include <iomanip>
#include <cstdlib>
#include "libb.h"

using namespace std;

void matrice::ecriture() //on appelle cette fonction lorsque l'utilisateur ne met pas d'argument lors de l'appel du programme, il choisira son nom de fichier dnas le programme.
{
	string nom;
	cout << "Entrez le nom du fichier de sauvegarde. si un fichier du meme nom existe, il sera perdu"<<endl;
	cin >> nom;

	ofstream fichier( "nom.txt" , ios::out | ios::trunc);
	if(fichier)
	{
		lcv *tmp=tete;
		fichier << largeur << ' ' << hauteur << ' ' << name;
		while(tmp->suiv!=NULL){
			fichier << ' ' << tmp->li << ' ' << tmp->co << ' ' << tmp->val;
			tmp=tmp->suiv;
		}
		fichier.close();
		cout << "sauvegarde effectuée" << endl;
	}
	else
	{
		cerr << "erreur !" << endl;
	}
}

void matrice::lecture()
{
	ifstream fichier( "nom.txt" , ios::in);
	if(fichier)
	{
		lcv *tmp=tete;
		fichier >> largeur;
		fichier >> hauteur;	
		fichier >> name;
		while(fichier){
			fichier >> tmp->li;
			fichier >> tmp->co;
			fichier >> tmp->val;
			tmp=tmp->suiv;
		}
		fichier.close();
		cout << "chargement effectuer effectuée" << endl;
	}
	else
	{
		cerr << "erreur !" << endl;
	}
}

int main()
{
	cout << "ma bite" << endl;
}
