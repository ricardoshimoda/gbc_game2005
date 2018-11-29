#pragma once
#ifndef __Island__
#define __Island__

#include "GameObject.h"
#include "TextureManager.h"

class Island : public GameObject {
public:
	Island();
	~Island();

	// Draw the object
	void draw();

	// Update the object
	void update();

	// remove anything that needs to be deleted
	void clean();
private:
	void _move();
	void _reset();
	void _checkBounds();
};


#endif /* defined (__Island__) */
