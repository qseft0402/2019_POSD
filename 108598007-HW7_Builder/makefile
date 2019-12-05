.PHONY:mkdir clean run stat
BIN=bin
OBJ=obj
SRC=src
TEST=test
CC=g++
CFLAG=-std=c++11 -Wfatal-errors

all:clean mkdir bin/ut_all

bin/ut_all: $(TEST)/ut_main.cpp $(OBJ)/find_visitor.o $(OBJ)/update_path_visitor.o $(OBJ)/filesystem_builder.o $(TEST)/ut_node.h  $(SRC)/link.h $(SRC)/null_iterator.h  $(SRC)/visitor.h $(SRC)/file.h  $(SRC)/folder.h  $(SRC)/node.h $(TEST)/ut_fs.h
	$(CC) $(CFLAG) $(TEST)/ut_main.cpp -o $(BIN)/ut_all -lgtest -lpthread

obj/find_visitor.o: src/find_visitor.cpp src/find_visitor.h
	$(CC) $(CFLAG) -c $< -o $@

obj/update_path_visitor.o: src/update_path_visitor.cpp src/update_path_visitor.h
	$(CC) $(CFLAG) -c $< -o $@

obj/filesystem_builder.o: src/filesystem_builder.cpp src/filesystem_builder.h 
	$(CC) $(CFLAG) -c $< -o $@
run:
	$(BIN)/ut_all

clean:
	rm -f $(BIN)/*

mkdir:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

stat:
	wc -l src/* test/*.h test/*.cpp
