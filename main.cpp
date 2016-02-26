#include <ncurses.h>
#include <vector>
#include "contacto.h"
#include <string>
#include <iostream>

using std::string;
using std::vector;

using std::cin;
using std::cout;
using std::endl;

int menu();

void cargarContacto(vector<Contacto>);
int main(int argc,char*argv[]){
	vector<Contacto> lista;
	initscr();
	move(10,20); 
	int opcion=menu();	
    if(opcion==49){
        cargarContacto(lista);
    }else if(opcion==50){

    }else{

    }
	getch();
	endwin();
	return 0;
}


void cargarContacto(vector<Contacto> lista){
	char nombres[10];
	char numero[10];
	bool bandera=false;
	move(10,20); 
	addstr("Ingresando contacto, solo son aceptadas 9 minúsculas ");
	refresh();
	move(11,20);
	addstr("Nombre: ");
	for(int i=0;i<9;i++){
		do{
			char ingresada=getch();
			if(ingresada>=97 && ingresada<=122){
				nombres[i]=ingresada;
				bandera=true;
			}else{
				bandera=false;
			}
		}while(bandera==false);
		
	}
	nombres[9]='\0';
	refresh();
	move(12,20);
	addstr("Número: ");
	for(int i=0;i<9;i++){
		do{
			char ingresada=getch();
			if(i==4){
				if(ingresada==45){
					numero[i]=ingresada;
					bandera=true;
				}else{
					bandera=false;
				}
			}else{
				if(ingresada>=48 && ingresada<=57){
					numero[i]=ingresada;
					bandera=true;
				}else{
					bandera=false;
				}
			}
		}while(bandera==false);
		
	}
	numero[9]='\0';
	refresh();
	move(13,20);
	addstr(nombres);
	move(14,20);
	addstr(numero);
	Contacto nuevo(nombres,numero);
	lista.push_back(nuevo);	
	move(15,20);
	addstr("Agregado");
}
int menu(){
	int opcion;
	addstr(".-*.-*.-MENU-.*.-*.");
	addstr("1.-) Agregar Contacto\n2.) Listar Contacto\n3.)Salir\n");
	for(int i=0;i<9;i++){
		do{
			char ingresada=getch();
			if(ingresada==49 || ingresada==50 || ingresada==51){
				opcion=ingresada;
				bandera=true;
			}else{
				bandera=false;
			}
		}while(bandera==false);
	}
	
	return opcion;
}
