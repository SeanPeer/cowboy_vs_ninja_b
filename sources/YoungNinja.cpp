#include "iostream"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"

using namespace std;
using namespace ariel;

YoungNinja::YoungNinja(const string &name, const Point &location) : Ninja(name, location) {
    setSpeed(14);
    setHitPoints(100);
} // speed 100
YoungNinja::~YoungNinja() {}