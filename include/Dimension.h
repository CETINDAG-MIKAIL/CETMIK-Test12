#ifndef DIMENSION_H
#define DIMENSION_H
#include <iostream>
using namespace std;

// #include "ImageNG.h"
// #include "Dimension.h"


class Dimension
{ 
	private :

		int largeur;
		int hauteur; 
		int compD(const Dimension& );



	public : 

		static Dimension VGA;
		static Dimension HD;
		static Dimension FULL_HD;


		int getLargeur()const;
		int getHauteur()const;

		friend std::ostream& operator<<(std::ostream& os, const Dimension& d1);
		friend std::istream& operator>>(std::istream& is,  Dimension& d1);


		int operator==(const Dimension& );
		int operator!=(const Dimension& );


		void setLargeur(int);
		void setHauteur(int);

		void Affiche();

		Dimension();
		~Dimension();
		Dimension(int,int);
		Dimension(int,int,Dimension);
		Dimension(const Dimension &p);


// FLUX
		void Save(ofstream & ) const;
		void Load(ifstream & );



};
#endif