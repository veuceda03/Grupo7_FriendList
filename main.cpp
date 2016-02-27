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
void ordenar(vector<Contacto>, vector<Contacto>, int);

int main(int argc,char*argv[]){
	vector<Contacto> lista;
	initscr();
	move(10,20); 
	int opcion=menu();	
	cargarContacto(lista);
	clear();
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
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);
	char nombres[10];
	char numero[10];
	bool bandera=false;
	move(10,20);
	attron(COLOR_PAIR(1));
	addstr("Ingresando contacto, solo son aceptadas 9 minúsculas ");
	refresh();
	move(11,20);
	attron(COLOR_PAIR(2));
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
	attron(COLOR_PAIR(3));
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
	char amistad[2];
	addstr("Ingresar Nivel de Amistad: ");
	do{
		char ingresada=getch();
		if(ingresada>=49 && ingresada<=53){
			amistad[0]=ingresada;
			bandera=true;
		}else{
			bandera=false;
		}
	}while(bandera==false);
	amistad[1]='\0';
	refresh();
	move(14,20);	
	addstr(nombres);
	move(15,20);
	addstr(numero);
	move(16,20);
	addstr(amistad);
	Contacto nuevo(nombres,numero,amistad);
	lista.push_back(nuevo);	
	move(17,20);
	addstr("Agregado");
}
int menu(){
	int opcion;
	bool bandera=false;
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);
	init_pair(4,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	addstr(".-*.-*.-MENU-.*.-*.");
	attron(COLOR_PAIR(2));
	addstr("1.-) Agregar Contacto\n");
	attron(COLOR_PAIR(3));
	addstr("2.-) Listar Contacto\n");
	attron(COLOR_PAIR(4));	
	addstr("3.)Salir\n");
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
void ordenar(vector<Contacto> lista, vector<Contacto> lista2, int a){
	if(a==lista.size()){
		return;
	}else{			
		for(int i=a+1; i<lista.size(); i++){
			if(lista.at(i).getAmistad()<lista.at(a).getAmistad()){
				lista2.at(i)=lista.at(a);
				lista.at(a)=lista.at(i);
				lista.at(i)=lista2.at(i);
			}
		}
		ordenar(lista, lista2, a+1);
	}
}

