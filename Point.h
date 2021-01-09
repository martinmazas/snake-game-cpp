//
// Created by Niv Swisa on 09/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_POINT_H
#define FINALPROJECT_SNAKEGAME_POINT_H

#include <iostream>

class Point {
private:
    int _x;
    int _y;
public:
    Point() { _x = _y = 1; }

    Point(int x, int y) : _x(x), _y(y) {}

    ~Point() = default;

    void setPoint(int x, int y) {
        _x = x;
        _y = y;
    }

    void setX(int x) { _x = x; }

    void setY(int y) { _y = y; }

    int getX() const { return _x; }

    int getY() const { return _y; }

    void moveUp() { _y--; }

    void moveDown() { _y++; }

    void moveLeft() { _x--; }

    void moveRight() { _x++; }


};


#endif //FINALPROJECT_SNAKEGAME_POINT_H
