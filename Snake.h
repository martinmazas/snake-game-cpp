//
// Created by martin mazas on 10/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_SNAKE_H
#define FINALPROJECT_SNAKEGAME_SNAKE_H
#include <vector>
#include "Point.h"

#define HEIGHT 25
#define WIDTH 50

class Snake {
private:
    Point _position;
    int _velocity;
    char _direction;
    int _length;
    std::vector<Point> _body;
public:
    Snake(Point position, int velocity);

    void grow();
    void move_snake();
    void direction(char direction);

    std::vector<Point> get_body();

    bool collided();
    bool eaten(Point food);

    Point get_pos();

};


#endif //FINALPROJECT_SNAKEGAME_SNAKE_H
