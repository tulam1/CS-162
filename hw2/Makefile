CC = g++
exe_file = pizza_portal
$(exe_file): menu.o pizza.o restaurant.o implement.o pizza_portal.o
	$(CC) menu.o pizza.o restaurant.o implement.o pizza_portal.o -o $(exe_file)
menu.o: menu.cpp
	$(CC) -c menu.cpp
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
restaurant.o: restaurant.cpp
	$(CC) -c restaurant.cpp
implement.o: implement.cpp
	$(CC) -c implement.cpp
pizza_portal.o: pizza_portal.cpp
	$(CC) -c pizza_portal.cpp
clean:
	rm -f *.out *.o $(exe_file)
