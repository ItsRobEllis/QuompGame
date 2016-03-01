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

public:
  void InitAllegro(int _screenX, int _screenY);
  
};

#endif // _GAME_H_