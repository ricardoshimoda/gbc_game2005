#pragma once
#ifndef __BRICK__
#define __BRICK__

#include "GameObject.h"
#include "TextureManager.h"

class Brick : public GameObject {
public:
	Brick();
	~Brick();
	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
private:
	void _move();
	void _checkBounds();
	void _reset();
	glm::vec2 previousPosition;
};

#endif // defined (__BRICK__)
