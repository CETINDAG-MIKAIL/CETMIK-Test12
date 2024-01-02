#ifndef ITERATEUR_H
#define ITERATEUR_H
// #include "ImageNG.h"
#include "Dimension.h"
#include "Couleur.h"
#include "ArrayList.h"

#include <iostream>
using namespace std;


template <class type>
class Iterateur
{
	private :
		ArrayList<type>& lis; // reference de la liste
		noeud<type> *pCur;
	public :
		Iterateur (ArrayList<type>& l);
		int end();
		void reset();
		char operator++();
		char operator++(int);
		operator type() const;
		type& operator&(void);
};

#endif