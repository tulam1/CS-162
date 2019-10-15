CC = g++
exe_file = wizard_catalog

$(exe_file): wizard_cat.o wizard_function.o
	$(CC) wizard_cat.o wizard_function.o -o $(exe_file) $(CFLAGS)
wizard_cat.o: wizard_cat.cpp
	$(CC) -c wizard_cat.cpp $(CFLAGS)
wizard_function.o: wizard_function.cpp
	$(CC) -c wizard_function.cpp $(CFLAGS)

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean

