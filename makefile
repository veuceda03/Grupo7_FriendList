FriendList.exe:	main.o contacto.o
	g++ main.o contacto.o -lncurses

main.o:	main.cpp contacto.h
	g++ -c main.cpp -lncurses

contacto.o:	contacto.h contacto.cpp
	g++ -c contacto.cpp	
