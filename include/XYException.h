#ifndef XYEXCEPTION_H
#define XYEXCEPTION_H
// #include "ImageNG.h"
// #include "Dimension.h"
#include "Exception.h"
#include <string>

class XYException : public Exception
{
	private :
		std::string Coordonnee;
	public :
	
	//////////////////////////// GET

	const char* getCoordonnee()const;

	XYException(const char*, const char*  );


};
#endif