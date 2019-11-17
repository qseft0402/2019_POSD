.PHONY:clean run mkdir
BIN=bin
SRC=src
TEST=test
CC=g++
CFLAG=-std=c++11 -Wfatal-errors


all:clean mkdir bin/ut_all

bin/ut_all: $(TEST)/ut_main.cpp obj/find_visitor.o obj/update_path_visitor.o $(TEST)/ut_node.h $(SRC)/find_visitor.h  $(SRC)/find_visitor.cpp  $(SRC)/link.h $(SRC)/null_iterator.h  $(SRC)/visitor.h $(SRC)/file.h  $(SRC)/folder.h  $(SRC)/node.h $(TEST)/ut_fs.h $(SRC)/update_path_visitor.cpp $(SRC)/update_path_visitor.h
	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_main.cpp -o $(BIN)/ut_all -lgtest -lpthread

obj/find_visitor.o: src/find_visitor.cpp src/find_visitor.h
	$(CC) $(CFLAG) -c $< -o $@

obj/update_path_visitor.o: src/update_path_visitor.cpp src/update_path_visitor.h
	$(CC) $(CFLAG) -c $< -o $@


run:
	$(BIN)/ut_all

clean:
	rm -f $(BIN)/*

mkdir:
	mkdir -p $(BIN)
