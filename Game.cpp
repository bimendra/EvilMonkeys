#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "game.h"

using namespace std;
constexpr auto GAME_SPEED = 500;

bool Game::run(void)
{
  drawArea.createSprite(0, '$');  

  char key = ' ';
  startTime = timeGetTime();
  frameCount = 0;
  lastTime = 0;

  posx = 0;

  while (key != 'q')
  {
    while (!getInput(&key))
    {
      timerUpdate();      
    }
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
  drawArea.eraseSprit(posx, 5);
  posx = (posx + 1) % 80;
  drawArea.drawSprite(0, posx, 5);
  frameCount++;
  lastTime = timeGetTime();
}