#ifndef TRAINEDNINJA_HPP_
#define TRAINEDNINJA_HPP_

#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;
namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const string &name, const Point &location); // speed 120
        ~TrainedNinja() override;
    };

};

#endif