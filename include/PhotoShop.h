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
	static PhotoShop instance;
	
	PhotoShop();
	PhotoShop(PhotoShop&);
	PhotoShop& operator=(const PhotoShop&);
	
	public:
	
	static PhotoShop& getInstance();
	
	static Image* operande1;
	static Image* operande2;
	static Image* resultat;


	~PhotoShop();
	


	void reset();
	void ajouteImage(Image* pImage);

	void afficheImages();
	void dessineImages();
	Image* getImageParIndice(int indice);
	Image* getImageParId(int id);
	void supprimeImageParIndice(int ind);
	void supprimeImageParId(int id);
	ArrayList<Image*>& getImages();

	
};
#endif