//
// Created by martin mazas on 25/02/2021.
//

#ifndef FINALPROJECT_SNAKEGAME_SCORECOMPRESSION_H
#define FINALPROJECT_SNAKEGAME_SCORECOMPRESSION_H

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdlib.h>

using namespace std;

class ScoreCompression {
    string title = "TOP 5 SCORES";
    vector<pair<int, string>> scores;
    string fileName = "scores.txt";
public:
    ScoreCompression() {};

    ~ScoreCompression() {};

    void checkNewScore(int score, const string& nickname);

    void addNewHighScore(int score, const string& nickname);

    void displayScoreTable();

    void load();

    void save();
};


#endif //FINALPROJECT_SNAKEGAME_SCORECOMPRESSION_H
