#include "Pool.h"
#include "Game.h"

Pool::Pool()
{
	TheTextureManager::Instance()->load("../../Assets/textures/Pool.png",
		"pool", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("pool");
	setPosition(glm::vec2(0, 0));
	setWidth(size.x);
	setHeight(size.y);
	setType(GameObjectType::POOL);
	TheSoundManager::Instance()->load("../../Assets/audio/Cafe.ogg", "cafe", sound_type::SOUND_MUSIC);
	TheSoundManager::Instance()->playMusic("cafe", -1);

}

Pool::~Pool()
{
}

void Pool::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("pool", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Pool::update()
{
}

void Pool::clean()
{
}

void Pool::_move()
{
}

void Pool::_checkBounds()
{
}

void Pool::_reset()
{
}
