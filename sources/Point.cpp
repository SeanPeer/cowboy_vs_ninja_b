#include <iostream>
#include "Point.hpp"
#include <cmath>
#include <sstream>
#include <stdexcept>

using namespace std;
namespace ariel
{
    const double a = 0.00;
    const Point b(1, 2);
    Point::Point(double x, double y) : _x(x), _y(y) {}
    Point::~Point() {}

    double Point::distance(const Point &target)
    {
        double rx = _x - target._x;
        double ry = _y - target._y;

        double dist = std::sqrt(rx * rx + ry * ry);

        return dist;
    }
    string Point::print() const
    {
        stringstream res;
        res << "(" << _x << "," << _y << ")" << endl;
        return res.str();
    }
    Point Point::moveTowards(const Point &src, const Point &dst, double distance)
    {
        if (distance < 0)
        {
            throw invalid_argument("Negative distance");
        }
        
        double dx = dst._x - src._x;
        double dy = dst._y - src._y;
        double dist = std::sqrt(dx * dx + dy * dy);

        if (dist <= distance)
        {
            return dst;
        }
        else
        {
            double ratio = distance / dist;
            double newX = src._x + ratio * dx;
            double newY = src._y + ratio * dy;
            return Point(newX, newY);
        }
    }

    bool Point::operator==(const Point &sec) const
    {
        double ax = _x - sec._x;
        double ay = _y - sec._y;
        double a_dist = std::sqrt(ax * ax + ay * ay);

        double bx = sec._x - _x;
        double by = sec._y - _y;
        double b_dist = std::sqrt(bx * bx + by * by);

        return a_dist == b_dist;
    }

}
