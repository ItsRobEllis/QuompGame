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

void GameObject::CreateObject(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY)
{
  GameObject::m_locationX = x;
	GameObject::m_locationY = y;

	GameObject::m_velX = velX;
	GameObject::m_velY = velY;

	GameObject::m_dirX = dirX;
	GameObject::m_dirY = dirY;

	//Collision
	GameObject::m_boundX = boundX;
	GameObject::m_boundY = boundY;
}

void GameObject::Update()
{
  m_locationX += m_velX * m_dirX;	//Changes X using the velocity and direction of the object
	m_locationY += m_velY * m_dirY; //Also for Y
}

bool GameObject::IsColliding(GameObject *otherObject)
{

  	float _otherX = otherObject->GetX();	//If an object is within an object's boundries, return true
		float _otherY = otherObject->GetY();

		int _otherBoundX = otherObject->GetBoundX();
		int _otherBoundY = otherObject->GetBoundY();

  //Collision check
  if(m_locationX + m_boundX > _otherX - _otherBoundX &&
	  m_locationX - m_boundX < _otherX + _otherBoundX &&
	  m_locationY + m_boundY > _otherY - _otherBoundY &&
	  m_locationY - m_boundY < _otherY + _otherBoundY)
  {return true;} else {return false;}
}
