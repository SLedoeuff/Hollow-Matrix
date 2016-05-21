//!
//! \file app.h
//! \brief regroupe les fonctions consoles
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
#ifndef _app
#define _app

using namespace std;

/*! \class CPlayer
   * \brief classe representant le lecteur
   *
   *  La classe gere la lecture d'une liste de morceaux
   */
class app
{
	private:
//!
//! \fn void app::cons()
//! \brief 
//!
//! \param Aucun
//! \return Aucun
//!
		map <string,matrice> cont;

	public:
//!
//! \fn void app::cons()
//! \brief 
//!
//! \param Aucun
//! \return Aucun
//!
		app();
//!
//! \fn void app::cons()
//! \brief 
//!
//! \param Aucun
//! \return Aucun
//!
		void cons();
		
		
};



#endif
