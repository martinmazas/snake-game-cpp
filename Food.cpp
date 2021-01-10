//
// Created by martin mazas on 10/01/2021.
//

#include "Food.h"

void Food::genFood()
{
    int rX = rand() % (WIDTHF - 3) + 1;
    int rY = rand() % (HEIGHTF - 3) + 1;
    std::cout<<"rX: " <<rX <<" "<<std::endl;
    std::cout<<"rY: " <<rY <<" "<<std::endl;
    _position.setX(rX);
    _position.setY(rY);
}

Point Food::getPosition() { return _position; }
