CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: clean
clean:
	rm -f menu.o menu

menu: menu.cpp
	g++ -c menu.cpp
	g++ menu.o -o menu $(CXXFLAGS)
