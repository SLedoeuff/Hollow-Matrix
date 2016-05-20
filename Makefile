all: creuse

libb.o: libb.cpp libb.h
	g++ -o libb.o -c libb.cpp

app.o: app.cpp app.h
	g++ -o app.o -c app.cpp

main.o: main.cpp libb.h app.cpp app.h
		g++ -o main.o -c main.cpp
creuse: main.o libb.o app.o
	g++ -o creuse main.o libb.o app.o
clean:
	rm *.o
mrproper: clean
	rm creuse