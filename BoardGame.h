//
// Created by Niv Swisa on 09/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_BOARDGAME_H
#define FINALPROJECT_SNAKEGAME_BOARDGAME_H
#include <utility>
#include <vector>
#include "Point.h"

class BoardGame {
private:
    Point _snakePosition;
    Point _foodPosition;
    std::vector<Point> _snakeBody;
//    int _score;
//   std::vector<std::vector<int>> _board;
public:
//    BoardGame(){
//        std::vector<int> col(35);
//        //initial
//        for (int i = 0; i < 35; i++) {
//            _board.push_back(col);
//        }
//        //initial with -
//        for (int i = 0; i < 35; i++) {
//            for (int j = 0; j < 35; j++) {
//                _board[i][j] = '-';
//            }
//        }
//    }

    BoardGame(){

    }
    explicit BoardGame(std::vector<std::vector<int>>  board):_board(std::move(board)){}

    int getCol() {
        return _board[0].size();
    }

    int getrow() {
        return _board.size();
    }
    std::vector<std::vector<int>> getData() { return _board; };

    void printBoard(){

    }
    friend std::ostream& operator<<(std::ostream& out, const BoardGame& board){
        std::string str;
        for (int i = 0; i < board._board.size(); i++) {
            for (int j = 0; j < board._board[0].size(); j++) {
                    str += "- ";
            }
            str += '\n';
        }
        return out << str;
    }
};


#endif //FINALPROJECT_SNAKEGAME_BOARDGAME_H
