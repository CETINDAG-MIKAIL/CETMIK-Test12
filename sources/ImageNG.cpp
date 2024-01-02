#include <math.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#include "ImageNG.h"
#include "MyQT.h"
#include "Exception.h"
#include "RGBException.h"
#include "XYException.h"




int ImageNG::getL_MAX(){return 650;};
int ImageNG::getH_MAX(){return 650;};


int ImageNG::getLuminance()const
{
	int somme=0,cpt=0;

	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
            somme += matrice[i][j];
            cpt++;
        }
    }
    if(cpt!=0)
    	return somme/(int)cpt;
    return 0;	
}
int ImageNG::getMinimum()const
{
	int valMin=256;
	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
        	if(valMin > matrice[i][j])
        	{
        		valMin = matrice[i][j];
        	}
        }
    }
    return valMin;
}
int ImageNG::getMaximum()const
{
	int valMax=0;
	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
        	if(valMax < matrice[i][j])
        	{
        		valMax = matrice[i][j];
        	}
        }
    }
    return valMax;
}
float ImageNG::getContraste()const
{
	if (getMaximum() == 0 && getMinimum() == 0) 
	    return 0.0;

	float contraste=0;
	
	contraste = (getMaximum()- getMinimum()) /(float) (getMaximum() + getMinimum());

	return (float)contraste; 

}

int ImageNG::getPixel(int x,int y)const
{
		if ((x < 0 || x > dimension.getLargeur()) && (y < 0 || y > dimension.getHauteur())) {
			throw XYException("Coordonnee Pixel invalide !", "d");}
			
			if (x < 0 || x > dimension.getLargeur()) 
				throw XYException("Coordonnee Pixel invalide X !", "x");
			
			if (y < 0 ||  y > dimension.getHauteur()) 
				throw XYException("Coordonnee Pixel invalide Y !", "y");
	int val = matrice[x][y];
	return val;
}

//						CONSTRUCTEUR
ImageNG::ImageNG() : Image()
{
	for(int i=0;i<getL_MAX();i++)
	{
		for(int j=0; j<getH_MAX();j++)
		{
			matrice[i][j]=0;
		}
	}
}
/////////// constructeur d'initialisation //////////
ImageNG::ImageNG(int nombre, const char *n) :  Image(nombre, n)
{

}
/////////// constructeur d'initialisation + dimension//////////
ImageNG::ImageNG(int nombre, const char *n, Dimension d1) :  Image(nombre, n, d1)
{

}
//////// constructeur de copie //////////////:
ImageNG::ImageNG(const ImageNG& p) :  Image(p)
{
	for(int i=0;i<dimension.getLargeur();i++)
	{
		for(int j=0; j<dimension.getHauteur();j++)
		{
			matrice[i][j]=p.matrice[i][j];
		}
	}
}
ImageNG::ImageNG(const char* fichier) :  Image(fichier)
{
	MyQT::ImportFromFile(*this, fichier);
}

bool ImageNG::compI(const ImageNG& i1, const char* op)
{
	if(dimension != i1.dimension)
		throw(XYException("Dimension invalide pour une comparaison !\n\n", "d"));
	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
       
            if(strcmp(op, "==") == 0 && matrice[i][j] != i1.matrice[i][j])
            	return false;
        	else if((strcmp(op, "<") == 0 && matrice[i][j] >= i1.matrice[i][j]))
        		return false;
        	else if((strcmp(op, ">") == 0 && matrice[i][j] <= i1.matrice[i][j]))
        		return false;
        }

    }
    return true;
	
}
// //				SET

// void ImageNG::setId(int nombre){id=nombre;}


// void ImageNG::setNom(const char *n){ 

// 	if (nom) delete nom;
// 	nom = new char[strlen(n)+1];
// 	strcpy(nom,n);
// }
// void ImageNG::setDimension(Dimension d1) {

//         dimension = d1;
// }

void ImageNG::setPixel(int x, int y, int val)
{
	if ((x < 0 || x > dimension.getLargeur()) && (y < 0 || y > dimension.getHauteur())) {
			throw XYException("Coordonnee Pixel invalide !", "d");}
			
			if (x < 0 || x > dimension.getLargeur()) 
				throw XYException("Coordonnee Pixel invalide X !", "x");
			
			if (y < 0 ||  y > dimension.getHauteur()) 
				throw XYException("Coordonnee Pixel invalide Y !", "y");

	if(val < 0 || val > 255)
		throw(RGBException("niveau de gris invalide", val));
	
	matrice[x][y]=val;
}
void ImageNG::setBackground(int val)
{
	if(val < 0 || val > 255)
		throw(RGBException("niveau de gris invalide", val));
	for(int i=0;i<getL_MAX();i++)
	{
		for(int j=0;j<getH_MAX();j++)
		{
			matrice[i][j]=val;
		}	
	}
}



