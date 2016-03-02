#ifndef _GAME_H_
#define _GAME_H_
#include "Stdafx.h"

class Game
{
private:
  //Screen Width & Height
  int m_screenX;
  int m_screenY;

  int m_fps;

  enum GameState{PLAYING,MENU,LOST,PAUSE};

public:
  int InitAllegro(int _screenX, int _screenY);
  void 
};

#endif // _GAME_H_