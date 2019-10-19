#include <iostream>
#include <cmath>
using namespace std;
#include "circular_sector.h"

#include "shape.h"
#include "ellipse.h"
#include "triangle.h"
int main(int argc, char** argv) {
	Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new Ellipse(6,4),new CircularSector(6,5),new CircularSector(5,4),new Ellipse(5,3)};
	cout<<"p: ";
	for(int i=0;i<5;i++)
		cout<<shape_array[i]->perimeter()<<" ";
	cout<<endl;
	cout<<"s: ";
	for(int i=0;i<5;i++)
		cout<<shape_array[i]->sumOfSquares()<<" ";
	cout<<endl;
	
				

	
return 0;	
}
