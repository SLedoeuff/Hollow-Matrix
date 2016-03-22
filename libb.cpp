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


matrice::matrice(string nom,int x,int y)
{
	hauteur=y;
	largeur=x;
	name=nom;
	tete=NULL;
}


void matrice::action(int x,int y,int z,string act)
{
	if(tete==NULL)
	{
		lcv *B=new lcv(x,y,z);
		tete=B;
		if(act=="ajj")cout<<"Ajout de la valeur "<<z<<" a la position ("<<x<<"."<<y<<") dans la matrice "<<this->name<<endl;
		
		return;
	}
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		if(temp->li==x && temp->co==y)
		{
			if(act=="ajj")cerr<<"Erreur il y a deja la valeur "<<temp->val<<" a la position ("<<temp->li<<"."<<temp->co<<") , impossible d ajouter la valeur dans la matrice "<<this->name<<z<<endl;
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
		if(act=="ajj")cerr<<"Erreur il y a deja la valeur "<<temp->val<<" a la position ("<<temp->li<<"."<<temp->co<<") , impossible d ajouter la valeur dans la matrice "<<this->name<<z<<endl;
		else if(act=="add")
		{
			temp->val=temp->val+z;
		}
		return;
	}
	lcv* B=new lcv (x,y,z);
	temp->suiv=B;
	if(act=="ajj")cout<<"Ajout de la valeur "<<z<<" a la position ("<<x<<"."<<y<<") dans la matrice "<<this->name<<endl;
	
}

void matrice::affiche()
{
	cout<<endl<<"matrice "<<this->name<<endl;
	cout<<setw(10)<<right<<"ligne"<<setw(10)<<right<<"colonne"<<setw(10)<<right<<"valeur"<<endl;
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


void matrice::lecture(){}
void matrice::ecriture(){}
