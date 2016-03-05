#include "Stdafx.h"
#include "Player.h"

Player::Player(void)
{
  m_cursorX = 0;
  m_cursorY = 0;

  m_alive = true;
  m_score = 0;
}

void Player::HandleCursorLocation()
{
  m_cursorX = mouse_x;
  m_cursorY = mouse_y;
};

void Player::ScorePoint(int _amount)
{
  m_score += _amount;
}
