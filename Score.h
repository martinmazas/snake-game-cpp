//
// Created by Niv Swisa on 09/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_SCORE_H
#define FINALPROJECT_SNAKEGAME_SCORE_H


class Score {
private:
    int _score;
    int _lengthOfSnakeBody;
public:
    Score():_score(0),_lengthOfSnakeBody(0){}
    explicit Score(int score,int bodyLength):_score(score),_lengthOfSnakeBody(bodyLength){}
    Score(const Score& score){*this = score;}
    ~Score()= default;

    int getScore() const{return _score;}
    void setScore(int score){_score = score;}
    void calculateScore(){
        if(_lengthOfSnakeBody > 0){// continued to be different between levels and their calculate;
            _score = _lengthOfSnakeBody + 5;
        }
    }

};


#endif //FINALPROJECT_SNAKEGAME_SCORE_H
