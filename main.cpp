#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

bool gameOver();

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
    x = boardWidth / 2;
    y = boardHeight / 2;
    fruitAxisX = rand() % boardWidth;
    fruitAxisY = rand() % boardHeight;
    score = 0;
}

void draw()
{
}

void input()
{
}

void logic()
{
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
