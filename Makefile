SOURCE = Board.cpp Game.cpp main.cpp
SOURCE_O = $(SOURCE:.cpp=.o)

CPPC = g++ -Wall -std=c++11

.PHONY: all
.PHONY: clean

all: connect4

connect4: $(SOURCE_O)
	$(CPPC) -o $@ $(SOURCE_O)

Board.o: Board.cpp Board.h
	$(CPPC) -c Board.cpp

main.o: main.cpp Game.h
	$(CPPC) -c main.cpp

Game.o: Game.cpp Game.h Board.h
	$(CPPC) -c Game.cpp

clean:
	rm -f $(SOURCE_O) connect4
