.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: clean dict $(BIN)/hw6

$(BIN)/hw6: $(TEST)/ut_fs.cpp $(TEST)/ut_fs.h $(SRC)/node.h $(SRC)/folder.h $(SRC)/file.h $(SRC)/node_iterator.h $(SRC)/info_content_visitor.h $(SRC)/node_visitor.h $(SRC)/find_visitor.h $(SRC)/find_link_visitor.h $(OBJ)/info_content_visitor.o $(OBJ)/find_visitor.o $(OBJ)/find_link_visitor.o
	g++ -std=c++11 $< $(OBJ)/info_content_visitor.o $(OBJ)/find_visitor.o $(OBJ)/find_link_visitor.o -o $@ $(LIBS)

$(OBJ)/info_content_visitor.o: $(SRC)/info_content_visitor.cpp $(SRC)/info_content_visitor.h
	g++ -std=c++11 -c $< -o $@ $(LIBS)

$(OBJ)/find_visitor.o: $(SRC)/find_visitor.cpp $(SRC)/find_visitor.h
	g++ -std=c++11 -c $< -o $@ $(LIBS)

$(OBJ)/find_link_visitor.o: $(SRC)/find_link_visitor.cpp $(SRC)/find_link_visitor.h
	g++ -g -std=c++11 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

dict:
	mkdir -p $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
