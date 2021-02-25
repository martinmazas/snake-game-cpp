//
// Created by martin mazas on 25/02/2021.
//

#include "ScoreCompression.h"

void ScoreCompression::checkNewScore(int score, const string& nickname) {
    if (scores.size() < 5) {
        scores.emplace_back(score, nickname);
        sort(scores.begin(), scores.end(), greater<pair<int,string>>());
    } else {
        for (auto & i : scores) {
            if (score > i.first) {
                addNewHighScore(score, nickname);
                break;
            }
        }
    }
}

void ScoreCompression::addNewHighScore(int score, const string& nickname) {
    scores.emplace_back(score, nickname);
    sort(scores.begin(), scores.end(), greater<pair<int,string>>());
    scores.erase(scores.begin() + 5);
}

void ScoreCompression::displayScoreTable() {
    cout<< "//**********************************************************//"<<endl;
    cout<<"                "<<u8"\U00002694"<<u8"\U00002694"<<title<<u8"\U00002694"<<u8"\U00002694"<<endl;
    for (auto & score : scores) {
        cout <<"              "<<"Score: "<< score.first << "  Name: " << score.second << endl;
    }
}

void ScoreCompression::load() {
    ifstream  inFile(fileName);
    string line, name;
    int score;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            name = line.substr(0,3);
            score = atoi(line.substr(4,-1).c_str());
            scores.emplace_back(score, name);
        }
        inFile.close();

    } else cout << "Unable to open file";
}

void ScoreCompression::save() {
    ofstream outFile(fileName);
    for (auto & i : scores) {
        int score = i.first;
        string nickname = i.second;
        outFile << nickname << " " << score << endl;
    }
    outFile.close();
}