.PHONY:clean run mkdir
BIN=bin
SRC=src
TEST=test

all:clean mkdir hw4

hw4: $(TEST)/ut_main.cpp $(SRC)/complex_solids.h $(SRC)/cone.h $(SRC)/solid.h $(SRC)/square_cylinder.h $(SRC)/triangular_pyramid.h
	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_main.cpp -o $(BIN)/ut_all -lgtest -lpthread

run:
	$(BIN)/ut_all

clean:
	rm -f $(BIN)/*

mkdir:
	mkdir -p $(BIN)
