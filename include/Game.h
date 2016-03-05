#ifndef _GAME_H_
#define _GAME_H_

class Game
{
private:
  //Screen Width & Height
  int m_screenX;
  int m_screenY;
  int m_fps;
  //volatile int m_ticks;
  int m_oldticks;
  bool m_done;
  Player* m_player;
  Enemy* m_enemy;

  enum GameState{PLAYING,MENU,LOST,PAUSE};
  BITMAP* m_buffer;

public:
  int Init(int _screenX, int _screenY);
  void Update();
  void Quit();
};

#endif // _GAME_H_