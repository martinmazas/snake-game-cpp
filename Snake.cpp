//
// Created by martin mazas on 10/01/2021.
//

#include "Snake.h"

Snake::Snake(Point position, int velocity):_position(position), _velocity(velocity)
{
    _direction = 'n';
    _length = 1;
    _body.push_back(position);
}

void Snake::direction(char direction) { this->_direction = direction; }
void Snake::grow() { _length++; }
Point Snake::get_pos() { return _position; }

std::vector<Point> Snake::get_body() { return _body; }

void Snake::move_snake()
{
    int posY = _position.getY();
    int posX = _position.getX();
    switch(_direction)
    {
        case 'u':
            posY -= _velocity;
            _position.setY(posY);
            break;
        case 'd':
            posY += _velocity;
            _position.setY(posY);
            break;
        case 'l':
            posX -= _velocity;
            _position.setX(posX);
            break;
        case 'r':
            posX += _velocity;
            _position.setX(posX);
            break;
    }

    _body.push_back(_position);
    if(_body.size() > _length) _body.erase(_body.begin());
}

bool Snake::collided()
{
    if(_position.getX() < 1 || _position.getX() > WIDTH-2 || _position.getY() < 1 || _position.getY() > HEIGHT-2) return true;

    for(int i = 0; i < _length-1; i++)
    {
        if(_position.getX() == _body[i].getX() && _position.getY() == _body[i].getY()) return true;
    }
    return false;
}

bool Snake::eaten(Point food)
{
    if(_position.getX() == food.getX() && _position.getY() == food.getY()) return true;
    return false;
}
