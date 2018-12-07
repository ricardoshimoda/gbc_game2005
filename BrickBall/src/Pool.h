#pragma once
#ifndef __POOL__
#define __POOL__

#include "GameObject.h"
#include "TextureManager.h"

class Pool : public GameObject {
public:
	Pool();
	~Pool();
	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
private:
	void _move();
	void _checkBounds();
	void _reset();
};

#endif // defined (__POOL__)