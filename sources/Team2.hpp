#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Point.hpp"
#include "Character.hpp"
#include <vector>
#include "Team.hpp"

using namespace std;
namespace ariel
{
    class Team2 : public Team
    {
    private:
        // vector<Character*> crew;
        // Character *_leader;

    public:
        Team2();
        Team2(Character *leader);
        ~Team2();

    };
}
#endif