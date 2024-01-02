#ifndef IMAGENG_H
#define IMAGENG_H
#include <iostream>
#include "Dimension.h"
#include "Image.h"
using namespace std;


	class ImageNG : public Image 
	{
		private : 

			int matrice[550][550];
			bool compI(const ImageNG& , const char* );


		public :


//		GET

		static int 	getL_MAX();
		static int 	getH_MAX(); 	


	    int 		getLuminance()const;
	    int 		getMinimum()const;
	    int 		getMaximum()const;
	    float		getContraste()const;
		int 		getPixel(int ,int )const;



// 		SET


		void setL_MAX(int);
		void setH_MAX(int);


		void 	setBackground(int );
	    void 	setPixel(int , int, int );
//		CONSTRUCTEUR 


		ImageNG();
		ImageNG(int,const char *);
		ImageNG(int,const char *, Dimension);
		ImageNG(const ImageNG& );
	    ImageNG(const char* fichier);


//		OPERATEUR 

	    
	    ImageNG& operator=(const ImageNG&);

	    ImageNG operator+(int);
	    ImageNG operator-(int);


		ImageNG operator++();
		ImageNG operator++(int);


		ImageNG operator--();
		ImageNG operator--(int);

	    ImageNG operator-(const ImageNG&);

		bool operator==(const ImageNG& );
		bool operator>(const ImageNG& );
		bool operator<(const ImageNG& );

//		FRIEND

	    friend ImageNG operator+(int, ImageNG);
	    friend ImageNG operator-(int, ImageNG);
		friend std::ostream& operator<<(std::ostream& os, const ImageNG& i1);


 	 ~ImageNG();  // Destructeur virtuel
     void Affiche() const override;  // Implémentation de Affiche()
     void Dessine() const override;  // Implémentation de Dessine()
	 void importFromFile(const char* fichier);
     void exportToFile(const char* fichier, const char* format) const override;  // Implémentation de exportToFile()

	// FLUX

	void Save(ofstream & ) const;
	void Load(ifstream & );

	};


	#endif