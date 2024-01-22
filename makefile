CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
CC_SFML= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)


%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

main.o : main.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

main : $(OBJ) main.o
	$(CC) $(CCFLAGS) -o $@ $^ $(CC_SFML)

test.o : Testcase.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

test : $(OBJ) test.o
	$(CC) $(CCFLAGS) -o $@ $^ $(CC_SFML)

execute_test : test
	./test

execute : main
	./main

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean :
	rm -f $(OBJ) main.o main