#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
using namespace std;
namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        Point(double _xx, double _yy);
        ~Point();

        double const getX(){
            return _x;
        }

        double const getY(){
            return _y;
        }

        double distance(const Point &dst);
        string print() const;
        static Point moveTowards(const Point &src, const Point &dst, double distance);
        bool operator==(const Point &sec) const;
    };
}
#endif