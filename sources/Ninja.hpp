#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel
{
    class Ninja : public Character
    {
    private:
    int _speed;
    public:
        
        Ninja(const string &name, const Point &location);
        ~Ninja();
        void move(Character *enemy);
        void slash(Character *enemy);
        string getClass() const;
        void setSpeed(int num);
        int getSpeed();
    };

}

#endif