CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
CC_SFML= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)


%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

main.o : main.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

main : $(OBJ) main.o
	$(CC) $(CCFLAGS) -o $@ $^ $(CC_SFML)

execute : main
	./main

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean :
	rm -f $(OBJ) main.o main