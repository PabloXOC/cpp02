#include <iostream>
#include "Point.hpp"

// Declare the bsp function
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    // Triangle vertices
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    // Test cases
    Point insidePoint(5, 5);      // Inside the triangle
    Point edgePoint(5, 0);        // On the edge of the triangle
    Point vertexPoint(0, 0);      // On a vertex of the triangle
    Point outsidePoint(5, 10);   // Outside the triangle
    Point veryOutsidePoint(-5, 5); // Far outside the triangle

    // Perform tests and print results
    std::cout << "Inside Point (5, 5): " << (bsp(a, b, c, insidePoint) ? "Inside" : "Outside") << "\n";
    std::cout << "Edge Point (5, 0): " << (bsp(a, b, c, edgePoint) ? "Inside" : "Outside") << "\n";
    std::cout << "Vertex Point (0, 0): " << (bsp(a, b, c, vertexPoint) ? "Inside" : "Outside") << "\n";
    std::cout << "Outside Point (10, 10): " << (bsp(a, b, c, outsidePoint) ? "Inside" : "Outside") << "\n";
    std::cout << "Very Outside Point (-5, 5): " << (bsp(a, b, c, veryOutsidePoint) ? "Inside" : "Outside") << "\n";

    return 0;
}
