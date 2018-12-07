#pragma once
#pragma once
#ifndef __Cloud__
#define __Cloud__
#include "GameObject.h"
#include "TextureManager.h"
#include "SoundManager.h"

class Cloud : public GameObject {
public:
	Cloud();
	~Cloud();
	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
private:
	void _move();
	void _checkBounds();
	void _reset();
};
#endif /* defined (__Cloud__) */