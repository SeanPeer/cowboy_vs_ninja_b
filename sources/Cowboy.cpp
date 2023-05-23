#include "iostream"
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(const string &name, const Point &location) : Character(name, location)
{
    _bullets = 6;
    setHitPoints(110);
    setClass("C");
    setToTeam(false);
} // bullets
Cowboy::~Cowboy()
{
}
void Cowboy::shoot(Character *enemy)
{
    if (this == enemy)
    {
        throw runtime_error("A cowboy cannot shoot at himself.");
    }
    if (enemy == nullptr)
    {
        throw invalid_argument("A cowboy cannot shoot nothing.");
    }
    if (!isAlive())
    {
        throw runtime_error("A dead cowboy cannot shoot.");
    }

    if (!enemy->isAlive())
    {
        throw runtime_error("Cannot shoot a dead enemy.");
    }

    if (hasboolets())
    {
        enemy->hit(10);
        _bullets--;
    }
}

bool Cowboy::hasboolets()
{
    return (_bullets > 0);
}
void Cowboy::reload()
{
    if (isAlive())
    {
        _bullets = 6;
    }
    else
        throw runtime_error("A dead cowboy cannot reload");
}

string Cowboy::getClass() const
{
    return "C";
}