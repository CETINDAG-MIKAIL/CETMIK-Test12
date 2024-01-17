#include <math.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#include "ImageRGB.h"
#include "MyQT.h"
#include "Image.h"
#include "XYException.h"




//				GET 



int ImageRGB::getL_MAX(){return 550;};
int ImageRGB::getH_MAX(){return 550;};



Couleur ImageRGB::getPixel(int x,int y)const
{

	if ((x < 0 || x > dimension.getLargeur()) && (y < 0 || y > dimension.getHauteur())) {
			throw XYException("Coordonnee Pixel invalide !", "d");}
	

	if (x < 0 || x > dimension.getLargeur()) 
		throw XYException("Coordonnee Pixel invalide X !", "x");
	
	if (y < 0 ||  y > dimension.getHauteur()) 
		throw XYException("Coordonnee Pixel invalide Y !", "y");

	int rouge = matrice[x][y].getRouge();
	int bleu = matrice[x][y].getBleu();
	int vert = matrice[x][y].getVert();

	return Couleur(rouge,vert,bleu);

	//return matrice[x][y];
}

//						CONSTRUCTEUR
ImageRGB::ImageRGB() : Image()
{
	for(int i=0;i<getL_MAX();i++)
	{
		for(int j=0; j<getH_MAX();j++)
		{
			matrice[i][j]=Couleur(0,0,0);
		}
	}
}
/////////// constructeur d'initialisation //////////
ImageRGB::ImageRGB(int nombre, const char *n) : Image(nombre, n)
{

}
/////////// constructeur d'initialisation + dimension//////////
ImageRGB::ImageRGB(int nombre, const char *n, Dimension d1) : Image(nombre, n, d1)
{

}
//////// constructeur de copie //////////////:
ImageRGB::ImageRGB(const ImageRGB& p) : Image(p)
{
	for(int i=0;i<dimension.getLargeur();i++)
	{
		for(int j=0; j<dimension.getHauteur();j++)
		{
			matrice[i][j]=p.matrice[i][j];
		}
	}
}
ImageRGB::ImageRGB(const char* fichier) : Image(fichier)
{
    MyQT::ImportFromFile(*this, fichier);
}

void ImageRGB::setPixel(int x, int y,const Couleur &c1)
{
	if ((x < 0 || x > dimension.getLargeur()) && (y < 0 || y > dimension.getHauteur())) {
			throw XYException("Coordonnee Pixel invalide !", "d");}
			
			if (x < 0 || x > dimension.getLargeur()) 
				throw XYException("Coordonnee Pixel invalide X !", "x");
			
			if (y < 0 ||  y > dimension.getHauteur()) 
				throw XYException("Coordonnee Pixel invalide Y !", "y");

	matrice[x][y]=c1;
}
void ImageRGB::setBackground(const Couleur &c1)
{
	for(int i=0;i<dimension.getLargeur();i++)
	{
		for(int j=0;j<dimension.getHauteur();j++)
		{
			matrice[i][j]=c1;
		}	
	}
}



// 				OPERATEUR

ImageRGB& ImageRGB::operator=(const ImageRGB& p)
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


std::ostream& operator<<(std::ostream& os,const ImageRGB &i1){

	os << "Id: " << i1.id << "||" << "Nom: " << i1.nom << "||" << "Largeur: " << i1.getDimension().getLargeur() << "||" << "Hauteur: " << i1.getDimension().getHauteur()<< endl;
	return os;
}





void ImageRGB::Affiche()const
{
	cout << "id = " << getId() << endl;
	if (nom == NULL) cout << "pointeur null" << endl;
	cout << "nom = " << getNom() << endl;
 	cout << "Dimension = " << dimension.getLargeur() << " x " << dimension.getHauteur() << endl;
}
void ImageRGB::Dessine() const{
    MyQT::ViewImage(*this);
}

void ImageRGB::importFromFile(const char* fichier){
    MyQT::ImportFromFile(*this, fichier);
}

void ImageRGB::exportToFile(const char* fichier, const char* format)const {
	cout << "fichier" << fichier << endl << "format" << format << endl;
    MyQT::ExportToFile(*this, fichier, format);
}

//			DESTRUCTEUR 
ImageRGB::~ImageRGB()
{
	// cout << "D" << endl << endl;
	// if(nom) delete nom;
cout << "D ImageRGB" << endl;
    for (int i = 0; i < getL_MAX(); i++) {
        for (int j = 0; j < getH_MAX(); j++) {
            matrice[i][j] = Couleur(0,0,0);
        }
    }

}
//		FLUX

void ImageRGB::Save(ofstream & fichierD) const
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
void ImageRGB::Load(ifstream & fichierD)
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
string ImageRGB::getType() const  
{
	return "RGB";
}