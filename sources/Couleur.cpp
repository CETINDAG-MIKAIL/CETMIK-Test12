#include <math.h>
#include <iostream>
#include <cstring>
#include <fstream>



using namespace std;
#include "Couleur.h"
#include "MyQT.h"
#include "RGBException.h"
// #include "Dimension.h"



Couleur Couleur::ROUGE{255,0,0};
Couleur Couleur::VERT{0,255,0};
Couleur Couleur::BLEU{0,0,255};
Couleur Couleur::BLANC{0,0,0};
Couleur Couleur::NOIR{255,255,255};


//			GET
int Couleur::getRouge()const{return rouge;}
int Couleur::getVert() const{return vert;}
int Couleur::getBleu() const{return bleu;}



//			SET
void Couleur::setRouge(int r1) {
    if (r1 < 0 || r1 > 255) {
        throw RGBException("Composant rouge invalide\n", r1);
    }
    rouge = r1;
}
void Couleur::setVert(int v1) {
    if (v1 < 0 || v1 > 255) {
        throw RGBException("Composant vert invalide\n", v1);
    }
    vert = v1;
}

void Couleur::setBleu(int b1) {
    if (b1 < 0 || b1 > 255) {
        throw RGBException("Composant bleu invalide\n", b1);
    }
    bleu = b1;
}



//			CONSTRUCTEUR


Couleur::Couleur()
{
	setRouge(0);
	setVert(0);
	setBleu(0);
}

Couleur::Couleur(int r1,int v1,int b1)
{
	setRouge(r1);
	setVert(v1);
	setBleu(b1);
}

Couleur::Couleur(const Couleur& c1)
{
	setRouge(c1.getRouge());
	setVert(c1.getVert());
	setBleu(c1.getBleu());
}


std::ostream& operator<<(std::ostream& os, const Couleur& c1)
{
	os << "rouge : " << c1.getRouge() << "	vert : " << c1.getVert() << "	bleu : " << c1.getBleu() << endl;
	return os;
}
void Couleur::Affiche()
{
	cout << "rouge = " << getRouge() << endl;
	cout << "vert = " << getVert() << endl;
 	cout << "bleu = " << getBleu() << endl;
 	cout << endl;
}

//		FLUX

void Couleur::Save(ofstream & fichierD) const
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
void Couleur::Load(ifstream & fichierD)
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