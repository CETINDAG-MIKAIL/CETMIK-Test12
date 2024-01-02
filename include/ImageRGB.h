#ifndef IMAGERGB_H
#define IMAGERGB_H
#include <iostream>
#include "Dimension.h"
#include "Couleur.h"
#include "Image.h"
// #include "MyQT.h"



	class ImageRGB : public Image 
	{
		private : 

			// int id;
			// char* nom;
			// Dimension dimension;
			Couleur matrice[300][300];
			// bool compI(const ImageRGB& , const char* );


		public :


//		GET

		static int 	getL_MAX();
		static int 	getH_MAX(); 	

		Couleur 	getPixel(int ,int )const;



// 		SET

		void 	setBackground(const Couleur& );
	    void 	setPixel(int , int, const Couleur& );
//		CONSTRUCTEUR 


		ImageRGB();
		ImageRGB(int,const char *);
		ImageRGB(int,const char *, Dimension);
		ImageRGB(const ImageRGB& );
	    ImageRGB(const char* fichier);


//		OPERATEUR 

	    
	    ImageRGB& operator=(const ImageRGB&);

	
		friend std::ostream& operator<<(std::ostream& os, const ImageRGB& i1);


 	 ~ImageRGB();  // Destructeur virtuel
     void Affiche() const;  // Implémentation de Affiche()
     void Dessine() const;  // Implémentation de Dessine()
	 void importFromFile(const char* fichier);
     void exportToFile(const char* fichier, const char* format) const;  // Implémentation de exportToFile()

// 		FLUX


     	void Save(ofstream & fichier) const;
		void Load(ifstream & fichier);
	};
	#endif