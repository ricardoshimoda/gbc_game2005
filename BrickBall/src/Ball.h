#pragma once
#ifndef __BALL__
#define __BALL__

#include "GameObject.h"
#include "TextureManager.h"

class Ball : public GameObject {
public:
	Ball();
	~Ball();
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
