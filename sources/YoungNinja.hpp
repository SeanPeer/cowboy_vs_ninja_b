#ifndef YOUNGNINJA_HPP_
#define YOUNGNINJA_HPP_

#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;
namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja();
        YoungNinja(const string &name, const Point &location); // speed 100

        ~YoungNinja() override;
    };

};

#endif