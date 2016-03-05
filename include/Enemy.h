#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy : public GameObject
{
private:
  int m_locationX,
      m_locationY,
      m_boundX,
      m_boundY;
  
  bool m_alive,
       m_collidable,
       m_isColliding;

  float m_velX, 
        m_velY, 
        m_dirX, 
        m_dirY,
        m_acceleration;
	void (*TakeLife)(void);

  PALETTE m_palette;
  BITMAP *m_enemyImage;

public:
	Enemy(float _locationX, float _locationY, char *_image);
  bool Colliding(GameObject *_otherObject);
  void Render(BITMAP* _buffer);
	void Collided(m_player objectID);
  void TrackPlayer(int _cursorX, int _cursorY);
};

#endif // _ENEMY_H_