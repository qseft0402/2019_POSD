.PHONY: clean

# all: bin/ut_shape
all: clean dirs bin/ut_all

bin/ut_all: test/ut_shape.cpp src/triangle.h src/circular_sector.h src/ellipse.h
		g++ test/ut_shape.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/*
dirs:
	mkdir -p bin
