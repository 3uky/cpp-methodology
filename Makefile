# Define required macros here
SHELL = /bin/sh

OBJS =  main.o
CFLAGS = -Wall -g -pthread -lboost_system
CC = g++
INCLUDES = -I include
LIBS = -lm

main: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}
.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
		
clean:
	-rm -f *.o core *.core

