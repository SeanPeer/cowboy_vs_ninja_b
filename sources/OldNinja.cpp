#include "iostream"
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"

using namespace std;
using namespace ariel;

OldNinja::OldNinja(const string &name, const Point &location) : Ninja(name, location) {
    setSpeed(8);
    setHitPoints(150);
} // speed 8
OldNinja::~OldNinja() {}