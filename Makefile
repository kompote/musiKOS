CFLAGS = `pkg-config --cflags gtkmm-3.0` -Wall
LFLAGS = `pkg-config --libs gtkmm-3.0`
SRC = src/
BIN = bin/


all: musikos

musikos: ${BIN}main.o ${BIN}Core.o ${BIN}Module.o ${BIN}Hello.o ${BIN}Coucou.o ${BIN}ModuleFactory.o ${BIN}Player.o ${BIN}Audiotheque.o
	g++ -o musikos ${BIN}main.o ${BIN}Core.o ${BIN}Module.o ${BIN}Hello.o ${BIN}Coucou.o ${BIN}ModuleFactory.o ${BIN}Player.o ${BIN}Audiotheque.o ${LFLAGS} -lvlc

${BIN}main.o: ${SRC}main.cpp 
	g++ -o ${BIN}main.o -c ${SRC}main.cpp ${CFLAGS}

${BIN}Core.o: ${SRC}Core.cpp ${SRC}Core.hpp
	g++ -o ${BIN}Core.o -c ${SRC}Core.cpp ${CFLAGS}

${BIN}Module.o: ${SRC}Module.cpp ${SRC}Module.hpp
	g++ -o ${BIN}Module.o -c ${SRC}Module.cpp ${CFLAGS}

${BIN}Hello.o: ${SRC}Hello.cpp ${SRC}Hello.hpp
	g++ -o ${BIN}Hello.o -c ${SRC}Hello.cpp ${CFLAGS}

${BIN}Coucou.o: ${SRC}Coucou.cpp ${SRC}Coucou.hpp
	g++ -o ${BIN}Coucou.o -c ${SRC}Coucou.cpp ${CFLAGS}

${BIN}Player.o: ${SRC}Player.cpp ${SRC}Player.hpp
	g++ -o ${BIN}Player.o -c ${SRC}Player.cpp ${CFLAGS}

${BIN}Audiotheque.o: ${SRC}Audiotheque.hpp ${SRC}Audiotheque.cpp
	g++ -o ${BIN}Audiotheque.o -c ${SRC}Audiotheque.cpp ${CFLAGS}	

${BIN}ModuleFactory.o: ${SRC}ModuleFactory.cpp
	g++ -o ${BIN}ModuleFactory.o -c ${SRC}ModuleFactory.cpp ${CFLAGS}

clean:
	rm -f ${BIN}*
