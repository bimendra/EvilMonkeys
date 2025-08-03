#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "game.h"

using namespace std;
constexpr auto GAME_SPEED = 33.3333;

bool Game::run(void)
{
  char key = ' ';
  startTime = timeGetTime();
  frameCount = 0;
  lastTime = 0;

  while (key != 'q')
  {
    while (!getInput(&key))
    {
      timerUpdate();
    }
    cout << frameCount << endl;
    cout << frameCount / ((timeGetTime() - startTime) / 1000) << "fps" << endl;
  }
  
  return true;
}

bool Game::getInput(char* c)
{
  if (_kbhit())
  {
    *c = _getch();
    return true;
  }
  return false;
}

void Game::timerUpdate()
{
  double currentTime = timeGetTime() - lastTime;
  if (currentTime < GAME_SPEED)
  {
    return;
  }
  frameCount++;
  lastTime = timeGetTime();
}