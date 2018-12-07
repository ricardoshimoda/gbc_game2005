#include "Brick.h"
#include "Game.h"
#include <iostream>

Brick::Brick()
{
	TheTextureManager::Instance()->load("../../Assets/textures/Brick.png",
		"brick", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("brick");
	setWidth(size.x);
	setHeight(size.y);
	int halfWidth = getWidth() >> 1;
	int halfHeight = getHeight() >> 1;
	glm::vec2 firstPosition(SCREEN_HEIGHT/2- halfHeight,SCREEN_WIDTH/2- halfWidth);
	setPosition(firstPosition);
	previousPosition = firstPosition;
	setIsCollidingX(false);
	setIsCollidingY(false);
	setType(GameObjectType::BRICK);

	TheSoundManager::Instance()->load("../../Assets/audio/points.wav", "points", sound_type::SOUND_SFX);
}

Brick::~Brick()
{
}

void Brick::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("brick", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), true);
}

void Brick::update()
{
	_move();
	_checkBounds();
}

void Brick::clean()
{
}

void Brick::_move()
{
	glm::vec2 mouseVector = TheGame::Instance()->getMousePosition();
	setPosition(glm::vec2(mouseVector.x, mouseVector.y));

	glm::vec2 velocity;
	velocity.x = mouseVector.x - previousPosition.x;
	velocity.y = mouseVector.y - previousPosition.y;
	setVelocity(velocity);

	std::cout << "Velocity X:" << velocity.x << " | Velocity Y:" << velocity.y << std::endl;

	previousPosition = glm::vec2(mouseVector.x, mouseVector.y);
}

void Brick::_checkBounds()
{
}

void Brick::_reset()
{
}
