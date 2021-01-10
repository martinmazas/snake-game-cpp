//
// Created by martin mazas on 10/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_FOOD_H
#define FINALPROJECT_SNAKEGAME_FOOD_H


#include <cstdio>
#include "Point.h"

#define WIDTHF 50
#define HEIGHTF 25

class Food
{
private:
    Point _position;

public:
    void genFood();

    Point getPosition();
};
#endif //FINALPROJECT_SNAKEGAME_FOOD_H
