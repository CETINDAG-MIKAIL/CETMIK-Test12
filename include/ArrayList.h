#ifndef ARRAYLIST_H
#define ARRAYLIST_H
// #include "ImageNG.h"
#include "Dimension.h"
#include "Couleur.h"

#include <iostream>
using namespace std;


template <class type>
struct noeud
{
	type valeur;
	noeud<type> *suiv;
	noeud (type n, noeud<type> *s) : valeur(n), suiv(s) {};
};

// Declaration de la classe iterateur
template <class type> class Iterateur;
// Definition de la classe CListe
template <class type>
class ArrayList
{
	private :
	noeud<type> *pListe;
	public :
	ArrayList (void);
	ArrayList (const ArrayList<type> &);
	~ArrayList (void);
	char estVide(void);
	// type head(void);
	void insereElement(type n);
	void trier();
	int compare(const type& a, const type& b) const;

	int getNombreElements();
	type& getElement(int);
	type& retireElement(int);
	void operator=(const ArrayList<type>&);

	// void removeHead (void);
	// void removeTail (void);
	void Affiche (void);
	friend class Iterateur<type>;


};

#endif