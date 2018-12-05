#include "Bullet.h"
#include "Game.h"

Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../../Assets/textures/Bullet.png",
		"bullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("bullet");
	setWidth(size.x);
	setHeight(size.y);
	/*
	 * goes down 10px/frame
	 */
	setVelocity(glm::vec2(0, 10));
	_reset();
	setIsColliding(false);
	setType(GameObjectType::BULLET);

	TheSoundManager::Instance()->load("../../Assets/audio/Explosion.wav", "explosion", sound_type::SOUND_SFX);


}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("bullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Bullet::update()
{
	_move();
	_checkBounds();
}

void Bullet::clean()
{
}

void Bullet::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Bullet::_checkBounds()
{
	if (getPosition().y > 480 + getHeight()) {
		_reset();
	}
}

void Bullet::_reset()
{
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (640 - getWidth()) + halfWidth + 1;
	int yComponent = -(rand() % (640 - getWidth())) - getHeight();
	setPosition(glm::vec2(xComponent, yComponent));
	setIsColliding(false);
}
