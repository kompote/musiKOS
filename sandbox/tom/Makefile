CFLAGS = `pkg-config --cflags gtkmm-3.0` -Wall
LFLAGS = `pkg-config --libs gtkmm-3.0`
SRC = src/
BIN = bin/


all: hello

hello: ${BIN}main.o ${BIN}Core.o ${BIN}Module.o ${BIN}Hello.o ${BIN}Coucou.o ${BIN}ModuleFactory.o ${BIN}Player.o ${BIN}PlayerMain.o
	colorgcc -o hello ${BIN}main.o ${BIN}Core.o ${BIN}Module.o ${BIN}Hello.o ${BIN}Coucou.o ${BIN}ModuleFactory.o ${BIN}Player.o ${BIN}PlayerMain.o ${LFLAGS} -lvlc

${BIN}main.o: ${SRC}main.cpp 
	g++ -o ${BIN}main.o -c ${SRC}main.cpp ${CFLAGS}

${BIN}Core.o: ${SRC}Core.cpp ${SRC}Hello.cpp
	g++ -o ${BIN}Core.o -c ${SRC}Core.cpp ${CFLAGS}

${BIN}Module.o: ${SRC}Module.cpp ${SRC}Module.hpp 
	g++ -o ${BIN}Module.o -c ${SRC}Module.cpp ${CFLAGS}

${BIN}Hello.o: ${SRC}Hello.cpp
	g++ -o ${BIN}Hello.o -c ${SRC}Hello.cpp ${CFLAGS}

${BIN}Coucou.o: ${SRC}Coucou.cpp
	g++ -o ${BIN}Coucou.o -c ${SRC}Coucou.cpp ${CFLAGS}

${BIN}Player.o: ${SRC}Player.cpp ${SRC}Player.hpp ${SRC}PlayerMain.hpp
	colorgcc -o ${BIN}Player.o -c ${SRC}Player.cpp ${CFLAGS}

${BIN}PlayerMain.o: ${SRC}PlayerMain.cpp ${SRC}PlayerMain.hpp
	colorgcc -o ${BIN}PlayerMain.o -c ${SRC}PlayerMain.cpp ${CFLAGS}

${BIN}ModuleFactory.o: ${SRC}ModuleFactory.cpp
	g++ -o ${BIN}ModuleFactory.o -c ${SRC}ModuleFactory.cpp ${CFLAGS}

clean:
	rm -f ${BIN}*
