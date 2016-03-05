#include "Stdafx.h"
#include "Enemy.h"

Enemy::Enemy(float _locationX, float _locationY, char *_image)
{
  SetID(ENEMY);
  m_locationX = 0;
  m_locationY = 0;
  m_boundX = 128;
  m_boundY = 128;

  m_alive = true;
  m_collidable = true;
  m_isColliding = false;
  
  m_velX = 0;
  m_velY = 0;
  m_dirX = 0;
  m_dirY = 0;


  m_enemyImage = load_bitmap(_image, m_palette);
}

// This handles collisions in the enemy
bool Enemy::Colliding(GameObject *_otherObject)
{
  float _otherX = _otherObject->GetX();	//If an object is within an object's boundries, return true
  float _otherY = _otherObject->GetY();
  int _otherBoundX = _otherObject->GetBoundX();
  int _otherBoundY = _otherObject->GetBoundY();
  
  //Collision check
  if(m_locationX + m_boundX > _otherX - _otherBoundX &&
     m_locationX - m_boundX < _otherX + _otherBoundX &&
     m_locationY + m_boundY > _otherY - _otherBoundY &&
     m_locationY - m_boundY < _otherY + _otherBoundY)
  {return true;} else {return false;}
}

void Enemy::Render(BITMAP* _buffer)
{
  blit(m_enemyImage, _buffer, 0, 0, 50, 50, 128, 128);
}

void Enemy::Collided(m_player _objectID)
{
	if(_objectID == PLAYER)
	{
		//KillPlayer();
    //SetAlive(false);
	} 
  else
  {
    //_player->ScorePoint(1);
  }
}

void Enemy::TrackPlayer(int _cursorX, int _cursorY)
{
  
}