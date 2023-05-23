#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <string>

#include "Point.hpp"

using namespace std;
namespace ariel
{
    class Character
    {
    private:
        string _name;
        int _hitPoints;
        Point _location;
        string _class;
        bool _isLeader = false;
        bool _hasTeam = false;

    public:
        Character(Character &&character);
        Character(const Character &Character);
        Character(const string &name, const Point &location);
        virtual ~Character();
        bool isAlive();
        double distance(const Character *character);
        void hit(int damage);
        string getName();
        Point getLocation();
        string print() const;
        void setHitPoints(int num);
        int getHitPoints();
        string getClass();
        void setClass(string class_name);
        void setLocation(Point new_location);
        void setIsLeader(bool degree);
        bool isLeader();
        void setToTeam(bool flag);
        bool isTeamMate();

        // Copy assignment operator
        Character &operator=(const Character &character)
        {
            if (this != &character)
            {
                _name = character._name;
                _hitPoints = character._hitPoints;
                _location = character._location;
            }
            return *this;
        }

        // Move assignment operator
        Character &operator=(Character &&character) noexcept
        {
            if (this != &character)
            {
                _name = std::move(character._name);
                _hitPoints = character._hitPoints;
                _location = std::move(character._location);
                character._hitPoints = 0;
            }
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &output, const Character &character)
        {
            output << character.print();
            return output;
        }
    };

}
#endif