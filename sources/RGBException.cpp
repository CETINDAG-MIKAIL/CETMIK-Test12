#include <math.h>
#include <iostream>
#include <cstring>
#include "RGBException.h"
#include "Exception.h"
using namespace std;

/////////////////////////////////// GET
int RGBException::getValeur()const
{
	return Valeur;	
}
RGBException::RGBException(const char* message, int valeur) : Exception(message){
	Valeur=valeur;
}
