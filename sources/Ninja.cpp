#include "iostream"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(const string &name, const Point &location) : Character(name, location)
{
    setClass("N");
    setToTeam(false);
} // speed
Ninja::~Ninja() {}
void Ninja::move(Character *enemy)
{
    Point new_location = Point::moveTowards(getLocation(), enemy->getLocation(), _speed);
    Character::setLocation(new_location);
}
void Ninja::slash(Character *enemy)
{
    if (this == enemy)
    {
        throw runtime_error("Harakiri is not allowed!");
    }
    if (enemy == nullptr)
    {
        throw invalid_argument("Ninja cannot attack nothing.");
    }
    if (!isAlive())
    {
        throw runtime_error("A dead character cannot attack.");
    }
    double distance = getLocation().distance(enemy->getLocation());
    if (distance < 1.0)
    {
        if (enemy->isAlive())
        {
            enemy->hit(40);
        }
        else
            throw runtime_error("Cannot attack a dead character.");
    }
}

int Ninja::getSpeed()
{
    return _speed;
}

void Ninja::setSpeed(int num)
{
    _speed = num;
}