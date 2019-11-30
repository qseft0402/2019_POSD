.PHONY:clean run mkdir
BIN=bin
SRC=src
TEST=test
CC=g++
CFLAG=-std=c++11 -Wfatal-errors


all:clean mkdir bin/midterm2

bin/midterm2: $(TEST)/ut_midterm2.cpp obj/evaluate_visitor.o obj/flattened_set_visitor.o src/element.h src/integer.h src/iterator.h src/null_iterator.h src/set.h src/visitor.h src/flattened_set_visitor.cpp
	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_midterm2.cpp -o $(BIN)/ut_all -lgtest -lpthread

obj/evaluate_visitor.o: src/evaluate_visitor.cpp src/evaluate_visitor.h
	$(CC) $(CFLAG) -c $< -o $@

obj/flattened_set_visitor.o: src/flattened_set_visitor.cpp src/flattened_set_visitor.h
	$(CC) $(CFLAG) -c $< -o $@


run:
	$(BIN)/ut_all

clean:
	rm -f $(BIN)/*

mkdir:
	mkdir -p $(BIN)
