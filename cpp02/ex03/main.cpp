#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    std::cout << std::endl << "------------------------test1---------------------- " << std::endl << std::endl;

    const Point pt1(1.5, 1.5);
    const Point pt2;
    const Point pt3(0, 1.5);

    const Point ptA(1.1, 0.5); //not in triangle1
    const Point ptB(0.5, 0.8); //in triangle1
    const Point ptC(0, 0.0); //on vertex of triangle1
    const Point ptD(0, 0.5); //on edge of triangle1
    const Point ptE(1, 1.1); //in triangle triangle1

    std::cout << "the pointA is in the triangle1 " << bsp(pt1, pt2, pt3, ptA)<< std::endl;
    std::cout << "the pointB is in the triangle1 " << bsp(pt1, pt2, pt3, ptB)<< std::endl;
    std::cout << "the pointC is in the triangle1 " << bsp(pt1, pt2, pt3, ptC)<< std::endl;
    std::cout << "the pointD is in the triangle1 " << bsp(pt1, pt2, pt3, ptD)<< std::endl;
    std::cout << "the pointE is in the triangle1 " << bsp(pt1, pt2, pt3, ptE)<< std::endl << std::endl;

    Point pt4(1.5, 1.5);
    Point pt5;
    Point pt6(2.5, 2.5);

    std::cout << "the pointA is in the invalid colinear triangle " << bsp(pt4, pt5, pt6, ptA)<< std::endl;
    std::cout << "the pointB is in the invalid colinear triangle " << bsp(pt4, pt5, pt6, ptB)<< std::endl;
    std::cout << "the pointC is in the invalid colinear triangle " << bsp(pt4, pt5, pt6, ptC)<< std::endl;
    std::cout << "the pointD is in the invalid colinear triangle " << bsp(pt4, pt5, pt6, ptD)<< std::endl;
    std::cout << "the pointE is in the invalid colinear triangle " << bsp(pt4, pt5, pt6, ptE)<< std::endl;

    std::cout << std::endl << "------------------------test2---------------------- " << std::endl << std::endl;
    Point pt7(4, 1.5);
    Point pt8(1, 0.5);
    Point pt9(0.5, 2);

    Point ptF(2, 1); //in triangle2
    Point ptG(1, 1.5); //in triangle2
    Point ptH(3, 1); //not in triangle2
    Point ptI(2, 2); //not in triangle2

    std::cout << "the pointF is in the triangle2 " << bsp(pt7, pt8, pt9, ptF)<< std::endl;
    std::cout << "the pointG is in the triangle2 " << bsp(pt7, pt8, pt9, ptG)<< std::endl;
    std::cout << "the pointH is in the triangle2 " << bsp(pt7, pt8, pt9, ptH)<< std::endl;
    std::cout << "the pointI is in the triangle2 " << bsp(pt7, pt8, pt9, ptI)<< std::endl;

    return (0);
}