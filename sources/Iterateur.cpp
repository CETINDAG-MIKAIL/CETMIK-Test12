#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;
#include "ArrayList.h"
#include "Iterateur.h"
#include "MyQT.h"
#include "Couleur.h"

// #include "Dimension.h"
template <class type>
Iterateur<type>::Iterateur (ArrayList<type>& l): lis(l),pCur(l.pListe) 
{

};

template <class type>
int Iterateur<type>::end() 
{
    return pCur == 0; 
}

template <class type>
void Iterateur<type>::reset() 
{ 
    pCur = lis.pListe; 
}

template <class type>
char Iterateur<type>::operator++()
{
 if (pCur)
 {
 pCur = pCur->suiv;
 return 1;
 }
 else return 0;
}

template <class type>
char Iterateur<type>::operator++(int) 
{ 
 return operator++(); 
}

template <class type>
Iterateur<type>::operator type() const 
{ 
 return pCur->valeur; // Appel du constructeur de copie de la
} // classe T !!!

template <class type>
type& Iterateur<type>::operator& (void) 
{ 
 return pCur->valeur; 
}
template class Iterateur<int>;
template class Iterateur<Couleur>;


