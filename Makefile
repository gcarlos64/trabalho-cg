CC=g++
CFLAGS=-Wall -Werror -Wextra -Wunused-but-set-variable -pedantic -w -std=c++11
LIBS=-lGL -lGLU -lglut

all: main

main: main.cpp
	$(CC) $(CFLAGS) -o main *.cpp $(LIBS)

clean:
	rm -f main

