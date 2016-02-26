#include <ncurses.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

using std::cin;
using std:cout;
using std::endl;

int menu();


//void cargarContacto(vector);
void cargarContacto();

int main(int argc,char*argv[]){
	//vector<Contacto> lista;
	initscr();
	cargarContacto();
	
	getch();
	endwin();
	return 0;
}


void cargarContacto(){//vector lista){
	char nombres[10];
	bool bandera=false;
	move(10,20); 
	addstr("Ingresando contacto");
	refresh();
	move(11,20);
	addstr("Nombre: ");
	for(int i=0;i<9;i++){
		do{
			char ingresada=getch();
			if(ingresada>=){

			}
		}while(bandera==false);
		
	}
	nombres[9]='\0';
	refresh();
	move(13,20);
	addstr(nombres);		

int menu(){
	int opcion;
	cout<<".-*.-*.-MENU-.*.-*."<<endl;
	cout<<"1.-) Agregar Contacto\n2.)Listar Contacto\n3.)Salir\n";
	cin>>opcion;
	return opcion;
}
