//
// Created by Niv Swisa on 09/01/2021.
//

#include "BoardGame.h"

void BoardGame::displayBoard(Snake snake, Food food) {
    Point snake_pos = snake.get_pos();
    Point food_pos = food.getPosition();

    vector<Point> snake_body = snake.get_body();

    cout << "SCORE : " << score << "\n\n";

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