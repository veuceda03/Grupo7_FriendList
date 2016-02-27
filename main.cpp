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
void escribir(vector<Contacto>);
void cargarContacto(vector<Contacto>);

int main(int argc,char*argv[]){
	vector<Contacto> lista;
    int opcion;
	initscr();
    bool ejecutando=true;  
    do{
        move(0,20); 
	    opcion=menu();	
        refresh();
        clear();
        refresh();
        if(opcion==49){
            cargarContacto(lista);
            //clear();
            refresh();
        }else if(opcion==50){
            clear();         
            escribir(lista);
            refresh();
        }else{
            ejecutando=false;
        }
    }while(ejecutando==true);
	getch();
	endwin();
    cout<<opcion;
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
            noecho();
			char ingresada;
            if((ingresada=getch())!='\n'){
                if(ingresada>=97 && ingresada<=122){
				    echo();
                    addch(ingresada);                    
                    nombres[i]=ingresada;
				    bandera=true;
			    }else{
                    noecho();
				    bandera=false;
			    }
            }
			
		}while(bandera==false);
	}
	nombres[9]='\0';
	refresh();
	move(12,20);
	addstr("Número: ");
	for(int i=0;i<9;i++){
		do{
            noecho();
			char ingresada;
            if((ingresada=getch())!='\n'){
                if(i==4){
				    if(ingresada==45){
                        addch(ingresada); 
					    numero[i]=ingresada;
					    bandera=true;
				    }else{
					    bandera=false;
				    }
			    }else{
				    if(ingresada>=48 && ingresada<=57){
                        addch(ingresada); 					    
                        numero[i]=ingresada;
					    bandera=true;
				    }else{
					    bandera=false;
				    }
			    }

            }
			
		}while(bandera==false);
		
	}
	numero[9]='\0';
	refresh();
    move(14,20);
    addstr("Su nuevo contacto es: ");
	move(15,20);
	addstr(nombres);
	move(16,20);
	addstr(numero);
	Contacto nuevo(nombres,numero);
	lista.push_back(nuevo);
    getch();
    clear();
}

int menu(){
	int opcion;
    bool bandera=false;
	addstr(".-*.-*.-MENU-.*.-*.\n");
	addstr("1.-) Agregar Contacto\n2.) Listar Contacto\n3.)Salir\n");
	do{
		char ingresada=getch();
		if(ingresada==49 || ingresada==50 || ingresada==51){
			opcion=ingresada;
			bandera=true;
		}else{
			bandera=false;
		}
	}while(bandera==false);

	return opcion;
}
void escribir(vector<Contacto> lista){
    refresh();
    clear();
    move(1,20);
    addstr("Nombre\t   Número");
    move(2,20);
    addch(sizeof(lista));  
    int x=2,y=20;
    for(int i=0;i<lista.size();i++){
        Contacto temp=lista[i];
        char* numero=temp.getNumero();
        char* nombre=temp.getNombre();
        move(x,y);
        x++;
        y++;
        for(int j=0;j<9;j++){
            addch(nombre[j]);
        }     
        addstr("\t");
        for(int j=0;j<9;j++){
            addch(numero[j]);
        }   
    }
    getch();
    clear();
}
