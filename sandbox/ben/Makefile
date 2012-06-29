CFLAGS = `pkg-config --cflags gtkmm-3.0`
LFLAGS = `pkg-config --libs gtkmm-3.0`

all: hello

hello: main.o Core.o Hello.o Coucou.o
	g++ -o hello main.o Core.o Hello.o Coucou.o ${LFLAGS}

main.o: Core.hpp
	g++ -c main.cpp ${CFLAGS}

Core.o: Core.hpp Hello.hpp
	g++ -c Core.cpp ${CFLAGS}

Hello.o: Hello.hpp
	g++ -c Hello.cpp ${CFLAGS}

Coucou.o: Coucou.hpp
	g++ -c Coucou.cpp ${CFLAGS}

clean:
	rm -f *.o
