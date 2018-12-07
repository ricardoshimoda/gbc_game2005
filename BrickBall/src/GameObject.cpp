#include "GameObject.h"

GameObject::GameObject()
{
	m_position = glm::vec2(0, 0);
	m_rotation = glm::vec2(0, 0);
	m_scale = glm::vec2(1.0f, 1.0f);
	m_velocity = glm::vec2(0, 0);
	m_acceleration = glm::vec2(0, 0);
}

GameObject::~GameObject()
{
}


glm::vec2 GameObject::getPosition()
{
	return m_position;
}

glm::vec2 GameObject::getRotation()
{
	return m_rotation;
}

glm::vec2 GameObject::getScale()
{
	return m_scale;
}

glm::vec2 GameObject::getVelocity()
{
	return m_velocity;
}

glm::vec2 GameObject::getAcceleration()
{
	return m_acceleration;
}

int GameObject::getWidth()
{
	return m_width;
}

int GameObject::getHeight()
{
	return m_height;
}

bool GameObject::getIsCollidingX()
{
	return m_isCollidingX;
}

bool GameObject::getIsCollidingY()
{
	return m_isCollidingY;
}

GameObjectType GameObject::getType()
{
	return m_type;
}

void GameObject::setPosition(glm::vec2 newPosition)
{
	m_position = newPosition;
}

void GameObject::setWidth(int newWidth)
{
	m_width = newWidth;
}

void GameObject::setHeight(int newHeight)
{
	m_height = newHeight;
}

void GameObject::setVelocity(glm::vec2 newVelocity)
{
	m_velocity = newVelocity;
}

void GameObject::setIsCollidingX(bool collision)
{
	m_isCollidingX = collision;
}

void GameObject::setIsCollidingY(bool collision)
{
	m_isCollidingY = collision;
}

void GameObject::setType(GameObjectType newType)
{
	m_type = newType;
}
