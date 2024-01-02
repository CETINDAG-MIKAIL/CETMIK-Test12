#ifndef RGBEXCEPTION_H
#define RGBEXCEPTION_H
// #include "ImageNG.h"
// #include "Dimension.h"
#include "Exception.h"

class RGBException : public Exception
{
	private :
		int Valeur; 
	public :
	
	//////////////////////////// GET

	int getValeur()const;

	RGBException(const char *, int  );


};
#endif