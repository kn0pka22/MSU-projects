 
proga: inheritance_main.o inheritance.o
	g++ inheritance_main.o inheritance.o -o proga
proga_main.o: inheritance_main.cpp inheritance.hpp
	g++ inheritance_main.cpp -c
inheritance.o: inheritance.cpp inheritance.hpp
	g++ inheritance.cpp -c
clean: rm -f *.o proga 
