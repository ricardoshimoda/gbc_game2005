#include "DeepSpace.h"
#include "Game.h"

DeepSpace::DeepSpace()
{
	TheTextureManager::Instance()->load("../../Assets/textures/DeepSpace.png",
		"deepspace", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("deepspace");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(0, 3));
	_reset();
	setIsColliding(false);
	//setType(GameObjectType::DEEPSPACE);

}

DeepSpace::~DeepSpace()
{
}

void DeepSpace::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("deepspace", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void DeepSpace::update()
{
	_move();
	_checkBounds();
}

void DeepSpace::clean()
{
}

void DeepSpace::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void DeepSpace::_checkBounds()
{
	if (getPosition().y >= 0)
	{
		_reset();
	}
}

void DeepSpace::_reset()
{
	setPosition(glm::vec2(0, -960));
}
