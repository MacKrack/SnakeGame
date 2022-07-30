#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using namespace std;

bool gameOver;

const int boardWidth = 20;
const int boardHeight = 20;
int snakeAxisX, snakeAxisY, fruitAxisX, fruitAxisY, score;
int snakeTailX[100], snakeTailY[100];
int nSnakeTail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void setup()
{
    gameOver = false;
    dir = STOP;
    snakeAxisX = boardWidth / 2;
    snakeAxisY = boardHeight / 2;
    srand(time(NULL));
    fruitAxisX = rand() % (boardWidth - 2) + 2;
    fruitAxisY = rand() % (boardHeight - 2) + 2;
    score = 0;
}

void draw()
{
    system("clear");

    // up edge of board
    for (int i = 0; i < boardWidth + 2; i++)
    {
        cout << "#";
    }

    cout << endl;

    // sides edges of board
    for (int i = 0; i < boardHeight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            // left edge of board
            if (j == 0)
            {
                cout << "#";
            }
            // head of snake
            if (i == snakeAxisY && j == snakeAxisX)
            {
                cout << "O";
            }
            // fruit possition
            else if (i == fruitAxisY && j == fruitAxisX)
            {
                cout << "x";
            }
            // blank space and sanke tail
            else
            {
                bool print = false;
                for (int k = 0; k < nSnakeTail; k++)
                {
                    if (snakeTailY[k] == i && snakeTailX[k] == j)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }

            // right edge od board
            if (j == boardWidth - 1)
            {
                cout << "#";
            }
        }
        cout << endl;
    }

    // down edge of board
    for (int i = 0; i < boardWidth + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void input()
{
    // (kbhit() & getch() - features is not available on unix, but characters should load immediately from keyboard - without waiting for return key
    switch (cin.get())
    {
    case 'a':
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 'w':
        dir = UP;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'x':
        gameOver = true;
        break;
    }
}

void logic()
{
    // logic of snake tail move
    int prevSnakeTailX = snakeTailX[0];
    int prevSnakeTailY = snakeTailY[0];
    int prev2_SnakeTailX, prev2_SnakeTailY;
    snakeTailX[0] = snakeAxisX;
    snakeTailY[0] = snakeAxisY;
    for (int i = 1; i < nSnakeTail; i++)
    {
        prev2_SnakeTailX = snakeTailX[i];
        prev2_SnakeTailY = snakeTailY[i];
        snakeTailX[i] = prevSnakeTailX;
        snakeTailY[i] = prevSnakeTailY;
        prevSnakeTailX = prev2_SnakeTailX;
        prevSnakeTailY = prev2_SnakeTailY;
    }

    switch (dir)
    {
    case LEFT:
        snakeAxisX--;
        break;
    case RIGHT:
        snakeAxisX++;
        break;
    case UP:
        snakeAxisY--;
        break;
    case DOWN:
        snakeAxisY++;
        break;
    default:
        break;
    }
    // game over when snake hit the wall
    if (snakeAxisX > boardWidth || snakeAxisX < 0 || snakeAxisY > boardHeight || snakeAxisY < 0)
    {
        gameOver = true;
    }
    // get the points for catch fruit and then change the fruit locations
    if (snakeAxisX == fruitAxisX && snakeAxisY == fruitAxisY)
    {
        score += 10;
        fruitAxisX = rand() % (boardWidth - 2) + 2;
        fruitAxisY = rand() % (boardHeight - 2) + 2;
        nSnakeTail++;
    }
}

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();

        // this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
