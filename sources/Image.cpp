#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;
#include "Image.h"
#include "MyQT.h"
// #include "Dimension.h"




int Image::getId() const
{
	return id;
}
char* Image::getNom()const
{
	return nom;
}
Dimension Image::getDimension()const
{
	return dimension;
}
//			SET

void Image::setId(int nombre){id=nombre;}


void Image::setNom(const char *n){ 
	if (nom && strlen(nom) > 0) 
	{
		delete nom;
		nom=NULL;
	}
	nom = new char[strlen(n)+1];
	strcpy(nom,n);
}
void Image::setDimension(Dimension d1) {

        dimension = d1;
}
// 			CONSTRUCTEUR

Image::Image()
{
	setId(0);
	nom = NULL;
	setNom("default");
}

Image::Image(int nombre,const char *n)
{
	setId(nombre);
	nom = NULL;
	setNom(n);
}

/////////// constructeur d'initialisation + dimension//////////
Image::Image(int nombre, const char *n, Dimension d1)
{
	setId(nombre);
	nom = NULL;
	setNom(n);	
	setDimension(d1);
}
/////////// constructeur de copie //////////

Image::Image(const Image& p)
{
	setId(p.getId());
	nom = NULL;
	setNom(p.getNom());	
	setDimension(p.getDimension());
}

/////////// constructeur fichier//////////

Image::Image(const char* fichier)
{
	setId(1);
	nom = NULL;
	setNom(fichier);	
}

//			DESTRUCTEUR 
Image::~Image()
{
	cout << "D Image" << endl << endl;
	if(nom != NULL && strlen(nom)>0)
	{
		delete[] nom; 
		nom=NULL;
	}
}
