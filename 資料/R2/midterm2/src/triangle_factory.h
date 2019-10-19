#ifndef TRIANGLE_FACTORY_H
#define TRIANGLE_FACTORY_H

#include "triangle.h"
#include <string>

class TriangleFactroy {
    public:
        TriangleFactroy() {

        }

        Triangle* create(int a, int b, int c) {
            Triangle* tri = nullptr;
            try {
                tri = new Triangle(a, b, c);
            } catch(const std::string message) {
                tri = nullptr;
            }

            return tri;
        }
};

#endif