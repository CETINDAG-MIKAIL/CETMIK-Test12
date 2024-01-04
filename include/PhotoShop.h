#ifndef PHOTOSHOP_H
#define PHOTOSHOP_H
#include "ArrayList.h"
#include "Image.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
// #include "Dimension.h"
// #include "Exception.h"

class PhotoShop
{
	private:
	ArrayList<Image*> images;
	static int numCourant;
	public:
	PhotoShop();
	~PhotoShop();
	


	void reset();
	void ajouteImage(Image* pImage);

	void afficheImages();
	void dessineImages();
	Image* getImageParIndice(int indice);
	Image* getImageParId(int id);
	void supprimeImageParIndice(int ind);
	void supprimeImageParId(int id);


	
};
#endif