CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
CC_SFML= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard ../src/*.cpp)
OBJ= $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

test.o : Testcase.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

test : $(OBJ) test.o
	$(CC) $(CCFLAGS) -o $@ $^ $(CC_SFML)

execute : test
	./test

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean :
	rm -f $(OBJ) test.o test
