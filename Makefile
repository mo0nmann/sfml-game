all: compile link

compile: Header_Files/Player.h Source_Files/*
	g++ -c Source_Files/* -I./SFML/include

link: main.o	
	g++ main.o player.o -o main.exe -LSFML/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -lopenal32