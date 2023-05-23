#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Character.hpp"
#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;
namespace ariel
{

    class Team
    {
    private:
        vector<Character *> crew;
        Character *_leader;

    public:
        Team();
        Team(Character *leader);
        // Team(Cowboy *leader);
        ~Team();

        void add(Character *character);
        void attack(Team *enemy_team);
        int stillAlive();
        void print();
        void findNewLeader();
        Character *findClosestEnemy(Team *enemy_team);
        Character *look4NewLeader();
        Character *getLeader();
        vector<Character *> getCrew();
        void setLeader(Character *leader);
    };

}

#endif