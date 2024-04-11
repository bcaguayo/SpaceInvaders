CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: clean
clean:
	rm -f menu.o menu

menu: menu.cpp
	g++ -std=c++11 menu.cpp -o menu $(CXXFLAGS)