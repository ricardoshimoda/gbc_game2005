#pragma once
#ifndef __BULLET__
#define __BULLET__

#include "GameObject.h"
#include "TextureManager.h"

class Bullet : public GameObject {
public:
	Bullet();
	~Bullet();
	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
private:
	void _move();
	void _checkBounds();
	void _reset();
};

#endif // defined (__BULLET__)