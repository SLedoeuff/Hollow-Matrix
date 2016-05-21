//!
//! \file libb.cpp
//! \brief fonctions qui permet d'effectuer les calculs matriciels
//! \author DEMOGUE Bruno, HUOT Amaury, LE DOEUFF Sacha, BASTIDE Anthony
//! \version 1.0
//!
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include "libb.h"
//
using namespace std;

lcv::lcv(int x,int y,int z)
{
	li=x;
	co=y;
	val=z;
	suiv=NULL;
}


matrice::matrice(string nom,int x,int y)
{
	hauteur=y;
	largeur=x;
	name=nom;
	tete=NULL;
}

matrice::matrice()
{
	hauteur=0;
	largeur=0;
	name=" ";
	tete=NULL;
}


void matrice::action(int x,int y,int z,string act)
{
	if(tete==NULL)
	{
		lcv *B=new lcv(x,y,z);
		tete=B;
		if(act=="ajj")/*cout<<"Ajout de la valeur "<<z<<" a la position ("<<x<<"."<<y<<") dans la matrice "<<this->name<<endl*/;
		
		return;
	}
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		if(temp->li==x && temp->co==y)
		{
			if(act=="ajj")/*cerr<<"Erreur il y a deja la valeur "<<temp->val<<" a la position ("<<temp->li<<"."<<temp->co<<") , impossible d ajouter la valeur dans la matrice "<<this->name<<z<<endl*/;
			else if(act=="add")
			{
				temp->val=temp->val+z;
			}
			return;
		}
		temp=temp->suiv;
	}
	if(temp->li==x && temp->co==y)
	{
		if(act=="ajj")/*cerr<<"Erreur il y a deja la valeur "<<temp->val<<" a la position ("<<temp->li<<"."<<temp->co<<") , impossible d ajouter la valeur dans la matrice "<<this->name<<z<<endl*/;
		else if(act=="add")
		{
			temp->val=temp->val+z;
		}
		return;
	}
	lcv* B=new lcv (x,y,z);
	temp->suiv=B;
	if(act=="ajj")/*cout<<"Ajout de la valeur "<<z<<" a la position ("<<x<<"."<<y<<") dans la matrice "<<this->name<<endl*/;
	
}

void matrice::affiche()
{
	cout<<endl<<"matrice "<<this->name<<endl;
	cout<<setw(10)<<right<<"ligne"<<setw(10)<<right<<"colonne"<<setw(10)<<right<<"valeur"<<endl;
	if(tete==NULL){
	cout<<"matrice vide"<<endl;
	return;
	}
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		if(temp->val!=0)
		{
			cout<<setw(10)<<right<<temp->li<<setw(10)<<right<<temp->co<<setw(10)<<right<<temp->val<<endl;
			temp=temp->suiv;
		}
	}
	cout<<setw(10)<<right<<temp->li<<setw(10)<<right<<temp->co<<setw(10)<<right<<temp->val<<endl;
	cout<<endl;

}
void matrice::ajout(int x,int y,int z)
{
	if(z==0)
	{
		cout<<"ajout de 0 inutile dans la matrice"<<endl;
		return;
	}
	if(x<=largeur && y<=hauteur)
	{
		action(x,y,z,"ajj");
	}
	else
	{
		cout<<"Erreur coordonnées hors matrice ("<<x<<","<<y<<")"<<endl;
	}
	
}


void matrice::addition(matrice B)
{
	if(hauteur==B.hauteur && largeur ==B.largeur)
	{
		lcv* temp=B.tete;
		while(temp->suiv!=NULL)
		{
			action(temp->li,temp->co,temp->val,"add");
			temp=temp->suiv;
		}
		action(temp->li,temp->co,temp->val,"add");
	}
	else
	{
		cout<<"Erreur les deux matrice doivent avoir des tailles identique"<<endl;
	}
}


void matrice::soustraction(matrice B)
{	
	if(hauteur==B.hauteur && largeur ==B.largeur)
	{
		lcv* temp=B.tete;
		while(temp->suiv!=NULL)
		{
			action(temp->li,temp->co,-(temp->val),"add");
			temp=temp->suiv;
		}
		action(temp->li,temp->co,-(temp->val),"add");
	}
	else
	{
		cout<<"Erreur les deux matrice doivent avoir des tailles identique"<<endl;
	}
}



matrice matrice::multiplication(matrice B)
{
	if(largeur==B.hauteur)
	{
		matrice res ("res",hauteur,B.largeur);
		lcv* temp=tete;
		while(temp->suiv!=NULL)
		{
			lcv* temp2=B.tete;
			while(temp2->suiv!=NULL)
			{
				if(temp2->li==temp->co)
				{
					res.action(temp->li,temp2->co,(temp->val*temp2->val),"add");
				}
				temp2=temp2->suiv;
			}
			if(temp2->li==temp->co)
			{
				res.action(temp->li,temp2->co,(temp->val*temp2->val),"add");
			}
			temp=temp->suiv;
		}

		lcv* temp2=B.tete;
		while(temp2->suiv!=NULL)
		{
			if(temp2->li==temp->co)
			{
				res.action(temp->li,temp2->co,(temp->val*temp2->val),"add");
			}
			temp2=temp2->suiv;
		}
		if(temp2->li==temp->co)
		{
			res.action(temp->li,temp2->co,(temp->val*temp2->val),"add");
		}
		return res;
	}
	else
	{
		cout<<"Erreur la hauteur de la premiere matrice doit etre egal a la largeur de la deuxieme"<<endl;
	}

}



