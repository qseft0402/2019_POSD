#include "triangle.h"
#include <string>

Triangle::Triangle(int a, int b, int c) : _a(a), _b(b), _c(c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::string("illegal triangle");
    }

    if ((a + b) < c) {
        throw std::string("illegal triangle");
    }

    if ((b + c) < a) {
        throw std::string("illegal triangle");
    }

    if ((a + c) < b) {
        throw std::string("illegal triangle");
    }
}