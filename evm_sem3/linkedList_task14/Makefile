 proga: linked_list_main.o linked_list.o
	g++ linked_list_main.o linked_list.o -o proga
proga_main.o: linked_list_main.cpp linked_list.hpp
	g++ linked_list_main.cpp -c
inheritance.o: linked_list.cpp linked_list.hpp
	g++ linked_list.cpp -c
clean: rm -f *.o proga 
