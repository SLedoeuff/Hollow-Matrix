#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

interface::console()
  {	
		int v(0), var1,var2,res;				
		char c ;		
		bool affiche = false;
		do
		{
			c = saisie(v);														// on declare une variable qui prend la saisie de l'utilisateur en valeur
			if ( affiche == true )
			{
				P.Afficher();
			}

			switch ( c ) 												// On declare un switch pour traiter tout les cas de saisies
			{
				case '+' : 
					var1 = P.depiler();				
					var2 = P.depiler();
					res = var1 + var2 ;
					P.empiler(res);
				break;
				
				case '-' : 
					var1 = P.depiler();
					var2 = P.depiler();
					res = var2 - var1 ;
					P.empiler(res);				
				break;

				case '*' :
					var1 = P.depiler();
					var2 = P.depiler();
					res = var1 * var2 ;
					P.empiler(res);

				break;

				case '/' :
					var1 = P.depiler();
					var2 = P.depiler();
					res = var2 / var1 ;
					P.empiler(res);

				break;

				case '%' :
					var1 = P.depiler();
					var2 = P.depiler();
					res = var1 % var2 ;
					P.empiler(res);

				break;
				
				case '=' :
					var1 = P.depiler();
					cout << "> "<<var1<<endl;
								
				break; 
				
				case 'a' :
					affiche = !affiche;
				break;

				case 'v' :
					P.empiler(v);
				break;

				case 'd' :
					var1 = P.depiler();
					P.empiler(v);
					P.empiler(v);
				break;

				case ':' : 
					var1 = P.depiler();
					cout<<">"<<var1;
					P.empiler(var1);
				break; 

				case 'save' :
					var1 = 				

				default : 
				break;
			}
		}while ( c != 'q' && c != 'Q');      // la calculette fonctionne tant que on ne tape pas q ou Q , le cas échéant elle quitte et dis Aurevoir
  }
  
  char Calculatrice::saisie(int & V)
  {	

  string S;
	int i;
    cout << "< ";
    cin >> S;
	V = 0;
	if (('0'<=S[0]) && (S[0]<='9'))
	{
		i = 0;
		while ( S[i] != '\0' )
		{
			
			V = V * 10 + (S[i] - '0');
			i++;
		}
		return 'v';
	}else if (S[0] == '-')
	{
		if (('0'<=S[1]) && (S[1]<='9')) 
		{
			i = 1;
			while ( S[i] != '\0' )
			{
				V = V * 10 + (S[i] - '0');
				i++;
			}
			V = -V;
			return 'v';
		}
			else
		{	
		return S[0];
		}
	}
	else
	{
		return S[0];
	}
	
    
			// ...
  }
