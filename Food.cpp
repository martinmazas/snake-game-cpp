//
// Created by martin mazas on 10/01/2021.
//

#include "Food.h"

void Food::genFood()
{
    _position.setX((rand() % WIDTHF - 3) + 1);
    _position.setY((rand() % HEIGHTF - 3) + 1);
}

Point Food::getPosition() { return _position; }
