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
            // blank space
            else
                cout << " ";

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
    // get the points for catch fruit and change the fruit locations
    if (snakeAxisX == fruitAxisX && snakeAxisY == fruitAxisY)
    {
        score += 10;
        fruitAxisX = rand() % (boardWidth - 2) + 2;
        fruitAxisY = rand() % (boardHeight - 2) + 2;
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
