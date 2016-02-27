#ifndef CONTACTO_H
#define CONTACTO_H

class Contacto{

	char* nombre;
	char* numero;
	char* amistad;
	

	public:
		Contacto(char*, char*, char*);

	public:		
		Contacto(char*, char*);
		Contacto();

		void setNombre(char* nombre);
		void setNumero(char* numero);
		void setAmistad(char* amistad);		
		char* getNombre();
		char* getNumero();
		char* getAmistad();								
		void imprimirNumero();
		void imprimirNombre();
								
};

#endif


