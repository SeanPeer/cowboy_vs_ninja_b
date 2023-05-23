#include "iostream"
#include "Character.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
using namespace ariel;

TrainedNinja::TrainedNinja(const string &name, const Point &location) : Ninja(name, location)
{
    setSpeed(12);
    setHitPoints(120);
} // speed 12
TrainedNinja::~TrainedNinja() {}