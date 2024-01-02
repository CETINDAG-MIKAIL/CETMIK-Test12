#ifndef IMAGE_H
#define IMAGE_H
// #include "ImageNG.h"
#include "Dimension.h"


class Image 
{
	protected: 
		int id;
		char* nom;
		Dimension dimension;
	public:

		int 		getId()const;
		char* 		getNom() const ;
		Dimension 	getDimension() const;

		void setId(int);
		void setNom(const char *);
		void setDimension(Dimension);

		Image();
		Image(int ,const char *);
		Image(int , const char *, Dimension );
		Image(const Image& );
		Image(const char* );
		
		void Affiche();
		virtual ~Image();
	    virtual void Affiche() const = 0;  
	    virtual void Dessine() const = 0;  
	    virtual void exportToFile(const char* fichier, const char* format) const = 0;

};
#endif