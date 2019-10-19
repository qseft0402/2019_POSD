#ifndef SHAPE_H
#define SHAPE_H

class Visitor;

class Shape
{
public:
  Shape(){}

  virtual void accept(Visitor *visitor)
  {

  }
  virtual void setRadius(double){}
  virtual void setRadius(double, double){}
  virtual void setRadius(double, double, double, double, double, double){}
  virtual void getRadius() const
  {

  }

};
#endif /* shape_h */
