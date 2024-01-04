#include <math.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#include "Dimension.h"
#include "XYException.h"

//#include "MyQT.h"




///////////// constructeur par default //////////////
Dimension::Dimension()
{
	setLargeur(550);
	setHauteur(550);
}

std::ostream& operator<<(std::ostream& os, const Dimension& d1)
{
	os << d1.getLargeur()<<"x"	<< d1.getHauteur(); 
	return os;	
}

std::istream& operator>>(std::istream& is, Dimension& d1)
{
	cout << "Entrez la largeur :" << endl;
	cin >> d1.largeur;

	cout << "Entrez la hauteur :" << endl; 
	cin >> d1.hauteur;
	if (d1.largeur < 1 || d1.hauteur < 1) {
	        if (d1.largeur < 1 && d1.hauteur < 1) 
	            throw XYException("Dimension invalide !\n", "d");
	        
	        if (d1.largeur < 1) 
	            throw XYException("Largeur invalide !", "x");
	        
	        if (d1.hauteur < 1) 
	            throw XYException("Hauteur invalide !\n", "y");
	        
	    }
	return is;	
}



///////////// constructeur initialisation //////////////
Dimension::Dimension(int l, int h)
{
	if(l < 0 && h < 0)
		throw(XYException("Dimension doit être superieur a 0 !\n", "d"));
	
	if(l<0)
		throw(XYException("Largeur doit être superieur a 0 !\n", "x"));
	setLargeur(l);

	if(h<0)
			throw(XYException("Hauteur doit être superieur a 0 !\n", "y"));
	setHauteur(h);
}
/*
///////////// constructeur initialisation + DIMENSION//////////////
Dimension::Dimension(int l, int h, Dimension d1)
{
	setLargeur(l);
	setHauteur(h);
	setDimension(d1);
}
*/

///////////// constructeur copie //////////////
Dimension::Dimension(const Dimension& p)
{
	if(p.largeur < 0 && p.hauteur < 0)
		throw(XYException("Dimension doit être superieur a 0 !\n", "d"));

	if(p.largeur<0)
		throw(XYException("Largeur doit être superieur a 0 !\n", "x"));
	setLargeur(p.largeur);

	if(p.hauteur<0)
			throw(XYException("Hauteur doit être superieur a 0 !\n", "y"));
	setHauteur(p.hauteur);
}


/////////// Destructeur ////////////////////
Dimension::~Dimension()
{
	// cout << "D Dimension" << endl;
	setLargeur(0);
	setHauteur(0);
}

int Dimension::getLargeur()const{return largeur;}
int Dimension::getHauteur()const{return hauteur;}

void Dimension::setLargeur(int l){

	if(l<0)
		throw(XYException("Largeur doit être superieur a 0 !\n", "x"));
	largeur=l;
}

void Dimension::setHauteur(int h){
	if(h<0)
		throw(XYException("Hauteur doit être superieur a 0 !\n", "y"));
	hauteur=h;
}
void Dimension::Affiche()
{
	cout << "largeur :" << getLargeur() << endl;
	cout << "hauteur :" << getHauteur() << endl;
}
Dimension Dimension::VGA{640,480};
Dimension Dimension::HD{1280,720};
Dimension Dimension::FULL_HD{1920,1080};
/*
Dimension d(Dimension::HD);
Dimension::Dimension(const Dimension& p)
*/
int Dimension::operator==(const Dimension& d)
{
    return compD(d) == 0;
}

int Dimension::operator!=(const Dimension& d)
{
    return compD(d) != 0;
}


int Dimension::compD(const Dimension& d)
{
	if((largeur == d.largeur) && (hauteur == d.hauteur))
		return 0;		
	return 1;
}
void Dimension::Save(ofstream & fichierD) const
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
void Dimension::Load(ifstream & fichierD) 
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



