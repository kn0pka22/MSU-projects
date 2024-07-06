 proga: trees_main.o trees.o
	g++ trees_main.o trees.o -o proga
proga_main.o: trees_main.cpp trees.hpp
	g++ trees_main.cpp -c
trees.o: trees.cpp trees.hpp
	g++ trees.cpp -c
clean: rm -f *.o proga 
