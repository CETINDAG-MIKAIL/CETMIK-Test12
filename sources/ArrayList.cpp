#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;
#include "ArrayList.h"
#include "Iterateur.h"
#include "MyQT.h"
// #include "Dimension.h"


//***** Classe ArrayList *****
template <class type>
ArrayList<type>::ArrayList(void):pListe(0) 
{

};
template <class type>
ArrayList<type>::ArrayList(const ArrayList<type> &c1) : pListe(nullptr) 
{
    if (c1.pListe != nullptr)
    {
        pListe = new noeud<type>(c1.pListe->valeur, nullptr); // Crée la tete de la liste copie

        noeud<type>* courant = pListe;
        noeud<type>* courantCopie = c1.pListe->suiv; // Se met 1 en avance par rapport à la liste source parce que le premier est deja copier

        while (courantCopie != nullptr)
        {
            courant->suiv = new noeud<type>(courantCopie->valeur, nullptr); // Crée un nouveau nœud dans la liste copiée
            courant = courant->suiv;
            courantCopie = courantCopie->suiv;
        }
    }
}
template <class type>
void ArrayList<type>::operator=(const ArrayList<type> &c1) {
//	Detruit la liste
    noeud<type> *pCur = pListe;
    while (pCur != nullptr) {
        noeud<type> *pPrec = pCur;
        pCur = pCur->suiv;
        delete pPrec; 
    }
    pListe = nullptr; // Réinitialise la tete
// reconstruit la nouvelle liste depuis la seconde comme avec le constructeur copie
    if (c1.pListe != nullptr) {
        pListe = new noeud<type>(c1.pListe->valeur, nullptr); // Cree la tete

        noeud<type>* courant = pListe;
        noeud<type>* courantCopie = c1.pListe->suiv; // Avance d'un élément par rapport à la liste source

        while (courantCopie != nullptr) {
            courant->suiv = new noeud<type>(courantCopie->valeur, nullptr);
            courant = courant->suiv;
            courantCopie = courantCopie->suiv;
        }
    }
}



template <class type>
ArrayList<type>::~ArrayList (void)
{
	noeud<type> *pCur, *pPrec;
	pCur = pListe;
	while (pCur != NULL)
	{
		pPrec = pCur; pCur = pCur->suiv;
		delete pPrec;
	}
}

template <class type>
char ArrayList<type>::estVide(void) 
{ 
	if(pListe == nullptr)
		return 'O';
	else
		return 'N';
}

template <class type>
int ArrayList<type>::getNombreElements(void) 
{ 
	int i=0;
	if(pListe == nullptr){
		return i;	
	} 
	else
	{
		i=1;
		noeud<type> *courant = pListe;
		while(courant != nullptr)
		{
			courant = courant ->suiv;
			i++;
		}
		return i;
		cout << endl;
	}
}
	
template <class type>
type& ArrayList<type>::getElement(int indice) 
{ 
    int i = 0;
    noeud<type> *courant = pListe;

    while ( i <= indice) {
    	// cout << "i: " << i << ", indice: " << indice << ", courant: " << courant << endl;
        if (i == indice) {
            return courant->valeur;
        }

        courant = courant->suiv;
        i++;
    }

    throw std::out_of_range("L'indice est hors limites ou la liste est vide.");
}

template <class type> 
type& ArrayList<type>::retireElement(int indice) {
    int i = 0;
    noeud<type>* tmp = nullptr;
    noeud<type>* courant = pListe;
    noeud<type>* prec = nullptr;

    while (courant != nullptr && indice != i) {
        prec = courant;
        courant = courant->suiv;
        i++;
    }

    if (courant != nullptr) {
        if (indice == 0) {
            tmp = courant;
            pListe = courant->suiv;
        } else {
            tmp = courant;
            prec->suiv = courant->suiv;
        }
        type& valeurRetiree = tmp->valeur;
        delete tmp; // Assurez-vous de libérer la mémoire du nœud retiré
        return valeurRetiree;
    }

    throw std::out_of_range("L'indice est hors limites ou la liste est vide.");
}

// template <class type>
// type& operator=(const ArrayList<type> &value) {
//     }

// template <class type>
// type ArrayList<type>::head(void)
// { 
// 	return pListe->valeur; // Appel du constructeur de copie de la
// } // classe T !!!

template <class type>
void ArrayList<type>::insereElement (type n)
{
	if(pListe == nullptr)
	{
		pListe = new noeud<type> (n,pListe);
		return;
	}
	else
	{
		noeud<type> *courant = pListe;
		while(courant->suiv != nullptr)
		{
			courant = courant->suiv; 
		}
		if(courant->suiv == nullptr)
		{
			courant->suiv = new noeud<type> (n,nullptr);
		}
	}
}

// template <class type>
// void ArrayList<type>::removeHead (void)
// {
//  if (pListe)
//  {
//  noeud<type> *pWork(pListe);
//  pListe = pListe->suiv;
//  delete pWork;
//  }
// }

// template <class type>
// void ArrayList<type>::removeTail(void)
// {
// 	if (!pListe) return;
// 	if (!pListe->suiv)
// 	{
// 	delete pListe; pListe =0;
// 	return;
// 	}
// 	noeud<type> *pWork(pListe), *pPrec;
// 	while (pWork->suiv)
// 	{
// 	pPrec = pWork;
// 	pWork = pWork->suiv;
// 	}
// 	delete pWork;
// 	pPrec->suiv = 0;
// }

template <class type>
void ArrayList<type>::Affiche (void)
{
	if(pListe == nullptr){
		cout << "Liste vide !" << endl;
		return;	
	} 
	else
	{
		noeud<type> *courant = pListe;
		cout << "contenue de la liste :" << endl;
		while(courant != nullptr)
		{
			cout << courant->valeur << "	";
			courant = courant ->suiv;
		}
		cout << endl;
	}
}

template <class type>
void ArrayList<type>::trier() {
    if (pListe == nullptr) {
        cout << "La liste est vide !" << endl;
        return;
    }

    noeud<type> *i, *j;
    for (i = pListe; i != nullptr; i = i->suiv) {
        for (j = i->suiv; j != nullptr; j = j->suiv) {
            if (compare(i->valeur, j->valeur) > 0) { // Utilisation de la fonction compare()
                type temp = i->valeur;
                i->valeur = j->valeur;
                j->valeur = temp;
            }
        }
    }
}

template <class type>
int ArrayList<type>::compare(const type& a, const type& b) const {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}



// //***** Classe CLisIer *****
// template <class type>
// CLisIter<type>::CLisIter (ArrayList<type>& l): lis(l),pCur(l.pListe) 
// {

// };

// template <class type>
// int CLisIter<type>::end() 
// { 
// 	return pCur == 0; 
// }

// template <class type>
// void CLisIter<type>::reset() 
// { 
// 	pCur = lis.pListe; 
// }

// template <class type>
// char CLisIter<type>::operator++()
// {
// 	if (pCur)
// 	{
// 	pCur = pCur->suiv;
// 	return 1;
// 	}
// 	else return 0;
// }

// template <class type>
// char CLisIter<type>::operator++(int) 
// { 
// 	return operator++(); 
// }

// template <class type>
// CLisIter<type>::operator type() const 
// { 
// 	return pCur->valeur; // Appel du constructeur de copie de la
// } // classe T !!!

// template <class type>
// type& CLisIter<type>::operator& (void) 
// { 
// 	return pCur->valeur; 
// }
//***** Instanciation des templates *****
template class ArrayList<int>;
// template class ArrayList<Couleur>;


// #include "coord.h"
// template class ArrayList<coord>;
// template class CLisIter<coord>;
