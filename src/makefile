CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: clean
clean:
	rm -f menu.o menu game.o game

game: game.o menu.o
	g++ game.o menu.o -o game $(CXXFLAGS)

menu.o: menu.cpp
	g++ -c menu.cpp $(CXXFLAGS)

game.o: game.hpp game.cpp
	g++ -c game.cpp $(CXXFLAGS)