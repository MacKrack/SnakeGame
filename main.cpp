#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

bool gameOver();

void setup()
{
    gameOver = false;
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
