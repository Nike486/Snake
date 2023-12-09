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

    size_t xPosSnake = 5;
    size_t yPosSnake = 3;

    char mainField[12][30];

    size_t yPosFood = (rand() % 10) + 1;
    size_t xPosFood = (rand() % 28) + 1;

    size_t xPrevPosSnake[100];
    size_t yPrevPosSnake[100];

    size_t tail = 0;

    size_t a[100];
    size_t b[100];

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
            xPrevPosSnake[i + 1] = a[i];
            yPrevPosSnake[i + 1] = b[i];
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
            a[i] = xPrevPosSnake[i];
            b[i] = yPrevPosSnake[i];
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
};


int main() {

    bool gameOver = false;
    Field field{};


    while (!gameOver)
    {
        field.createField();
        field.Input();
        field.gamePlay();
        field.printField();
        Sleep(200);
        system("cls");
    }

    return 0;
}