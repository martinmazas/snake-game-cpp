//
// Created by Niv Swisa on 09/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_BOARDGAME_H
#define FINALPROJECT_SNAKEGAME_BOARDGAME_H
#include <utility>
#include <vector>
#include "Point.h"
#include "Snake.h"
#include "Food.h"

class BoardGame {
private:
//    Point _snakePosition;
//    Point _foodPosition;
//    std::vector<Point> _snakeBody;
public:

    BoardGame(){};
//    explicit BoardGame(std::vector<std::vector<int>>  board):_board(std::move(board)){}
    void displayBoard(Snake snake, Food food );
//    int getCol() {
//        return _board[0].size();
//    }
//
//    int getrow() {
//        return _board.size();
//    }
//    std::vector<std::vector<int>> getData() { return _board; };
//
//    void printBoard(){
//
//    }
//    friend std::ostream& operator<<(std::ostream& out, const BoardGame& board){
//        std::string str;
//        for (int i = 0; i < board._board.size(); i++) {
//            for (int j = 0; j < board._board[0].size(); j++) {
//                    str += "- ";
//            }
//            str += '\n';
//        }
//        return out << str;
//    }
};


#endif //FINALPROJECT_SNAKEGAME_BOARDGAME_H
