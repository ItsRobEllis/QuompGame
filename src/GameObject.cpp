#include "Stdafx.h"
#include "GameObject.h"

void GameObject::SetupObjects()
{
	m_locationX = 0;
	m_locationY = 0;
	m_velX = 0;
	m_velY = 0;
	m_dirX = 0;
	m_dirY = 0;
	m_boundX = 0;
	m_boundY = 0;
	m_sprite = NULL;
	m_alive = true;
	m_collidable = true;
  m_isColliding = false;
}

void GameObject::CreateObject(float _x, float _y, float _velX, float _velY, int _dirX, int _dirY, int _boundX, int _boundY)
{
  GameObject::m_locationX = _x;
	GameObject::m_locationY = _y;
	GameObject::m_velX = _velX;
	GameObject::m_velY = _velY;
	GameObject::m_dirX = _dirX;
	GameObject::m_dirY = _dirY;
  
	//Collision
	GameObject::m_boundX = _boundX;
	GameObject::m_boundY = _boundY;
}

void GameObject::Update()
{
  m_locationX += m_velX * m_dirX;	//Changes X using the velocity and direction of the object
	m_locationY += m_velY * m_dirY; //Also for Y
}

bool GameObject::IsColliding(GameObject *_otherObject)
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

void GameObject::Collided(m_player _objectID)
{}

bool GameObject::Collidable()
{
	return m_alive && m_collidable;
}
