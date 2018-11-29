#pragma once
#ifndef __ColManager__
#define __ColManager__

#include <iostream>
#include "GameObject.h"
#include <glm/geometric.hpp>

class ColManager {
public:
	static bool check(GameObject* object1, GameObject* object2);
};


#endif /* defined (__ColManager__) */
