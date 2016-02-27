#include "contacto.h"
#include <iostream>
#include <cstring>
#include <ncurses.h>

Contacto::Contacto(char* nombre, char* numero, char* amistad){
	this->nombre=nombre;
	this->numero= numero;
	this->amistad=amistad;
}
using namespace std;
Contacto::Contacto(){
	nombre=new char[10];
	numero=new char[10];
	amistad=new char[2];
}

/*Contacto::Contacto(char* nombres, char* numeros, char* amistad){
	setNombre(nombre);
}*/

void Contacto::setNombre(char* nombre){
	this->nombre= new char[10];
	strcpy(this->nombre,nombre);
}

void Contacto::setNumero(char* numero){
	this->numero= new char[10];
	strcpy(this->numero,numero);
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

void Contacto::imprimirNumero(){
	for(int i=0;i<9;i++){
		addch(numero[i]);
	}
}
void Contacto::imprimirNombre(){
	for(int i=0;i<9;i++){
		addch(nombre[i]);
	}
}


