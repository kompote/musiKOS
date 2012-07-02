CFLAGS = `pkg-config --cflags gtkmm-3.0`
LFLAGS = `pkg-config --libs gtkmm-3.0`

all: hello

hello: main.o Core.o Module.o Hello.o Coucou.o ModuleFactory.o
	g++ -o hello main.o Core.o Module.o Hello.o Coucou.o ModuleFactory.o ${LFLAGS}

main.o: Core.hpp
	g++ -c main.cpp ${CFLAGS}

Core.o: Core.hpp Hello.hpp
	g++ -c Core.cpp ${CFLAGS}

Module.o: Module.hpp
	g++ -c Module.cpp ${CFLAGS}

Hello.o: Hello.hpp
	g++ -c Hello.cpp ${CFLAGS}

Coucou.o: Coucou.hpp
	g++ -c Coucou.cpp ${CFLAGS}

ModuleFactory.o: ModuleFactory.hpp
	g++ -c ModuleFactory.cpp ${CFLAGS}

clean:
	rm -f *.o
