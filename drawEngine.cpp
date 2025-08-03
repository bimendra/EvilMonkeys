#include <iostream>
#include <Windows.h>
#include "drawEngine.h"

using namespace std;

DrawEngine::DrawEngine(int xSize, int ySize)
{
  screenWidth = xSize;
  screenHeight = ySize;
  cursorVisibility(false);
}

DrawEngine::~DrawEngine()
{
  cursorVisibility(true);
}

int DrawEngine::createSprite(int index, char c)
{
  if (index >= 0 && index < 16)
  {
    spriteImage[index] = c;
    return index;
  }  
  return -1;
}

void DrawEngine::deleteSprite(int index)
{

}

void DrawEngine::eraseSprit(int posx, int posy)
{
  gotoxy(posx, posy);
  cout << ' ';
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
  gotoxy(posx, posy);
  cout << spriteImage[index];
}

void DrawEngine::gotoxy(int x, int y)
{
  HANDLE output_handle;
  COORD pos;
  pos.X = x;
  pos.Y = y;
  output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(output_handle, pos);
}

void DrawEngine::cursorVisibility(bool visibility)
{
  HANDLE output_handle;
  CONSOLE_CURSOR_INFO ccInfo;

  ccInfo.dwSize = 1;
  ccInfo.bVisible = visibility;

  output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleCursorInfo(output_handle, &ccInfo);
}