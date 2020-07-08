all: compile link

compile: main.cpp Header_Files/Player.h Source_Files/Player.cpp
	g++ -c Source_Files/Player.cpp main.cpp -I./SFML/include

link: main.o	
	g++ main.o player.o -o main.exe -LSFML/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -lopenal32