#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "Stdafx.h"

class GameObject
{
private:
  int m_locationX,
      m_locationY,
      m_height,
      m_width,
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
  
  BITMAP *m_sprite;

public:
  void SetupObjects();
  void CreateObject(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY);
  void Update();
  bool IsColliding(GameObject *otherObject);

  int GetX() {return m_locationX;}
	int GetY() {return m_locationY;}
	void SetX(float x) {GameObject::m_locationX = x;}
	void SetY(float x) {GameObject::m_locationY = y;}
  int GetBoundX() {return m_boundX;}
	int GetBoundY() {return m_boundY;}
}

#endif // _GAMEOBJECT_H_