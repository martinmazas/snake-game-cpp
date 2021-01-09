//
// Created by Niv Swisa on 09/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_PLAYER_H
#define FINALPROJECT_SNAKEGAME_PLAYER_H

#include <string>
#include <utility>
#include "Score.h"
#include "Level.h"

using namespace std;

class Player {
private:
    int  _id;
    string _name;
    Score _score;
    Level _level;
public:
    Player(){}
    Player(int id, string name,Score score, const Level& level):_id(1),_name(std::move(name)),_score(score),_level(level){}
    ~Player(){}


};



#endif //FINALPROJECT_SNAKEGAME_PLAYER_H
