#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player : public GameObject
{
private:
  int m_cursorX,
      m_cursorY;

public:
  Player(void);
  bool m_alive;
  int m_score;
	void HandleCursorLocation();
  void ScorePoint(int _amount);
};

#endif // _PLAYER_H_