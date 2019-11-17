.PHONY:clean run mkdir
BIN=bin
SRC=src
TEST=test

all:clean mkdir hw4

hw4: $(TEST)/ut_main.cpp $(TEST)/ut_node.h $(SRC)/file.h  $(SRC)/folder.h  $(SRC)/node.h $(TEST)/ut_fs.h
	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_main.cpp -o $(BIN)/ut_all -lgtest -lpthread

run:
	$(BIN)/ut_all

clean:
	rm -f $(BIN)/*

mkdir:
	mkdir -p $(BIN)
