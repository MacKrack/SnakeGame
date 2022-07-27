#include <iostream>
#include <chrono>
#include <thread>

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
    fruitAxisX = rand() % boardWidth;
    fruitAxisY = rand() % boardHeight;
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

            // blank space
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
}

void input()
{
    ;
}

void logic()
{
    ;
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
