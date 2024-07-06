proga: proga_main.o database.o
		g++ proga_main.o database.o -o proga
proga_main.o: proga_main.cpp
		g++ proga_main.cpp -c
database.o: database.cpp database.hpp
	g++ database.cpp -c
clean: rm -f *.o proga
