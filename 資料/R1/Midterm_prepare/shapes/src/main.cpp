#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>    // std::sort
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/sort.h"
using namespace std;

int main(int argc, char *argv[])
{
  vector<string> str;
  vector<double> matrix;
  vector<Shape*> shapes;

  ifstream fin;
  ofstream fout;
  string finline;
  string shapeC;
  string data;
  double c1;
  double rtest[2];
  double test6[6];

  fin.open(argv[1]);
  fout.open(argv[2]);

  while (getline( fin, finline,'\n'))  //讀檔讀到跳行字元
  {
    stringstream templine(finline); // string 轉換成 stream
    templine >> shapeC;
    // cout << shapeC << endl;
    if(shapeC[0] == 'C')
    {
      templine >> data;
      data = data.substr(1, data.size()-2);
      c1 = stod(data);
      // cout << c1 << endl;
      Shape *cir = new Circle(c1);
      shapes.push_back(cir);
    }
    else if(shapeC[0] == 'R')
    {
      templine >> data;
      data = data.substr(1, data.size()-2);

      stringstream Rsstr(data);
      string Rtoken;
      int i=0;
      while(getline(Rsstr, Rtoken, ','))
      {
        rtest[i] = stod(Rtoken);
        i+=1;
      }
      // cout << rtest[0] << endl;
      // cout << rtest[1] << endl;

      Shape *rec = new Rectangle(rtest[0],rtest[1]);
      shapes.push_back(rec);
    }
    else if(shapeC[0] == 'T')
    {
      templine >> data;
      data = data.substr(1, data.size()-2);

      stringstream sstr(data);
      string token;
      int i=0;
      while(getline(sstr, token, ','))
      {
        test6[i] = stod(token);
        i+=1;
      }
      // cout << test6[2] << endl;
      Shape *tri = new Triangle(test6[0],test6[1], test6[2], test6[3], test6[4], test6[5]);
      shapes.push_back(tri);
    }
    else
    {
      cout << "QA" <<endl;
    }
  }
  fin.close();

  Sort *s = new Sort(&shapes);
  if(argv[3][0] == 'a')
  {
    if(argv[4][0] == 'i')
    {
      int j;
      s->sortArea([](Shape *a, Shape *b){
        return a->area() < b->area();
      });
      fout << "[";
      for(j =0; j < shapes.size()-2; j++)
      {
        fout << shapes[j]->area() << ",";
      }
      fout << shapes[j]->area() << ",";
      j+=1;
      fout << shapes[j]->area() << "]" << endl;
    }
    else
    {
      int j;
      s->sortArea([](Shape *a, Shape *b){
        return a->area() > b->area();
      });
      fout << "[";
      for(j =0; j < shapes.size()-2; j++)
      {
        fout << shapes[j]->area() << ",";
      }
      fout << shapes[j]->area() << ",";
      j+=1;
      fout << shapes[j]->area() << "]" << endl;
    }
  }
  else
  {
    if(argv[4][0] == 'i')
    {
      s->sortPerimeter(perimeterAscendingComparison);
      int j;
      fout << "[";
      for(j =0; j < shapes.size()-2; j++)
      {
        fout << shapes[j]->perimeter() << ",";
      }
      fout << shapes[j]->perimeter() << ",";
      j+=1;
      fout << shapes[j]->perimeter() << "]" << endl;
    }
    else
    {
      s->sortPerimeter(perimeterDescendingComparison);
      int j;
      fout << "[";
      for(j =0; j < shapes.size()-2; j++)
      {
        fout << shapes[j]->perimeter() << ",";
      }
      fout << shapes[j]->perimeter() << ",";
      j+=1;
      fout << shapes[j]->perimeter() << "]" << endl;
    }
  }
}
