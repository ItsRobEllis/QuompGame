#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

class GameObject
{
private:
  int m_locationX,
      m_locationY,
      m_height,
      m_width,
      m_boundX,
      m_boundY,
      m_ID;
  
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
  enum m_player{PLAYER,ENEMY};
  void SetupObjects();
  void CreateObject(float _x, float _y, float _velX, float _velY, int _dirX, int _dirY, int _boundX, int _boundY);
  void Update();
  void Collided(m_player _objectID);
  bool IsColliding(GameObject *otherObject);
  bool GameObject::Collidable();

  int GetID(void){return m_ID;};
  void SetID(int const _ID){m_ID = _ID;};
  
  int GetX() {return m_locationX;}
	int GetY() {return m_locationY;}
	void SetX(float x) {GameObject::m_locationX = x;}
	void SetY(float y) {GameObject::m_locationY = y;}
  int GetBoundX() {return m_boundX;}
	int GetBoundY() {return m_boundY;}
};

#endif // _GAMEOBJECT_H_