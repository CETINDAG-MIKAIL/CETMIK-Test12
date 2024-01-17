#include <math.h>
#include <iostream>
#include <cstring>
#include "PhotoShop.h"
#include "ArrayList.h"
#include "Iterateur.h"

using namespace std;
int PhotoShop::numCourant = 1;

PhotoShop::PhotoShop()
{	

}

PhotoShop::~PhotoShop()
{
	reset();
}
void PhotoShop::ajouteImage(Image* pImage)
{
	pImage->setId(numCourant);
	numCourant++;

	images.insereElement(pImage);

}
void PhotoShop::afficheImages()  {
    Iterateur<Image*> it(images); // Création d'un itérateur pour la liste d'images
    // it.reset();
    while(!it.end()) {

        Image* image = it.operator&(); // Obtention de l'image à partir de l'itérateur
        image->Affiche(); // Appel de la méthode Affiche() pour afficher l'image
    	it.operator++();
    }
}
void PhotoShop::dessineImages()  {
    Iterateur<Image*> it(images); // Création d'un itérateur pour la liste d'images

    while(!it.end()) {

        Image* image = it.operator&();
        image->Dessine(); 
    	it.operator++();
    }
}
Image* PhotoShop::getImageParIndice(int indice)
{
	Iterateur<Image*> it(images); // Création d'un itérateur pour la liste d'images
	int i=0;

    while(!it.end()) 
    {
    	if(i==indice)
    	{
        	 return it.operator&();
    	}
    	it.operator++();
    	i++;
    }
    return nullptr;
}
Image* PhotoShop::getImageParId(int id)
{
	Iterateur<Image*> it(images); // Création d'un itérateur pour la liste d'images

    while(!it.end()) 
    {
    	Image* image = it.operator&();

    	if( image->getId() == id)
    	{
        	 return image;
    	}
    	it.operator++();
    }
    return nullptr;
}
void PhotoShop::supprimeImageParIndice(int indice) {
    if (indice > 0 && indice < images.getNombreElements())
    { 
        cout << "INDICE : " << indice << endl;
        Image* image = images.getElement(indice); // Récupère le pointeur vers l'image à supprimer
        cout << "image --------------------="<< image->getId() << endl;
        images.retireElement(indice); // Retire l'élément correspondant de la liste en utilisant la classe ArrayList
        delete image; // Libère la mémoire occupée par l'image
    }

}


void PhotoShop::supprimeImageParId(int id) {
    Iterateur<Image*> it(images); // Crée un itérateur pour la liste d'images
    int i=1;
    while (!it.end()) {
        Image* image = it.operator&(); // Obtient le pointeur vers l'image courante

        if (image->getId() == id) {
            cout << "Image à supprimer trouvée avec l'id : " << i << endl;
            images.retireElement(i); // Retire l'élément correspondant de la liste en utilisant l'indice
            delete image; // Libère la mémoire occupée par l'image après avoir retiré l'élément
            cout << "Image supprimée." << endl;
            break; // Sort de la méthode une fois l'image supprimée
        }

        it.operator++();
        i++;
    }
}



void PhotoShop::reset() {
    // Libération de la mémoire pour chaque Image dans images
    while (!images.estVide()) {
        Image* image = images.getElement(0); // Obtient l'image à l'indice 0
        delete image; // Libère la mémoire pour l'image
        images.retireElement(0); // Retire l'image de la liste
    }

    numCourant = 1;
}

PhotoShop PhotoShop::instance; // on l'initialise afin de garantir son existence pour ne pas avoir une initialisation tardive et avoir des probleme avec getInstance
PhotoShop& PhotoShop::getInstance()
{
	return instance;
}
ArrayList<Image*>&  PhotoShop::getImages()
{
    cout << "ICI" << endl;
    return images;
}
