//
// Created by Niv Swisa on 09/01/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_LEVEL_H
#define FINALPROJECT_SNAKEGAME_LEVEL_H

#include <string>

enum  level {easy,medium,hard};
class Level {
private:
    int _diffLevel;
    std::string _level;

public:
    Level():_diffLevel(0),_level(std::to_string(easy)){}
    explicit Level(int diffLevel){
        _diffLevel = diffLevel;
        switch(_diffLevel){
            case 0: _level = std::to_string(easy);
            case 1: _level = std::to_string(medium);
            case 2: _level = std::to_string(hard);
        }
    }

    Level(const Level& level){*this = level;}
    ~Level(){}

    std:: string getLevel(){return _level;}
    void setLevel(int level){
        switch(_diffLevel){
            case 0: _level = std::to_string(easy);
            case 1: _level = std::to_string(medium);
            case 2: _level = std::to_string(hard);
        }
    }

    void increaseLevel() {
        if(_diffLevel < 2){
            setLevel(++_diffLevel);
        }
    }

    void decreaseLevel(){
        if(_diffLevel > 0){
            setLevel(--_diffLevel);
        }
    }

};


#endif //FINALPROJECT_SNAKEGAME_LEVEL_H
