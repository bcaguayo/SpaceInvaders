CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: clean
clean:
	rm -f menu.o menu game.o game

# menu: menu.cpp
# 	g++ -c menu.cpp
# 	g++ menu.o -o menu $(CXXFLAGS)

# game: game.hpp game.cpp
# 	g++ -c game.cpp
# 	g++ game.o -o game $(CXXFLAGS)

game: game.hpp game.cpp menu.cpp
	g++ -c game.cpp
	g++ -c menu.cpp
	g++ game.o menu.o -o game $(CXXFLAGS)