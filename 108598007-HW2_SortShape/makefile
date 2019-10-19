.PHONY: clean

# all: bin/ut_shape
all: clean dirs bin/ut_sort bin/ut_all

# bin/ut_all: test/shape.cpp src/triangle.h src/circular_sector.h src/ellipse.h
# 		g++ test/ut_shape.cpp -o bin/ut_all -lgtest -lpthread

bin/ut_sort: src/main.cpp src/triangle.h src/circular_sector.h src/ellipse.h src/sort.h test/ut_sort.h
				g++ src/main.cpp -o bin/ut_all -lgtest -lpthread -Wfatal-errors
clean:
	rm -f bin/*
dirs:
	mkdir -p bin
