main: main.o Plato.o Ingrediente.o
	g++ main.o Ingrediente.o Plato.o -o main

main.o:	main.cpp Ingrediente.h Plato.h
	g++ -c main.cpp
Ingrediente.o: Ingrediente.cpp Ingrediente.h
	g++ -c Ingrediente.cpp
Plato.o: Plato.cpp Plato.h Ingrediente.h
	g++ -c Plato.cpp
clean:
	rm *.o	