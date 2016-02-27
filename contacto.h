#ifndef CONTACTO_H
#define CONTACTO_H

class Contacto{

	char* nombre;
	char* numero;
	
	public:		
		Contacto(char*, char*);
		Contacto();
		void setNombre(char* nombre);
		void setNumero(char* numero);
		char* getNombre();
		char* getNumero();
		void imprimirNumero();
		void imprimirNombre();
								
};

#endif


