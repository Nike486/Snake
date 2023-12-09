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

    size_t a = 0;
    size_t b = 0;
    size_t c = 0;
    size_t d = 0;
    size_t e = 0;
    size_t f = 0;

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
        xPrevPosSnake[1] = a;
        yPrevPosSnake[1] = b;
        xPrevPosSnake[2] = c;
        yPrevPosSnake[2] = d;
        xPrevPosSnake[3] = e;
        yPrevPosSnake[3] = f;



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

        a = xPrevPosSnake[0];
        b = yPrevPosSnake[0];
        c = xPrevPosSnake[1];
        d = yPrevPosSnake[1];
        e = xPrevPosSnake[2];
        f = yPrevPosSnake[2];

        mainField[yPosFood][xPosFood] = '*';
        mainField[yPosSnake][xPosSnake] = '0';

        if(yPosSnake == yPosFood && xPosSnake == xPosFood)
        {
            yPosFood = (rand() % 10) + 1;
            xPosFood = (rand() % 28) + 1;
            tail++;
        }

        std::cout << xPrevPosSnake[0] << ":" << yPrevPosSnake[0] << std::endl;
        std::cout << xPrevPosSnake[1] << ":" << yPrevPosSnake[1] << std::endl;
        std::cout << xPrevPosSnake[2] << ":" << yPrevPosSnake[2] << std::endl;
        std::cout << xPrevPosSnake[3] << ":" << yPrevPosSnake[3] << std::endl;

        mainField[yPrevPosSnake[0]][xPrevPosSnake[0]] = 'o';
        mainField[yPrevPosSnake[1]][xPrevPosSnake[1]] = 'o';
        mainField[yPrevPosSnake[2]][xPrevPosSnake[2]] = 'o';
        mainField[yPrevPosSnake[3]][xPrevPosSnake[3]] = 'o';





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
