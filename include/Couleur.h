#ifndef COULEUR_H
#define COULEUR_H
#include <iostream>
// #include "ImageNG.h"
// #include "Dimension.h"


class Couleur 
{

	private: 
		int rouge;
		int vert;
		int bleu;
	public:

		static Couleur ROUGE;
		static Couleur VERT;
		static Couleur BLEU;
		static Couleur BLANC;
		static Couleur NOIR;



		int 	getRouge()const;
		int 	getVert() const;
		int 	getBleu() const;

		void 	setRouge(int);
		void 	setVert(int);
		void 	setBleu(int);

		Couleur();
		Couleur(int,int,int);
		Couleur(const Couleur& );

		void Affiche();

		friend std::ostream& operator<<(std::ostream& os, const Couleur& couleur);


// 		FLUX


     	void Save(ofstream & fichier) const;
		void Load(ifstream & fichier);

};
#endif