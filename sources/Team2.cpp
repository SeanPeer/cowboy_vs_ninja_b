#include <iostream>
#include "Point.hpp"
#include "Team2.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>
#include <limits>
#include <stdexcept>

const double MAX_DOUBLE = std::numeric_limits<double>::max();

using namespace std;
namespace ariel
{
    Team2::Team2()
    {
    }

    Team2::Team2(Character *leader) : Team(leader)
    {
    }
    Team2::~Team2()
    {
        
    }
    
}