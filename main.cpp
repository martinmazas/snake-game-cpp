//#include <iostream>
//#include "BoardGame.h"

#include <iostream>
//#include <conio.h>
#include <ctime>
#include <ncurses.h>
#include <map>
#include <vector>
#include "ScoreCompression.h"
#include "Score.h"

#include "Snake.h"
#include "Food.h"

//#define WIDTH 50
//#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2,HEIGHT/2}, 1);
Food food;

int score;

void board()
{
    Point snake_pos = snake.get_pos();
    Point food_pos = food.getPosition();

    vector<Point> snake_body = snake.get_body();

    cout << "SCORE : " << score << "\n\n";

    //Display the board height and width

    for(int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t"<< u8"\U00002694";
        for(int j = 0; j < WIDTH - 2; j++)
        {
            if(i == 0 || i == HEIGHT-1) cout << u8"\U00002694";

            else if(i == snake_pos.getY() && j+1 == snake_pos.getX()) cout << u8"\U0001F40D";  //snake
            else if(i == food_pos.getY() && j+1 == food_pos.getX()) cout << u8"\U0001F34F";    //food

            else
            {
                bool isBodyPart = false;
                for(int k = 0; k < snake_body.size()-1; k++)
                {
                    if(i == snake_body[k].getY() && j+1 == snake_body[k].getX())
                    {
                        cout << u8"\U0001F40D";
                        isBodyPart = true;
                        break;
                    }
                }

                if(!isBodyPart) cout << ' ';
            }
        }
        cout << u8"\U00002694" << endl;
    }
}

int main()
{
    int level;
    cout<< endl;
    cout<< "//**********************************************************//"<<endl;
    cout<<"                 "<<u8"\U0001F40D"<<"Welcome To Snake"<<u8"\U0001F40D"<<endl;
    cout<<"          "<<u8"\U00002694"<<"Easy and Fun way to waste the time!"<<u8"\U00002694"<<endl;
    cout<< "//**********************************************************//"<<endl;
    cout<< endl;
    cout<<"                      Choose Level:                             "<<endl;
    cout<<"                      1.Easy"<<u8"\U0001F36A"<<"                "<<endl;
    cout<<"                      2.Medium"<<u8"\U0001F41E"<<"              "<<endl;
    cout<<"                      3.Hard"<<u8"\U0001F373"<<"                "<<endl;
    cin>>level;
    cout<< endl;
    cout<<"                      ENJOY!!!!!!                               "<<endl;
    cout<< endl;
    cout<< "//**********************************************************//"<<endl;
    cout<< endl<<endl;

    score = 0;
    srand(time(nullptr));

    food.genFood();

    char game_over = false;

    //Score object for getting level and initial the scores.
    Score scoreLevel;
    int newScore = scoreLevel.setScore(level);

    while(!game_over)
    {
        board();
        char c;
        c = getchar();
        if(c)
        {
            switch(c)
            {
                case 'w': snake.direction('u'); break;
                case 'a': snake.direction('l'); break;
                case 's': snake.direction('d'); break;
                case 'd': snake.direction('r'); break;
            }
        }

        if(snake.collided()) {
            //Load file with highest scores.
            ScoreCompression scores;
            scores.load();

            string nickname;
            cout<<"Please enter your name initials(3): "<<endl;
            cin>> nickname;
            //Name needs to be 3 characters
            if(nickname.length() < 3) {
                nickname = "XXX";
            }
            if(nickname.length() > 3) {
                nickname = nickname.substr(0,3);
            }
            //Check if the new score is in top 5 scores.
            scores.checkNewScore(score,nickname);
            scores.save();

            scores.displayScoreTable();

            cout<<"//**********************************************************//"<<endl;
            cout<<"                "<<u8"\U0000274C"<<u8"\U0000274C"<<"GAME OVER!"<<u8"\U0000274C"<<u8"\U0000274C"<<endl;
            cout<<"                 See you next time.                      "<<endl;
            cout<<"//**********************************************************//"<<endl;
            game_over = true;
        }

        if(snake.eaten(food.getPosition()))
        {
            food.genFood();
            snake.grow();
            score += newScore;
        }
        snake.move_snake();
    }
}
