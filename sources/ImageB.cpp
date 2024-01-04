#include <math.h>
#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;
#include "ImageB.h"
#include "MyQT.h"
#include "XYException.h"


	


int ImageB::getL_MAX(){return 550;};
int ImageB::getH_MAX(){return 550;};
Couleur ImageB::couleurTrue=Couleur(255,255,255);
Couleur ImageB::couleurFalse = Couleur(0,0,0);


bool ImageB::getPixel(int x,int y)const
{
	if ((x < 0 || x > dimension.getLargeur()) && (y < 0 || y > dimension.getHauteur())) {
			throw XYException("Coordonnee Pixel invalide !", "d");}
	

	if (x < 0 || x > dimension.getLargeur()) 
		throw XYException("Coordonnee Pixel invalide X !", "x");
	
	if (y < 0 ||  y > dimension.getHauteur()) 
		throw XYException("Coordonnee Pixel invalide Y !", "y");
	return  matrice[x][y];
}

//						CONSTRUCTEUR
ImageB::ImageB(): Image()
{
	for(int i=0;i<getL_MAX();i++)
	{
		for(int j=0; j<getH_MAX();j++)
		{
			matrice[i][j]= false;
		}
	}
}
/////////// constructeur d'initialisation //////////
ImageB::ImageB(int nombre, const char *n) : Image(nombre, n)
{

}
/////////// constructeur d'initialisation + dimension//////////
ImageB::ImageB(int nombre, const char *n, Dimension d1) : Image(nombre, n, d1)
{

	setId(nombre);
	nom = NULL;
	setNom(n);	
	setDimension(d1);
}
//////// constructeur de copie //////////////:
ImageB::ImageB(const ImageB& p): Image(p)
{
	for(int i=0;i<dimension.getLargeur();i++)
	{
		for(int j=0; j<dimension.getHauteur();j++)
		{
			matrice[i][j]=p.matrice[i][j];
		}
	}
}

void ImageB::setPixel(int x, int y,bool i1)
{
	// cout << i1<< endl;
	if ((x < 0 || x > dimension.getLargeur()) && (y < 0 || y > dimension.getHauteur())) {
			throw XYException("Coordonnee Pixel invalide !", "d");}
			
			if (x < 0 || x > dimension.getLargeur()) 
				throw XYException("Coordonnee Pixel invalide X !", "x");
			
			if (y < 0 ||  y > dimension.getHauteur()) 
				throw XYException("Coordonnee Pixel invalide Y !", "y");
	matrice[x][y]=i1;
}
void ImageB::setBackground(bool i1)
{
	for(int i=0;i<dimension.getLargeur();i++)
	{
		for(int j=0;j<dimension.getHauteur();j++)
		{
			matrice[i][j]=i1;
		}	
	}
}



// 				OPERATEUR

ImageB& ImageB::operator=(const ImageB& p)
{

    if (this == &p) {
        return *this; // Renvoyez l'objet actuel sans rien faire
    }

    setId(p.id);
    setNom(p.nom);
    setDimension(p.dimension);

    // Copiez les données de la matrice
    for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
            matrice[i][j] = p.matrice[i][j];
        }
    }

    return *this;
}



std::ostream& operator<<(std::ostream& os,const ImageB &i1){

	os << "Id: " << i1.id << "||" << "Nom: " << i1.nom << "||" << "Largeur: " << i1.getDimension().getLargeur() << "||" << "Hauteur: " << i1.getDimension().getHauteur()<< endl;
	return os;
}





void ImageB::Affiche()const
{
	cout << "id = " << getId() << endl;
	if (nom == NULL) cout << "pointeur null" << endl;
	cout << "nom = " << getNom() << endl;
 	cout << "Dimension = " << dimension.getLargeur() << " x " << dimension.getHauteur() << endl;
}
void ImageB::Dessine() const{
    MyQT::ViewImage(*this);
}

// void ImageB::importFromFile(const char* fichier){
//     MyQT::ImportFromFile(*this, fichier);
// }

void ImageB::exportToFile(const char* fichier, const char* format)const {
    MyQT::ExportToFile(*this, fichier, format);
}

//			DESTRUCTEUR 
ImageB::~ImageB()
{
	// cout << "D" << endl << endl;
	// if(nom) delete nom;
cout << "D ImageB" << endl;

    for (int i = 0; i < getL_MAX(); i++) {
        for (int j = 0; j < getH_MAX(); j++) {
            matrice[i][j] = false;
        }
    }

couleurTrue=Couleur(255,255,255);
couleurFalse = Couleur(0,0,0);
	
}

//			FLUX


void ImageB::Save(ofstream & fichierD) const
{
	//		Ouverture du fichier 
	if (!fichierD.is_open())
    {
        cout << "Erreur d'ouverture du fichier !" << endl; 
        exit(1);
    }

	fichierD.write((char *)(this), sizeof(*this));
	fichierD.close();
}
void ImageB::Load(ifstream & fichierD)
{
	//		Ouverture du fichier 
	if (!fichierD.is_open())
    {
        cout << "Erreur d'ouverture du fichier !" << endl; 
        exit(1);
    }

	fichierD.read((char *)(this), sizeof(*this));

	fichierD.close();
}
