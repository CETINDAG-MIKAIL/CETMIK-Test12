#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;
#include "Exception.h"

// #include "Image.h"
// #include "MyQT.h"
// #include "Dimension.h"

//////////////////////////////// GET				

char* Exception::getMessage() const
{
	return Message;
}

//////////////////////////////// SET				

void Exception::setMessage(const char *n)
{
	if (Message) delete[] Message;
	Message = new char[strlen(n)+1];
	strcpy(Message,n);
}



//////////////////////////////// CONSTRUCTEUR				
Exception::Exception()
{
	Message=nullptr;
	setMessage("Erreur");

}

Exception::Exception(const char *n)
{
	Message = nullptr;
	setMessage(n);
}
/////////// constructeur de copie //////////
Exception::Exception(const Exception& p) : Message(nullptr) {
    setMessage(p.Message);
}
Exception::~Exception() {
    if (Message) delete[] Message;
}