matrice matrice::carre()
{
	return multiplication(*this);
	
}
void matrice::transposition()
{
    int a;
    lcv * tmp = tete;
    a=tmp->li;
    tmp->li=tmp->co;
    tmp->co=a;
    while(tmp->suiv!=NULL)
    {
     	tmp=tmp->suiv;
        a=tmp->li;
        tmp->li=tmp->co;
      	tmp->co=a;
    }
}

void matrice::ecriture(string c)
{
	char * d = new char [c.length()+1];
 	strcpy (d, c.c_str());
	cout<<d<<endl;
	ofstream fichier(d  , ios::out | ios::trunc);
	if(fichier)
	{
		lcv *tmp=tete;
		fichier << largeur << ' ' << hauteur << ' ' << name;
		int i=0;
		while(tmp->suiv!=NULL){
			cout<<i<<endl;
			fichier << ' ' << tmp->li << ' ' << tmp->co << ' ' << tmp->val;
			tmp=tmp->suiv;
			i++;
		}
		fichier << ' ' << tmp->li << ' ' << tmp->co << ' ' << tmp->val;
		fichier.close();
		cout << "sauvegarde effectuée" << endl;
	}
	else
	{
		cerr << "erreur !" << endl;
	}
	cout<<"ok"<<endl;
}

void matrice::lecture(string c)
{
	char * d = new char [c.length()+1];
 	strcpy (d, c.c_str());
	ifstream fichier( d , ios::in);
	if(fichier)
	{
		fichier >> largeur;
		fichier >> hauteur;	
		fichier >> name;
		cout<<"1"<<endl;
		int x,y,z;
		while(fichier){
			fichier >> x;
			fichier >> y;
			fichier >> z;
			ajout(x,y,z);
		}
		cout<<"1"<<endl;
		fichier.close();
		cout << "chargement effectué" << endl;
	}
	else
	{
		cerr << "erreur !" << endl;
	}
}

void matrice::remplir_test()
{
	for(int i=0;i<=8000;i++)
	{
		int j=i;
		ajout(i,j,4);
	}
}

void matrice::battery_test()
{
	cout<<"Initialisation du test"<<endl;
	getchar();
	matrice D("D",8000,8000);
	cout<<"Declaration matrice n°1 éffectuée"<<endl;
	getchar();
	matrice E("E",8000,8000);
	cout<<"Declaration matrice n°2 éffectuée"<<endl;
	getchar();
	D.remplir_test();
	cout<<"Remplissage de la matrice n°1 éffectuée"<<endl;
	getchar();
	E.remplir_test();
	cout<<"Remplissage de la matrice n°2 éffectuée"<<endl;
	getchar();	
	matrice F=D.multiplication(E);
	cout<<"Multiplication des deux matrice et stockage dans matrice n°3 éffectuée"<<endl;
	getchar();	
	D.addition(E);
	cout<<"Addition de la matrice n°2 à la matrice n°1 éffectuée"<<endl;
	getchar();	
	//F.ecriture();
	cout<<"Ecriture dans un fichier de la matrice n°3 éffectuée"<<endl;
	getchar();	
	//F.lecture();
	cout<<"Lecture à partir d'un fichier de la matrice n°3 éffectuée"<<endl;
	getchar();	
	F.affiche();
	cout<<"Affichage de la matrice n°3 (multiplication de matrice 1 et 2) éffectué"<<endl;
	getchar();
	D.affiche();
	cout<<"Affichage de la matrice n°1 éffectué"<<endl;
	getchar();
	D.soustraction(E);
	cout<<"Soustraction de la matrice n°2 à la matrice n°1 éffectuée"<<endl;
	getchar();	
	D.affiche();
	cout<<"Affichage de la matrice n°1 éffectué"<<endl;
	getchar();	
	matrice I=D.carre();
	cout<<"Declaration de la matrice n°4 comme étant le carre de la matrice n°1 éffectuée"<<endl;
	getchar();	
	I.affiche();
	cout<<"Affichage de la matrice n°4 éffectué"<<endl;
	getchar();	
	matrice H("H",50,50);
	for(int i=0;i<=49;i++)
	{
		int j=i+1;
		H.ajout(i,j,4);
	}
	cout<<"Declaration et remplissage de la matrice n°5 éffectuée"<<endl;
	getchar();	
	H.affiche();
	cout<<"Affichage de la matrice n°5 éffectué"<<endl;
	getchar();	
	H.transposition();
	cout<<"Transposition de la matrice n°5 éffectuée"<<endl;
	getchar();	
	H.affiche();
	cout<<"Affichage de la matrice H après transposition effectué"<<endl;
}
