#pragma once
#ifndef __CollisionManager__
#define __CollisionManager__

// core libraries
#include <iostream>

#include "GameObject.h"
#include <GLM/gtx/norm.hpp>

class CollisionManager
{
public:
	static int squaredDistance(glm::vec2 P1, glm::vec2 P2);
	static bool squaredRadiusCheck(GameObject* object1, GameObject* object2);
	static bool bounds(GameObject* object1);
	static bool impulse(GameObject* ball, GameObject* brick);
private:
	CollisionManager();
	~CollisionManager();
};

typedef CollisionManager Collision;

#endif /* defined (__CollisionManager__) */
