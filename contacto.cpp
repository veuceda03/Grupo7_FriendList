#include "contacto.h"
#include <iostream>
#include <cstring>

Contacto::Contacto(char* nombre, char* numero, char* amistad){
	this->nombre=nombre;
	this->numero= numero;
	this->amistad=amistad;
}

void Contacto::setNombre(char* nombre){
	this->nombre=nombre;
}

void Contacto::setNumero(char* numero){
	this->numero=numero;
}

void Contacto::setAmistad(char* numero){
	this->amistad=amistad;
}
char* Contacto::getNombre(){
	return nombre;
}

char* Contacto::getNumero(){
	return numero;
}
char* Contacto::getAmistad(){
	return amistad;
}


