#include "Ball.h"
#include "Game.h"

Ball::Ball()
{
	TheTextureManager::Instance()->load("../../Assets/textures/8Ball.png",
		"ball", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("ball");
	setWidth(size.x);
	setHeight(size.y);
	_reset();
	setType(GameObjectType::BALL);

	TheSoundManager::Instance()->load("../../Assets/audio/Poing.wav", "poing", sound_type::SOUND_SFX);


}

Ball::~Ball()
{
}

void Ball::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("ball", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), true);
}

void Ball::update()
{
	_move();
	_checkBounds();
}

void Ball::clean()
{
}

void Ball::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Ball::_checkBounds()
{
}

void Ball::_reset()
{
	/*
	 * Random initial position
	 */
	int halfWidth = getWidth() >> 1;
	int halfHeight = getHeight() >> 1;
	int xInitialPosition = rand() % (640 - getWidth()) + halfWidth;
	int yInitialPosition = (rand() % (480 - getHeight())) - halfHeight;
	setPosition(glm::vec2(xInitialPosition, yInitialPosition));
	setIsCollidingX(false);
	setIsCollidingY(false);
	/*
	 * Random initial velocity
	 */
	int xInitialVelocity = rand() % 20 - 10;
	int yInitialVelocity = rand() % 20 - 10;
	setVelocity(glm::vec2(xInitialVelocity, yInitialVelocity));
}

