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

using namespace std;

lcv::lcv(int x,int y,int z)
{
	li=x;
	co=y;
	val=z;
	suiv=NULL;
}


matrice::matrice(string nom)
{
	name=nom;
	tete=NULL;
}


void matrice::ajout(int x,int y,int z,string action)
{
	if(tete==NULL)
	{
		lcv *B=new lcv(x,y,z);
		tete=B;
		if(action=="ajj")cout<<"Ajout de la valeur "<<z<<" a la position ("<<x<<"."<<y<<") dans la matrice "<<this->name<<endl;
		return;
	}
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		if(temp->li==x && temp->co==y)
		{
			if(action=="ajj")cerr<<"Erreur il y a deja la valeur "<<temp->val<<" a la position ("<<temp->li<<"."<<temp->co<<") , impossible d ajouter la valeur dans la matrice "<<this->name<<z<<endl;
			else if(action=="add")
			{
				temp->val=temp->val+z;
			}
			return;
		}
		temp=temp->suiv;
	}
	if(temp->li==x && temp->co==y)
	{
		if(action=="ajj")cerr<<"Erreur il y a deja la valeur "<<temp->val<<" a la position ("<<temp->li<<"."<<temp->co<<") , impossible d ajouter la valeur dans la matrice "<<this->name<<z<<endl;
		else if(action=="add")
		{
			temp->val=temp->val+z;
		}
		return;
	}
	lcv* B=new lcv (x,y,z);
	temp->suiv=B;
	if(action=="ajj")cout<<"Ajout de la valeur "<<z<<" a la position ("<<x<<"."<<y<<") dans la matrice "<<this->name<<endl;
	
}

void matrice::affiche()
{
	cout<<endl<<"matrice "<<this->name<<endl;
	cout<<setw(10)<<right<<"ligne"<<setw(10)<<right<<"colonne"<<setw(10)<<right<<"valeur"<<endl;
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		cout<<setw(10)<<right<<temp->li<<setw(10)<<right<<temp->co<<setw(10)<<right<<temp->val<<endl;
		temp=temp->suiv;
	}
	cout<<setw(10)<<right<<temp->li<<setw(10)<<right<<temp->co<<setw(10)<<right<<temp->val<<endl;
	cout<<endl;

}

void matrice::addition(matrice B)
{
	lcv* temp=B.tete;
	while(temp->suiv!=NULL)
	{
		ajout(temp->li,temp->co,temp->val,"add");
		temp=temp->suiv;
	}
	ajout(temp->li,temp->co,temp->val,"add");
}


void matrice::soustraction(matrice B)
{
	lcv* temp=B.tete;
	while(temp->suiv!=NULL)
	{
		ajout(temp->li,temp->co,-(temp->val),"add");
		temp=temp->suiv;
	}
	ajout(temp->li,temp->co,-(temp->val),"add");
}


void matrice::multiplication(matrice B){}
/*void matrice::carre()
{
	this->multiplication(this);
	
}*/
void matrice::transposition()
{
    int tab;
    for (int i = 0 ; i < taille ; i ++ )                    // Réalisation d'une transposition de matrice
    {
        for ( int j = i+1 ; j < taille ; j ++ )
        {
            tab = matrice[j][i];
            matrice[j][i] = matrice[i][j];
            matrice[i][j] = tab;
        }
    }
}


void matrice::lecture(){}
void matrice::ecriture(){}
