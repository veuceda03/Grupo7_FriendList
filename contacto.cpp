#include "contacto.h"
#include <iostream>
#include <cstring>


Contacto::Contacto(char* nombre, char* numero){
	this->nombre=nombre;
	this->numero= numero;
}

void Contacto::setNombre(char* nombre){
	this->nombre=nombre;
}

void Contacto::setNumero(char* numero){
	this->numero=numero;
}

char* Contacto::getNombre(){
	return nombre;
}

char* Contacto::getNumero(){
	return numero;
}
