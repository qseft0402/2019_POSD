.PHONY: clean

bin/hw3: test/ut_main.cpp src/main.cpp test/ut_shape.cpp test/ut_sort.cpp src/shape.h src/circle.h src/triangle.h src/rectangle.h src/sort.h
	g++ -std=c++11 src/main.cpp -o bin/hw3 -lpthread

clean:
	rm bin/hw3
