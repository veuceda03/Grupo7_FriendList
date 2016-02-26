#include "contacto.h"
#include <iostream>
#include <cstring>

Contacto::Contacto(string nombre, char* numero){
	this->nombre=nombre;
	this->numero= numero;
}

void Contacto::setNombre(string nombre){
	this->nombre=nombre;
}

void Contacto::setNumero(char* numero){
	this->numero=numero;
}

string Contacto::getNombre(){
	return nombre;
}

char* Contacto::getNumero(){
	return numero;
}


