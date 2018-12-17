#include "CollisionManager.h"
#include "SoundManager.h"
#include "Game.h"

int CollisionManager::squaredDistance(glm::vec2 P1, glm::vec2 P2)
{
	int diffOfXs = P2.x - P1.x;
	int diffOfYs = P2.y - P1.y;
	int result = diffOfXs * diffOfXs + diffOfYs * diffOfYs;
	return result;
}

bool CollisionManager::bounds(GameObject *bouncingObject) {
	int halfHeight = bouncingObject->getHeight() >> 1;
	int halfWidth = bouncingObject->getWidth() >> 1;
	glm::vec2 currentPosition = bouncingObject->getPosition();
	glm::vec2 currentVelocity = bouncingObject->getVelocity();
	bool collisionHappenedX = false;
	bool collisionHappenedY = false;
	/*
	 * At least it never ever leaves the screen - even if it is neccessary to stop it!
	 */
	if (currentPosition.x < halfWidth && currentVelocity.x < 0) {
		currentVelocity.x *= BOUNCE_FACTOR;
		collisionHappenedX = true;
	}
	if (currentPosition.x > SCREEN_WIDTH - halfWidth && currentVelocity.x > 0) {
		currentVelocity.x *= BOUNCE_FACTOR;
		collisionHappenedX = true;
	}
	if (currentPosition.y < halfHeight && currentVelocity.y < 0) {
		currentVelocity.y *= BOUNCE_FACTOR;
		collisionHappenedY = true;
	}
	if (currentPosition.y > SCREEN_HEIGHT - halfHeight && currentVelocity.y > 0) {
		currentVelocity.y *= BOUNCE_FACTOR;
		collisionHappenedY = true;
	}
	if (collisionHappenedX || collisionHappenedY) bouncingObject->setVelocity(currentVelocity);

	if (!collisionHappenedX)
		bouncingObject->setIsCollidingX(false);
	if (!collisionHappenedY)
		bouncingObject->setIsCollidingY(false);

	if (!bouncingObject->getIsCollidingX() && collisionHappenedX) {
		bouncingObject->setIsCollidingX(true);
		TheSoundManager::Instance()->playSound("poing", 0);
		// play sound
	}
	if (!bouncingObject->getIsCollidingY() && collisionHappenedY) {
		bouncingObject->setIsCollidingY(true);
		TheSoundManager::Instance()->playSound("poing", 0);
		// play sound
	}

	return collisionHappenedX || collisionHappenedY;
}

bool CollisionManager::impulse(GameObject * ball, GameObject * brick)
{
	int ballX = ball->getPosition().x;
	int ballY = ball->getPosition().y;
	int radius = ball->getHeight() >> 1; //(or width....)
	glm::vec2 ballVelocity = ball->getVelocity();

	int brickX = brick->getPosition().x;
	int brickY = brick->getPosition().y;
	int halfWidth = brick->getWidth() >> 1;
	int halfHeight = brick->getHeight() >> 1;
	glm::vec2 brickVelocity = brick->getVelocity();


	/* 
	 * Collision with the left side of the rectangle
	 */
	
	if ((ballX < brickX)
		&& (ballX + radius >= brickX - halfWidth)
		&& (ballY > brickY - halfHeight)
		&& (ballY < brickY + halfHeight))
	{
		//std::cout << "Collision side left" << std::endl;
		if(abs(brickVelocity.x) < 0.5 && ballVelocity.x > 0) {
			ballVelocity.x *= -1;
		}
		else {
			ballVelocity.x = /*ballVelocity.x +*/ brickVelocity.x;
		}
		ball->setVelocity(ballVelocity);
		TheSoundManager::Instance()->playSound("points", 0);
	}
	if ((ballX > brickX)
		&& (ballX - radius <= brickX + halfWidth)
		&& (ballY > brickY - halfHeight)
		&& (ballY < brickY + halfHeight))
	{
		//std::cout << "Collision side right" << std::endl;
		if (abs(brickVelocity.x) < 0.5 && ballVelocity.x > 0) {
			ballVelocity.x *= -1;
		}
		else {
			ballVelocity.x = /*ballVelocity.x +*/ brickVelocity.x;
		}
		ball->setVelocity(ballVelocity);
		TheSoundManager::Instance()->playSound("points", 0);
		
	}
	if ((ballY > brickY)
		&& (ballY - radius <= brickY + halfHeight)
		&& (ballX > brickX - halfWidth)
		&& (ballX < brickX + halfWidth)) {
		//std::cout << "Collision side down" << std::endl;
		if (abs(brickVelocity.y) < 0.5 && ballVelocity.y < 0) {
			ballVelocity.y *= -1;
		}
		else {
			ballVelocity.y = brickVelocity.y;
		}
		ball->setVelocity(ballVelocity);
		TheSoundManager::Instance()->playSound("points", 0);
	}
	if ((ballY < brickY)
		&& (ballY + radius >= brickY - halfHeight)
		&& (ballX > brickX - halfWidth)
		&& (ballX < brickX + halfWidth)) {
		if (abs(brickVelocity.y) < 0.5 && ballVelocity.y > 0) {
			ballVelocity.y *= -1;
		}
		else {
			ballVelocity.y = brickVelocity.y;
		}
		ball->setVelocity(ballVelocity);
		TheSoundManager::Instance()->playSound("points", 0);
	}
	return false;
}


bool CollisionManager::squaredRadiusCheck(GameObject *object1, GameObject *object2)
{
	glm::vec2 P1 = object1->getPosition();
	glm::vec2 P2 = object2->getPosition();
	int halfHeights = (object1->getHeight() + object2->getHeight()) * 0.5;

	//if (glm::distance(P1, P2) < halfHeights) {

	if (CollisionManager::squaredDistance(P1, P2) < (halfHeights * halfHeights)) {
		if (!object2->getIsCollidingY()) {
			
			object2->setIsCollidingY(true);

			switch (object2->getType()) {
			case BRICK:
				std::cout << "Collision with Bullet!" << std::endl;
				TheSoundManager::Instance()->playSound("points", 0);
				break;
			default:
				std::cout << "Collision with unknown type!" << std::endl;
					break;
			}

			return true;
		}
		return false;
	}
	else
	{
		object2->setIsCollidingY(false);
		return false;
	}
	
}

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}
