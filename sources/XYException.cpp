#include <math.h>
#include <iostream>
#include <cstring>
#include "XYException.h"
#include "Exception.h"
using namespace std;

/////////////////////////////////// GET
const char * XYException::getCoordonnee()const
{
	return Coordonnee.c_str();	
}

 XYException::XYException(const char* message, const char* typeErreur) : Exception(message), Coordonnee(typeErreur) {}
