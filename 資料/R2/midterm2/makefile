.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/midterm2

$(BIN)/midterm2: $(TEST)/ut_main.cpp $(SRC)/triangle_factory.h $(SRC)/set.h $(SRC)/flattened_visitor.h $(SRC)/set_visitor.h $(OBJ)/triangle.o
	g++ -g -std=c++11 $< $(OBJ)/triangle.o -o $@ $(LIBS)

$(OBJ)/triangle.o: $(SRC)/triangle.cpp $(SRC)/triangle.h
	g++ -g -std=c++11 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
