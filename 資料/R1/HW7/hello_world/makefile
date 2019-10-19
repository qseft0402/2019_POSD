BIN=bin
OBJ=obj
.PHONY: clean $(BIN) $(OBJ)

all: dirs $(BIN)/HelloWorldApp $(BIN)/tree_test

$(BIN)/HelloWorldApp: hello_world.cpp hello_world.h  $(OBJ)/text_frame.o | $(BIN)
	g++ -std=c++11 $< $(OBJ)/text_frame.o `wx-config --libs` `wx-config --cxxflags` -o $@

$(OBJ)/text_frame.o: text_frame.cpp text_frame.h | $(OBJ)
	g++ -std=c++11 -c $< `wx-config --cxxflags` -o $@

$(BIN)/tree_test: tree_test.cpp tree_test.h tree_frame.h | $(BIN)
	g++ -std=c++11 $< `wx-config --libs` `wx-config --cxxflags` -o $@

dirs:
	mkdir -p $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)
