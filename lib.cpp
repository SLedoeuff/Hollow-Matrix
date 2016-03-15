#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "lib.h"

using namespace std;

lcv::lcv(int x,int y,int z)
{
	li=x;
	co=y;
	val=z;
	suiv=NULL;
}


matrice::matrice()
{
	tete=NULL;
}


void matrice::ajout(int x,int y,int z)
{
	if(tete==NULL)
	{
		lcv *B=new lcv(x,y,z);
		tete=B;
		return;
	}
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		temp=temp->suiv;
	}
	lcv* B=new lcv (x,y,z);
	temp->suiv=B;

}

void matrice::affiche()
{
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		cout<<temp->li<<" "<<temp->co<<" "<<temp->val<<endl;
		temp=temp->suiv;
	}
	cout<<temp->li<<" "<<temp->co<<" "<<temp->val<<endl;
	cout<<endl;

}






void matrice::addition(matrice B)
{
	lcv* temp=tete;
	while(temp->suiv!=NULL)
	{
		temp=temp->suiv;
	}
	temp->suiv=B.tete;

}
void matrice::soustraction(){}
void matrice::multiplication(){}
//void matrice::carré(){}
void matrice::transposition(){}


void matrice::lecture(){}
void matrice::ecriture(){}
