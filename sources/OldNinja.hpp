#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;
namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &name, const Point &location); // speed 150
        ~OldNinja() override;
    };

};

#endif