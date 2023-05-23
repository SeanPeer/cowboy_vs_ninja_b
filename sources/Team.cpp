#include <iostream>
#include "Point.hpp"
#include "Team.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include <vector>
#include <limits>
#include <stdexcept>

const double MAX_DOUBLE = std::numeric_limits<double>::max();

using namespace std;
namespace ariel
{
    Team::Team() {}
    Team::Team(Character *leader)
    {
        _leader = leader;

        if (_leader->isTeamMate())
        {
            runtime_error("Cannot make an already promted character to be another Team's leader");
        }
        if (_leader->isLeader())
            throw runtime_error("Cannot make an already promted character");
        else
        {
            _leader->setIsLeader(true);
            _leader->setToTeam(true);
            crew.push_back(_leader);
            // cout << crew.size() << "crew.size()" << endl;
        }
    }
    // Team::Team(Cowboy *leader)
    // {
    //     _leader = leader;

    //     if (_leader->isTeamMate())
    //     {
    //         runtime_error("Cannot make an already promted character to be another Team's leader");
    //     }
    //     if (_leader->isLeader())
    //         throw runtime_error("Cannot make an already promted character");
    //     else
    //     {
    //         _leader->setIsLeader(true);
    //         _leader->setToTeam(true);
    //         crew.push_back(_leader);
    //         // cout << crew.size() << "crew.size()" << endl;
    //     }
    // }
    Team::~Team()
    {
        for (Character *character : crew)
        {
            delete character;
        }
    }

    void Team::add(Character *character)
    {
        // if character is a Teammate already using a flag
        if (character->isTeamMate())
        {
            throw runtime_error("Cannot insert a character who already has a Team");
        }
        // if Team is already full
        else if (crew.size() >= 10)
        {
            throw runtime_error("Cannot insert any more characters into Team");
        }
        else
        {

            character->setToTeam(true);
            crew.push_back(character);
            // cout << crew.size() << "crew.size() after add" << endl;
        }
    }
    void Team::attack(Team *enemy_team)
    {
        if (enemy_team == nullptr)
        {
            throw invalid_argument("Cannot attack No one !");
        }
        if (this == enemy_team)
        {
            throw runtime_error("The attack cannot be on team itself ! ");
        }
        if (enemy_team->stillAlive() == 0)
        {
            throw runtime_error("No enemy is left alive !");
        }
        if (stillAlive() == 0)
        {

            throw runtime_error("There are no one that is alive in attacks Team !");
        }

        if (!_leader->isAlive())
        {
            // Looking for another leader
            Character *new_leader = look4NewLeader();
            if (new_leader != nullptr)
            {
                _leader = new_leader;
            }
            else
            {
                // No leader is found - meaning that every other team characters are dead
                return;
            }
        }

        Character *enemy = findClosestEnemy(enemy_team);
        for (Character *character : crew)
        {
            if (enemy != nullptr)
            {
                if (character->isAlive() && enemy->isAlive())
                {
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(character))
                    {
                        if (cowboy->hasboolets())
                        {
                            cowboy->shoot(enemy);
                        }
                        else
                        {
                            cowboy->reload();
                        }
                    }
                    if (Ninja *ninja = dynamic_cast<Ninja *>(character))
                    {
                        if (ninja->distance(enemy) < 1.0)
                        {
                            ninja->slash(enemy);
                        }
                        else
                        {
                            ninja->move(enemy);
                        }
                    }
                }
            }
            else
            {
                return;
            }
            if (!enemy->isAlive())
                enemy = findClosestEnemy(enemy_team);
        }
    }
    Character *Team::look4NewLeader()
    {
        double closest_distance = MAX_DOUBLE;
        Character *new_leader = nullptr;

        for (Character *character : crew)
        {
            if (character->isAlive())
            {
                double distance = _leader->distance(character);
                if (distance < closest_distance)
                {
                    closest_distance = distance;
                    new_leader = character;
                }
            }
        }

        if (new_leader == nullptr)
            throw runtime_error("no leader");
        else
        {
            _leader = new_leader;
            return _leader;
        }
    }

    int Team::stillAlive()
    {
        int counter = 0;
        for (Character *character : crew) // going through all Cowboys in crew
        {
            if (character->getClass() == "C" && character->getHitPoints() > 0)
            {
                counter++;
            }
        }
        for (Character *character : crew) // going through all Ninja in crew
        {
            if (character->getClass() == "N" && character->getHitPoints() > 0)
                counter++;
        }
        return counter;
    }
    void Team::print()
    {
        for (Character *character : crew) // going through all Ninja in crew
        {
            if (character->getClass() == "C" && character->isAlive())
                character->print();
        }

        for (Character *character : crew) // going through all Cowboys in crew
        {
            if (character->getClass() == "N" && character->isAlive())
                character->print();
        }
    }

    void Team::findNewLeader()
    {
        Character *new_lead;
        double close_character = MAX_DOUBLE;

        for (Character *character : crew)
        {
            if (character->isAlive())
            {
                double candidate_character = character->getLocation().distance(_leader->getLocation());
                if (candidate_character < close_character)
                {
                    close_character = candidate_character;
                    new_lead = character;
                }
            }
        }
        _leader = new_lead;
    }
    Character *Team::findClosestEnemy(Team *enemy_team)
    {
        bool flag = false;
        double closest_distance = MAX_DOUBLE;
        Character *closest_enemy = nullptr;

        for (Character *enemy : enemy_team->crew)
        {
            if (enemy->isAlive())
            {
                flag = true;
                double distance = _leader->distance(enemy);
                if (distance < closest_distance)
                {
                    closest_distance = distance;
                    closest_enemy = enemy;
                }
            }
        }
        if (flag == false)
        {
            return NULL;
        }

        return closest_enemy;
    }
    Character *Team::getLeader()
    {
        return _leader;
    }
    void Team::setLeader(Character *leader)
    {
        _leader = leader;
    }

    vector<Character *> Team::getCrew()
    {
        return crew;
    }

}