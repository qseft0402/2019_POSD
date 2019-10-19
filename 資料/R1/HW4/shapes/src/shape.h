#ifndef shape_h
#define shape_h

class Shape
{
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual double compactness() const = 0;
};
#endif /* shape_h */
