#include <cmath>
#include "shape.h"
class Ellipse:public Shape
{
public:
    Ellipse(double semiMajorAxes,double semiMinorAxes):_semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes){}
    double area() const{
      return M_PI*_semiMajorAxes*_semiMinorAxes;
    }
    double perimeter() const{
      return 2*M_PI*_semiMinorAxes+4*(_semiMajorAxes-_semiMinorAxes);
    } // perimeter formula: 2π * semiMinorAxes + 4(semiMajorAxes-semiMinorAxes)
private:
double  _semiMajorAxes;
double  _semiMinorAxes;

};
