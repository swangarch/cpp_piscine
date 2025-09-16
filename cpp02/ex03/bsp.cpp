#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point vector_ab((b.get_x() - a.get_x()).toFloat(), (b.get_y() - a.get_y()).toFloat());
    Point vector_bc((c.get_x() - b.get_x()).toFloat(), (c.get_y() - b.get_y()).toFloat());
    Point vector_ca((a.get_x() - c.get_x()).toFloat(), (a.get_y() - c.get_y()).toFloat());

    Point vector_ap((point.get_x() - a.get_x()).toFloat(), (point.get_y() - a.get_y()).toFloat());
    Point vector_bp((point.get_x() - b.get_x()).toFloat(), (point.get_y() - b.get_y()).toFloat());
    Point vector_cp((point.get_x() - c.get_x()).toFloat(), (point.get_y() - c.get_y()).toFloat());

    Fixed c1 = vector_ab.get_x() * vector_ap.get_y() - vector_ab.get_y() * vector_ap.get_x();
    Fixed c2 = vector_bc.get_x() * vector_bp.get_y() - vector_bc.get_y() * vector_bp.get_x();
    Fixed c3 = vector_ca.get_x() * vector_cp.get_y() - vector_ca.get_y() * vector_cp.get_x();

    if (c1 > 0 && c2 > 0 && c3 > 0)
        return (true);
    else if (c1 < 0 && c2 < 0 && c3 < 0)
        return (true);

    return (false);
}