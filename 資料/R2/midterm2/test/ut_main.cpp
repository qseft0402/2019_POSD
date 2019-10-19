#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "../src/triangle.h"
#include "../src/triangle_factory.h"
#include "../src/set.h"
#include "../src/flattened_visitor.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TriangleConstructor, LegelTriangle) {
    ASSERT_NO_THROW(Triangle(3, 4, 5));
}

TEST(TriangleConstructor, IllegelTriangle) {
    try {
        Triangle t(3, 5, 3);
    } catch (const std::string message) {
        ASSERT_EQ(message, std::string("illegal triangle"));
    }
}

TEST(TriangleFactroy, LegelTriangle) {
    TriangleFactroy f;
    ASSERT_NE(nullptr, f.create(3, 4, 5));
}

TEST(TriangleFactroy, ILegelTriangle) {
    TriangleFactroy f;
    ASSERT_EQ(nullptr ,f.create(0, 4, 5));
}

TEST(SetObject, Add) {
    Set s;
    s.add(1);

    Set child;
    child.add(2);
    s.add(child);
    
    Set child2;
    child2.add(3);
    child2.add(4);
    Set child2_child;
    child2_child.add(5);
    Set empty;
    child2_child.add(empty);
    child2.add(child2_child);
    s.add(child2);

    ASSERT_EQ("{1,{2},{3,4,{5,{}}}}", s.toString());
}

TEST(FlattenedVisitor, VisitSet) {
    Set s;
    s.add(1);

    Set child;
    child.add(2);
    s.add(child);
    
    Set child2;
    child2.add(4);
    child2.add(3);
    Set child2_child;
    child2_child.add(5);
    Set empty;
    child2_child.add(empty);
    child2.add(child2_child);
    s.add(child2);

    FlattenedVisitor* visitor = new FlattenedVisitor();
    s.accept(visitor);

    ASSERT_EQ("{1,2,4,3,5}", visitor->getResult()->toString());
}