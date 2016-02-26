#include <ncurses.h>

using std::cin;
using std:cout;
using std::endl;

int menu();

int main(int argc,char*argv[]){

	return 0;
}

int menu(){
	int opcion;
	cout<<".-*.-*.-MENU-.*.-*."<<endl;
	cout<<"1.-) Agregar Contacto\n2.)Listar Contacto\n3.)Salir\n";
	cin>>opcion;
	return opcion;
}
