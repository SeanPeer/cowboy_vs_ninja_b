#ifndef COWBOY_HPP_
#define COWBOY_HPP_

#include "iostream"
#include "Character.hpp"

using namespace std;
namespace ariel
{
    class Cowboy : public Character
    {
        int _bullets;

    public:
        Cowboy(const string &name, const Point &location);
        ~Cowboy();

        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        string getClass() const;
    };
}
#endif