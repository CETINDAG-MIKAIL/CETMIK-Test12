#ifndef TRAITEMENTS_H
#define TRAITEMENTS_H
// #include "ImageNG.h"
// #include "Dimension.h"
#include "Dimension.h"
#include "ImageNG.h"
#include "Exception.h"
#include "ImageB.h"
#include "ArrayList.h"
#include "SortedArrayList.h"


class Traitements : public Image
{
	private :


	public :
	
	//////////////////////////// GET
	static ImageB Seuillage(const ImageNG& imageIn, int seuil);

	static ImageNG FiltreMoyenneur(const ImageNG& imageIn, int taille);
	static ImageNG FiltreMedian(const ImageNG& imageIn, int taille) ;
	static ImageNG Erosion(const ImageNG& imageIn, int taille);
	static ImageNG Dilatation(const ImageNG& imageIn, int taille);
	static ImageNG Negatif(const ImageNG& imageIn);


};
#endif