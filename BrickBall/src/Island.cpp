#include "Island.h"
#include "Game.h"
#include <stdlib.h>

Island::Island()
{
	TheTextureManager::Instance()->load("../../Assets/textures/island.png", "island", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("island");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(0, 5));
	_reset();
	setName("Island");
	setIsColliding(false);
}

Island::~Island()
{
}

void Island::draw()
{
	TheTextureManager::Instance()->draw("island", getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(), true);
}

void Island::update()
{
	_move();
	_checkBounds();
}

void Island::clean()
{
}

void Island::_move()
{
	glm::vec2 currentPosition = getPosition();
	glm::vec2 currentVelocity = getVelocity();
	setPosition(glm::vec2(currentPosition.x + currentVelocity.x, 
		                  currentPosition.y + currentVelocity.y));
}

void Island::_reset()
{
	int higherLimit = 640 - (int)(getWidth() / 2);
	int lowerLimit = (int)(getWidth() / 2);
	int xInitialPosition = rand() % higherLimit + 1 + lowerLimit;
	setPosition(glm::vec2(xInitialPosition, -getHeight()));

}

void Island::_checkBounds()
{
	// checks if the object has reached the lower bounds of the screen
	if (getPosition().y > 480.0f + getHeight()) {
		_reset();
	}
}
