CFLAGS = `pkg-config --cflags gtkmm-3.0` -Wall
LFLAGS = `pkg-config --libs gtkmm-3.0`

all: hello

hello: main.o Core.o Module.o Hello.o Coucou.o Audiotheque.o ModuleFactory.o
	g++ -o hello main.o Core.o Module.o Hello.o Coucou.o Audiotheque.o ModuleFactory.o ${LFLAGS}

main.o: Core.hpp main.cpp
	g++ -c main.cpp ${CFLAGS}

Core.o: Core.hpp Core.cpp
	g++ -c Core.cpp ${CFLAGS}

Module.o: Module.hpp Module.cpp
	g++ -c Module.cpp ${CFLAGS}

Hello.o: Hello.hpp Hello.cpp
	g++ -c Hello.cpp ${CFLAGS}

Coucou.o: Coucou.hpp Coucou.cpp
	g++ -c Coucou.cpp ${CFLAGS}

Audiotheque.o: Audiotheque.hpp Audiotheque.cpp
	g++ -c Audiotheque.cpp ${CFLAGS}

ModuleFactory.o: ModuleFactory.hpp ModuleFactory.cpp
	g++ -c ModuleFactory.cpp ${CFLAGS}

clean:
	rm -f *.o
