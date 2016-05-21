//!
//! \file app.cpp
//! \brief fonctions d'utilisation des opérations matricielles sur console
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
#include <map>
#include "libb.h"
#include "app.h"

using namespace std;

app::app()
{
	
}

void app::cons(){

	string czi;
	string debut;
	string fin;
	do	//boucle principale du prog
	{	
		try{
			czi="";
			debut="";
			fin="";
			getline(cin, czi);	//saisie de comande par lutilisateur
			if (czi=="\0");	
			else if(czi!="stop") //verifie si lutilisateur a demander a areter le prog
			{
				while(czi[0]==' ')czi.erase(0,1);													//
				while(czi[0]!=' ' && czi[0]!='+' && czi[0]!='-' && czi[0]!='*' && czi[0]!='\'' && czi[0]!='^' && czi[0]!='(' && czi[0]!='\0')		// isole la premire partie de la saisie pour l'analyser
				{																	//
					debut=debut+czi[0];														//		
					czi.erase(0,1);															//
				}																	//
				if (debut=="\0") throw(1);														//
																					
				else if(debut=="newmat"){ //verifie si lutilisateur a demander de créer une nouvelle matrice
					if(czi=="\0")throw(1);						//
					while(czi[0]==' ')czi.erase(0,1);				//
					if (czi[0]!='(') throw(1);					//
					while(czi[1]==' ')czi.erase(1,1);				// decoupe le reste en 2 partie 
					while(czi[1]!='\0' && czi[1]!=')')				//
					{								//	
						fin=fin+czi[1];						//
						czi.erase(1,1);						//
						while(czi[1]==' ')czi.erase(1,1);			//
					}								//
					while(czi[1]==' ')czi.erase(1,1);				//
					while(czi[2]==' ')czi.erase(1,1);				//
					if(czi!="()") throw(1);						//
					if(fin=="") throw(1);						//
					
					string a,b,c;							//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);		//
					while(fin[0]!=' ' && fin[0]!=',')				//
					{								//
						if(fin[0]=='\0')throw(1);				//
						a=a+fin[0];						//
						fin.erase(0,1);						//
					}								//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);		//
					while(fin[0]!=' ' && fin[0]!=',')				// analyse du contenue de la derniere string  
					{								//
						if(fin[0]=='\0')throw(1);				//
						b=b+fin[0];						//
						fin.erase(0,1);						//
					}								//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);		//
					while(fin[0]!=' ' && fin[0]!=',' && fin[0]!='\0')		//
					{								//
						c=c+fin[0];						//
						fin.erase(0,1);						//
					}								//
					if(fin!="\0")throw(1);						//
					if(a=="\0")throw(1);						//
					if(b=="\0")throw(1);						//
					if(c=="\0")throw(1);						//
					if (cont.count(a) ==1)throw(2);					//
					int d=0;							//
					while(b!="\0"){							//
						if(b[0]<'0' || b[0]>'9')throw(1);			//
						d=d*10+b[0]-48;						//
						b.erase(0,1);						//
					}								//
					int e=0;							//
					while(c!="\0"){							//
						if(c[0]<'0' || c[0]>'9')throw(1);			//
						e=e*10+c[0]-48;						//
						c.erase(0,1);						//
					}								//
					if(d<=0 || e<=0)throw(10);					//

					matrice Z(a,d,e);						//
					cont[a]=Z;							//creation de la matrice
				}
				else if(debut=="ajout"){
					if(czi=="\0")throw(1);				//
					while(czi[0]==' ')czi.erase(0,1);		//
					if (czi[0]!='(') throw(1);			//
					while(czi[1]==' ')czi.erase(1,1);		//
					while(czi[1]!='\0' && czi[1]!=')')		//
					{						//
						fin=fin+czi[1];				//decoupe le reste en 2 partie 
						czi.erase(1,1);				//
						while(czi[1]==' ')czi.erase(1,1);	//
					}						//
					while(czi[1]==' ')czi.erase(1,1);		//
					while(czi[2]==' ')czi.erase(1,1);		//	
					if(czi!="()") throw(1);				//
					if(fin=="") throw(1);				//
											
					string a,b,c,g;														//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',')											//
					{															//
						if(fin[0]=='\0')throw(1);											//
						a=a+fin[0];													//
						fin.erase(0,1);													//
					}															//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',')											//
					{															//
						if(fin[0]=='\0')throw(1);											//
						b=b+fin[0];													//
						fin.erase(0,1);													//
					}															//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',')											//
					{															//
						if(fin[0]=='\0')throw(1);											//
						c=c+fin[0];													//
						fin.erase(0,1);													//
					}															//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',' && fin[0]!='\0')									//
					{															// analyse du contenue de la derniere string  
						g=g+fin[0];													//
						fin.erase(0,1);													//
					}															//
					if(fin!="\0")throw(1);													//
					if(a=="\0")throw(1);													//
					if(b=="\0")throw(1);													//
					if(c=="\0")throw(1);													//
					if(g=="\0")throw(1);													//
					if (cont.count(a) ==0)throw(3);												//
					int d=0;														//
					while(b!="\0"){														//
						if(b[0]<'0' || b[0]>'9')throw(1);										//
						d=d*10+b[0]-48;													//
						b.erase(0,1);													//
					}															//
					int e=0;														//
					while(c!="\0"){														//
						if(c[0]<'0' || c[0]>'9')throw(1);										//
						e=e*10+c[0]-48;													//
						c.erase(0,1);													//
					}															//
					int f=0;														//
					while(g!="\0"){														//
						if(g[0]<'0' || g[0]>'9')throw(1);										//
						f=f*10+g[0]-48;													//
						g.erase(0,1);													//
					}															//
					if(d>cont[a].largeur || d<0)throw(4);											//
					if(e>cont[a].hauteur || e<0)throw(4);											//

					cont[a].ajout(d,e,f);													//apel de la focntion ajout
				}																
				else if(debut=="affiche"){													//
					if(czi=="\0")throw(1);													//
					while(czi[0]==' ')czi.erase(0,1);											//
					if (czi[0]!='(') throw(1);												//
					while(czi[1]==' ')czi.erase(1,1);											//
					while(czi[1]!='\0' && czi[1]!=')') 											//
					{															//
						if((czi[1]<'0' || czi[1]>'9') && (czi[1]<'a' || czi[1]>'z')&& (czi[1]<'A' || czi[1]>'Z'))th(1);			//decoupe le reste en 2 partie 
						fin=fin+czi[1];													//
						czi.erase(1,1);													//
						while(czi[1]==' ')czi.erase(1,1);										//
					}															//
					while(czi[1]==' ')czi.erase(1,1);											//
					while(czi[2]==' ')czi.erase(1,1);											//
					if(czi!="()")throw(1);													//
					if(fin=="")throw(1);													//
					if(cont.count(fin) ==0)throw(5);											//

					cont[fin].affiche();													//
				}
				else if(debut=="lecture"){													//
					if(czi=="\0")throw(1);													//
					while(czi[0]==' ')czi.erase(0,1);											//
					if (czi[0]!='(') throw(1);												//
					while(czi[1]==' ')czi.erase(1,1);											//
					while(czi[1]!='\0' && czi[1]!=')')											//
					{															//
						fin=fin+czi[1];													//decoupe le reste en 2 partie 
						czi.erase(1,1);													//
						while(czi[1]==' ')czi.erase(1,1);										//
					}															//
					while(czi[1]==' ')czi.erase(1,1);											//
					while(czi[2]==' ')czi.erase(1,1);											//
					if(czi!="()") throw(1);													//
					if(fin=="") throw(1);													//
							
					string a,b;														//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',')											//
					{															//
						if(fin[0]=='\0')throw(1);											//
						a=a+fin[0];													//
						fin.erase(0,1);													//
					}															//analyse du contenue de la derniere string  
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',' && fin[0]!='\0')									//
					{															//
						b=b+fin[0];													//
						fin.erase(0,1);													//
					}															//
					if(fin!="\0")throw(1);													//

					cont[a].lecture(b);													//apel de la focntion lecture
				}			
				else if(debut=="ecriture"){													//
					if(czi=="\0")throw(1);													//
					while(czi[0]==' ')czi.erase(0,1);											//
					if (czi[0]!='(') throw(1);												//
					while(czi[1]==' ')czi.erase(1,1);											//
					while(czi[1]!='\0' && czi[1]!=')')											//
					{															//decoupe le reste en 2 partie
						fin=fin+czi[1];													//
						czi.erase(1,1);													//
						while(czi[1]==' ')czi.erase(1,1);										//
					}															//
					while(czi[1]==' ')czi.erase(1,1);											//
					while(czi[2]==' ')czi.erase(1,1);											//
					if(czi!="()") throw(1);													//
					if(fin=="") throw(1);													//
							
					string a,b;														//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',')											//
					{															//
						if(fin[0]=='\0')throw(1);											//
						a=a+fin[0];													//
						fin.erase(0,1);													//analyse du contenue de la derniere string  
					}															//
					if(fin[0]=='\0')throw(1);												//
					while(fin[0]==' ' || fin[0]==',')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=',' && fin[0]!='\0')									//
					{															//
						b=b+fin[0];													//
						fin.erase(0,1);													//
					}															//
					if(fin!="\0")throw(1);													//

					cont[a].ecriture(b);													//apel de la focntion ecriture
				}				
				else if(debut=="help"){														//
					while(czi[0]==' ')czi.erase(0,1);											//			
					if(czi!="\0") throw(9);													//
					cout	<<"Les fonction disponible sont :"<<endl<<endl									//
						<<"newmat(nom de la matrice,largeur,hauteur):creer une nouvelle matrice"<<endl					//
						<<"ajout(nom de la matrice,abscisse,ordoné,valeur):ajoute une valeur a la matrice"<<endl			//
						<<"affiche(nom de la matrice):affiche la matrice"<<endl								//
						<<"ecriture(nom de la matrice,nom du fichier):ecrit la matrice dans le fichier"<<endl				//fonction help : enonce tt les posibilité
						<<"lecture(nom de la matrice,nom du fichier):lit la matrice dans le fichier"<<endl				//
						<<"stop : met fin au programme"<<endl										//
						<<"A+B : ajoute la matrice B a la matrice A"<<endl								//
						<<"A-B : soustrait la matrice B a la matrice A"<<endl								//
						<<"A*B(C) : multiplie la matrice B et la matrice A et met le resultat dans la matrice  C"<<endl			//
						<<"A^(C) : met la matrice A au carré et met le resultat dans la matrice  C"<<endl				//
						<<"A\' : fait la transposé de la matrice A"<<endl;								//
						
				}																//
				else{ 																//
					if(czi=="\0")throw(1);													//
					while(czi[0]==' ')czi.erase(0,1);											//
					while(czi[1]==' ')czi.erase(1,1);											//
					while(czi[1]!='\0')													//decoupe le reste en 2 partie
					{															//
						fin=fin+czi[1];													//
						czi.erase(1,1);													//
						while(czi[1]==' ')czi.erase(1,1);										//
					}															//
					while(czi[1]==' ')czi.erase(1,1);											//

					if(czi=="+"){														//
					if (fin=="\0") throw(1);												//
					if(cont.count(debut)==0)throw(8);											//apel de la fonction addition
					if(cont.count(fin)==0)throw(8);												//
					cont[debut].addition(cont[fin]);											//
					}
					else if(czi=="-"){													//
					if (fin=="\0") throw(1);												//
					if(cont.count(debut)==0)throw(8);											//apel de la fonction soustraction
					if(cont.count(fin)==0)throw(8);												//
					cont[debut].soustraction(cont[fin]);											//
					}	
					else if(czi=="*"){													//
					if (fin=="\0") throw(1);												//
					if(cont.count(debut)==0)throw(8);											//
					string a,b;														//
					while(fin[0]==' ')fin.erase(0,1);											//
					while(fin[0]!=' ' && fin[0]!='(')											//
					{															//
						a=a+fin[0];													//
						fin.erase(0,1);													//
					}															//
					while(fin[0]==' ' || fin[0]=='(')fin.erase(0,1);									//
					if(fin[0]=='\0')throw(1);												//
					while(fin[0]!=' ' && fin[0]!=')')											//
					{															//
						b=b+fin[0];													//
						fin.erase(0,1);													//
					}															//
					while(fin[0]==' ' || fin[0]==')')fin.erase(0,1);									//
					if (fin!="\0") throw(1);												//
					if(cont.count(a)==0)throw(8);												//
					matrice Z(b,cont[a].largeur,cont[debut].hauteur);									//
					cont[b]=Z;														//
					cont[b]=cont[debut].multiplication(cont[a]);										//apel de la fonction multiplication
					}		
					else if(czi=="^"){													//
					if (fin=="\0") throw(1);												//
					if(cont.count(debut)==0)throw(8);											//
					string a;														//
					while(fin[0]==' ')fin.erase(0,1);											//
					if(fin[0]!='(') throw(1);												//
					while(fin[0]==' ' || fin[0]=='(')fin.erase(0,1);									//
					while(fin[0]!=' ' && fin[0]!=')')											//
					{															//
						a=a+fin[0];													//
						fin.erase(0,1);													//
					}															//
																				//
					while(fin[0]==' ' || fin[0]==')')fin.erase(0,1);									//
					if (fin!="\0") throw(1);												//
					matrice Z(a,cont[debut].largeur,cont[debut].hauteur);									//
					cont[a]=Z;														//
					cont[a]=cont[debut].carre();												//apel de la fonction carre
					}			
					else if(czi=="\'"){													//
					if (fin!="\0") throw(1);												//
					if(cont.count(debut)==0)throw(8);											//apel de la fonction transposé
					cont[debut].transposition();												//
					}														
					else throw(1);														//
				}																//
																				//
			}																	//
		}	
		catch(int a){																	//
			if (a==1)cout<<endl<<endl<<"Erreur,commande invalide, utiliser la commande 'help' pour obtenir les commandes existantes"<<endl<<endl; 	//
			else if (a==2)cout<<endl<<"Erreur,vous essayer de créer une matrice deja existante"<<endl<<endl; 					//
			else if (a==3)cout<<endl<<"Erreur,vous essayer d'ajouter une valeur a une matrice inexistante"<<endl<<endl;				//
			else if (a==4)cout<<endl<<"Erreur,vous essayer d'ajouter une valeur hors de la matrice"<<endl<<endl;					//
			else if (a==5)cout<<endl<<"Erreur,vous essayer d'afficher une matrice inexistante"<<endl<<endl;						//  gestion des erreur
			else if (a==8)cout<<endl<<"Erreur,vous essayer de manipuler une matrice inexistante"<<endl<<endl; 					//
			else if (a==9)cout<<endl<<"Erreur,la fonction d'aide s'écris juste \"help\""<<endl<<endl; 						//
			else if (a==10)cout<<endl<<"Erreur,valeur trop basse"<<endl<<endl; 									//
		 																		//
		}																		//
	}while (czi!="stop");   																//
}


