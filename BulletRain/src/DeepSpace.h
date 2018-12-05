#pragma once
#ifndef __DEEPSPACE__
#define __DEEPSPACE__

#include "GameObject.h"
#include "TextureManager.h"

class DeepSpace : public GameObject {
public:
	DeepSpace();
	~DeepSpace();
	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
private:
	void _move();
	void _checkBounds();
	void _reset();
};

#endif // defined (__DEEPSPACE__)