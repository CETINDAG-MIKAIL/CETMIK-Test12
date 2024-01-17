#ifndef IMAGEB_H
#define IMAGEB_H
#include <iostream>
#include "Dimension.h"
#include "Couleur.h"
#include "Image.h"
// #include "MyQT.h"



	class ImageB : public Image 
	{
		private : 
			bool matrice[550][550];
		public :


//		GET
		static Couleur couleurTrue;
		static Couleur couleurFalse;
		static int 	getL_MAX();
		static int 	getH_MAX(); 	

		
		bool 	getPixel(int ,int )const;



// 		SET



		void 	setBackground(bool );
	    void 	setPixel(int , int, bool  );
//		CONSTRUCTEUR 


		ImageB();
		ImageB(int,const char *);
		ImageB(int,const char *, Dimension);
		ImageB(const ImageB& );
	    ImageB(const char* fichier);


//		OPERATEUR 

	    
	    ImageB& operator=(const ImageB&);

	
		friend std::ostream& operator<<(std::ostream& os, const ImageB& i1);


 	 ~ImageB();  // Destructeur virtuel
     void Affiche() const override;  // Implémentation de Affiche()
     void Dessine() const;  // Implémentation de Dessine()
	 // void importFromFile(const char* fichier);
     void exportToFile(const char* fichier, const char* format) const;  // Implémentation de exportToFile()


// 		FLUX


     	void Save(ofstream & fichier) const;
		void Load(ifstream & fichier);

		std::string getType() const override;
	};
	#endif