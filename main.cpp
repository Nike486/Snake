#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

/*
      ___           ___           ___           ___           ___
     /  /\         /__/\         /  /\         /__/|         /  /\
    /  /:/_        \  \:\       /  /::\       |  |:|        /  /:/_
   /  /:/ /\        \  \:\     /  /:/\:\      |  |:|       /  /:/ /\
  /  /:/ /::\   _____\__\:\   /  /:/~/::\   __|  |:|      /  /:/ /:/_
 /__/:/ /:/\:\ /__/::::::::\ /__/:/ /:/\:\ /__/\_|:|____ /__/:/ /:/ /\
 \  \:\/:/~/:/ \  \:\~~\~~\/ \  \:\/:/__\/ \  \:\/:::::/ \  \:\/:/ /:/
  \  \::/ /:/   \  \:\  ~~~   \  \::/       \  \::/~~~~   \  \::/ /:/
   \__\/ /:/     \  \:\        \  \:\        \  \:\        \  \:\/:/
     /__/:/       \  \:\        \  \:\        \  \:\        \  \::/
     \__\/         \__\/         \__\/         \__\/         \__\/
*/

class Field
{
private:

    char mainField[12][30];

    size_t xPosSnake = 5;
    size_t yPosSnake = 3;

    size_t xPosFood = 15;
    size_t yPosFood = 6;

    size_t xPrevPosSnake[100];
    size_t yPrevPosSnake[100];

    size_t xCorPosSnake[100];
    size_t yCorPosSnake[100];

    size_t tail = 0;

    enum movement
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    movement move;

public:

    void createField()
    {
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 30; ++j)
            {
                if(i == 0 || i == (11)
                || j == 0 || j == (29))
                {
                    mainField[i][j] = '#';
                }
                else mainField[i][j] = ' ';
            }
        }
    }

    void printField()
    {
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 30; ++j)
            {
                std::cout << mainField[i][j];
            }
            std::cout << std::endl;
        }
    }

    void Input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
                case 'a':
                    move = LEFT;
                    break;
                case 'd':
                    move = RIGHT;
                    break;
                case 'w':
                    move = UP;
                    break;
                case 's':
                    move = DOWN;
                    break;
            }
        }
    }

    void gamePlay()
    {
        xPrevPosSnake[0] = xPosSnake;
        yPrevPosSnake[0] = yPosSnake;

        for (int i = 0; i < tail; ++i)
        {
            xPrevPosSnake[i + 1] = xCorPosSnake[i];
            yPrevPosSnake[i + 1] = yCorPosSnake[i];
        }

        switch (move) {
            case LEFT:
                xPosSnake--;
                break;
            case RIGHT:
                xPosSnake++;
                break;
            case UP:
                yPosSnake--;
                break;
            case DOWN:
                yPosSnake++;
                break;
            default:
                break;
        }

        for (int i = 0; i < tail; ++i)
        {
            xCorPosSnake[i] = xPrevPosSnake[i];
            yCorPosSnake[i] = yPrevPosSnake[i];
        }

        mainField[yPosFood][xPosFood] = '*';
        mainField[yPosSnake][xPosSnake] = '0';

        if(yPosSnake == yPosFood && xPosSnake == xPosFood)
        {
            yPosFood = (rand() % 10) + 1;
            xPosFood = (rand() % 28) + 1;
            tail++;
        }

        for (int i = 0; i < tail; ++i)
        {
            mainField[yPrevPosSnake[i]][xPrevPosSnake[i]] = 'o';
        }
    }

    bool setGameStatus() const
    {
        if(yPosSnake == 0 || yPosSnake == (11)
        || xPosSnake == 0 || xPosSnake == (29))
        {
            return true;
        }

        if(mainField[yPosSnake][xPosSnake] == 'o')
        {
            return true;
        }

        return false;
    }
};

int main() {

    bool gameOver = false;
    Field field;

    while (!gameOver)
    {
        field.createField();
        field.Input();
        field.gamePlay();
        field.printField();
        gameOver = field.setGameStatus();
        Sleep(200);
        system("cls");
    }

    return 0;
}