#ifndef EXCEPTION_H
#define EXCEPTION_H
// #include "ImageNG.h"
// #include "Dimension.h"

class Exception
{
	protected :
		char* Message; 
	public :
	
		char* getMessage() const;

		void setMessage(const char *);

		Exception();
		Exception(const char *);
		Exception(const Exception& );
	    // Exception(const char* fichier);
	    ~Exception();

};
#endif