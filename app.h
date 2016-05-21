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

//!
//! \class app
//! \brief classe permettant d'utiliser les fonction en invité de commande
//!
class app
{
	private:
		map <string,matrice> cont;

	public:
//!
//! \fn void app::cons()
//! \brief constructeur par defaut de la classe app, ne sert que pour l'initialisation
//!
//! \param Aucun
//! \return Aucun
//!
		app();
//!
//! \fn void app::cons()
//! \brief permet de traiter les données que l'utilisateur rentre dans l'invité de commande pour éxécuter les calculs matriciels
//!   il prends ce que l'utilisateur a entré, les mets dans une string, et les traites caractère par caractère.
//! \param Aucun
//! \return Aucun
//!
		void cons();
		
		
};

#endif
