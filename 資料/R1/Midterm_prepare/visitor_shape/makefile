.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/shp

$(BIN)/shp: $(TEST)/ut_main.cpp $(TEST)/ut_shape.cpp $(TEST)/ut_sort.cpp $(SRC)/shape.h $(SRC)/circle.h $(SRC)/triangle.h $(SRC)/rectangle.h $(SRC)/sort.h $(SRC)/ap_visitor.h $(SRC)/visitor.h $(OBJ)/ap_visitor.o
	g++ -std=c++11 $< $(OBJ)/ap_visitor.o -o $@ $(LIBS)

$(OBJ)/ap_visitor.o: $(SRC)/ap_visitor.cpp $(SRC)/ap_visitor.h
	g++ -std=c++11 -c $< -o $@ $(LIBS)

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
