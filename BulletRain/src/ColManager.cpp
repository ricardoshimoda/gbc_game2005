#include "ColManager.h"
#include "Game.h"

bool ColManager::check(GameObject* object1, GameObject* object2)
{
	glm::vec2 P1 = object1->getPosition();
	glm::vec2 P2 = object2->getPosition();
	int halfHeights = (object1->getHeight() + object2->getHeight()) * 0.5;
	if (glm::distance(P1, P2) < halfHeights) {
		if (!object2->getIsColliding()) {
			std::cout << "Collision with " + object2->getName() << std::endl;
			object2->setIsColliding(true);
		}
	}
	else {
		object2->setIsColliding(false);
	}

	return false;
}
