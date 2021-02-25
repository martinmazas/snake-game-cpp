//
// Created by Niv Swisa on 09/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_SCORE_H
#define FINALPROJECT_SNAKEGAME_SCORE_H


class Score {
private:
    int _score;
public:
    Score():_score(0){}

    Score(int score):_score(10){}

    ~Score()= default;

    int getScore() const{return _score;}

    int setScore(int level){
        int newScore;
        switch (level) {
            case 1:
                newScore = 10;
                break;
            case 2:
                newScore = 7;
                break;
            case 3:
                newScore = 5;
                break;
            default:
                break;
        }
        return newScore;
    }



};


#endif //FINALPROJECT_SNAKEGAME_SCORE_H
