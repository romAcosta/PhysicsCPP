#pragma once
#include "raylib.h"

class Contact {
public:
	struct Body* bodyA;
	struct Body* bodyB;

	float restitution;	
	float depth;		
	Vector2 normal;

};