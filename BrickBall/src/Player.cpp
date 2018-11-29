#include "Player.h"
#include "Game.h"

Player::Player()
{
	TheTextureManager::Instance()->load("../../Assets/textures/plane.png", "player", TheGame::Instance()->getRenderer());
	setPosition(glm::vec2(0, 430.0f));
	
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);
	setName("Player");
	setIsColliding(false);
}

Player::~Player()
{
}

void Player::draw()
{
	TheTextureManager::Instance()->draw("player", getPosition().x, getPosition().y, TheGame::Instance()->getRenderer(), true);
}

void Player::update()
{
	glm::vec2 mouseVector = TheGame::Instance()->getMousePosition();

	setPosition(glm::vec2(mouseVector.x, getPosition().y));
}

void Player::clean()
{
}
