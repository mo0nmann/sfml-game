all: compile link

compile: main.cpp
	g++ -c main.cpp -I./SFML/include

link: main.o	
	g++ main.o -o main.exe -LSFML/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -lopenal32