// 				OPERATEUR

ImageNG& ImageNG::operator=(const ImageNG& p)
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

ImageNG ImageNG::operator+(int add) {
    if (add > 0) {
        ImageNG p2(*this);
        for (int i = 0; i < dimension.getLargeur(); i++) {
            for (int j = 0; j < dimension.getHauteur(); j++) {
                if ((p2.matrice[i][j] + add) < 255) {
                    p2.matrice[i][j] += add;
                } else {
                    p2.matrice[i][j] = 255;                    
                }
            }
        }
        return p2;
    }
    return *this;
}

ImageNG ImageNG::operator-(int add)
{
	if(add > 0)
	{
		ImageNG p2(*this);
		for (int i = 0; i < dimension.getLargeur(); i++) {
	        for (int j = 0; j < dimension.getHauteur(); j++) {
	            if((p2.matrice[i][j]-add) > 0)
	            {
	            	p2.matrice[i][j]-=add;	
	            }
	            else
	            {
	            	p2.matrice[i][j]=0;	
	            }
	        }
	    }
		return p2;	
	}
	return *this;
}
ImageNG operator+(int add,ImageNG i1)
{
	if(add > 0)
		return i1 + add;
	return i1;
	
}
ImageNG ImageNG::operator++()
{
	(*this) = (*this) + 20;
	return (*this);
}
ImageNG ImageNG::operator++(int)
{
	ImageNG i2(*this);
	(*this) = (*this) + 20;
	return i2;
}
ImageNG ImageNG::operator--()
{
	(*this) = (*this) - 20;
	return (*this);
}
ImageNG ImageNG::operator--(int)
{
	ImageNG i2(*this);
	(*this) = (*this) - 20;
	return i2;
}
ImageNG operator-(int add,ImageNG i1)
{
	if(add < 0)
		return i1 + add;
	return i1;
	
}
ImageNG ImageNG::operator-(const ImageNG& i1)
{
	ImageNG i2(*this);

	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
            i2.matrice[i][j] -= i1.matrice[i][j];
            if(i2.matrice[i][j]<0)
            	i2.matrice[i][j]=0;
        }
    }
    return i2;
}
bool ImageNG::operator==(const ImageNG& d)
{
    return compI(d, "==");
}
bool ImageNG::operator<(const ImageNG& d)
{
    return compI(d, "<");
}

bool ImageNG::operator>(const ImageNG& d)
{
    return compI(d, "<");
}



std::ostream& operator<<(std::ostream& os,const ImageNG &i1){
	os << "Id: " << i1.id << "||" << "Nom: " << i1.nom << "||" << "Largeur: " << i1.getDimension().getLargeur() << "||" << "Hauteur: " << i1.getDimension().getHauteur()<< "||" << "Luminance: " << i1.getLuminance() << "||" << "Contraste: " << i1.getContraste() << endl;
	return os;
}





void ImageNG::Affiche()const
{
	cout << "id = " << getId() << endl;
	if (nom == NULL) cout << "pointeur null" << endl;
	cout << "nom = " << getNom() << endl;
 	cout << "Dimension = " << dimension.getLargeur() << " x " << dimension.getHauteur() << endl;
}
void ImageNG::Dessine() const{
    MyQT::ViewImage(*this);
}

void ImageNG::importFromFile(const char* fichier){
    MyQT::ImportFromFile(*this, fichier);
}

void ImageNG::exportToFile(const char* fichier, const char* format)const {
    MyQT::ExportToFile(*this, fichier, format);
}

//			DESTRUCTEUR 
ImageNG::~ImageNG()
{
	// cout << "D" << endl << endl;
	// if(nom) delete nom;
cout << "D ImageNG" << endl;

    for (int i = 0; i < getL_MAX(); i++) {
        for (int j = 0; j < getH_MAX(); j++) {
            matrice[i][j] = 0;
        }
    }
cout << "JE SUIS DANS LE D DE ImageNG"  << endl;
}


//			FLUX


void ImageNG::Save(ofstream & fichierD) const
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
void ImageNG::Load(ifstream & fichierD)
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
