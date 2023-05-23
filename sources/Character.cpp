#include <iostream>
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <sstream>

using namespace std;
namespace ariel
{
    const double a = 0.00;
    const Point b(1, 2);
    Character::Character(const string &name, const Point &location) : _name(name), _location(location) {}
    // Copy constructor
    Character::Character(const Character &character)
        : _name(character._name), _hitPoints(character._hitPoints), _location(character._location) {}

    // Move constructor
    Character::Character(Character&& character) 
        : _name(std::move(character._name)), _hitPoints(character._hitPoints), _location(std::move(character._location)) {
        character._hitPoints = 0;
    }

    Character::~Character() {}
    bool Character::isAlive()
    {
        if (_hitPoints == 0)
            return false;
        else
            return true;
    }
    double Character::distance(const Character *character)
    {
        Point src_location = _location;
        return src_location.distance(character->_location);
    }
    void Character::hit(int damage)
    {
        if(damage < 0){
            throw invalid_argument("cannot be hit with a negative number");
        }
        _hitPoints -= damage;
        if (_hitPoints < 0)
        {
            _hitPoints = 0;
        }
    }
    string Character::getName()
    {
        return _name;
    }
    Point Character::getLocation()
    {
        return _location;
    }
    void Character::setHitPoints(int num)
    {
        _hitPoints = num;
    }
    void Character::setClass(string class_name)
    {
        _class = class_name;
    }
    string Character::getClass()
    {
        return _class;
    }
    string Character::print() const
    {
        std::stringstream res;
        if (this->_hitPoints > 0)
        {
            res << _class << _name << _hitPoints << _location.print() << endl;
        }
        else
        {
            res << _class << "(" << _name << ")" << _location.print() << endl;
        }
        return res.str();
    } // N - ninja, C - cowboy  should print- name , hitpoints, location - if dead (name)

    int Character::getHitPoints()
    {
        return _hitPoints;
    }
    void Character::setLocation(Point new_location)
    {
        _location = new_location;
    }
    void Character::setIsLeader(bool degree)
    {
        _isLeader = degree;
    }

    bool Character::isLeader()
    {
        return _isLeader;
    }

    void Character::setToTeam(bool flag)
    {
        _hasTeam = flag;
    }
    bool Character::isTeamMate()
    {
        return _hasTeam;
    }

};
