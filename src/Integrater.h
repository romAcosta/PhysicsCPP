#pragma once
#include "body.h"
#include "raymath.h"

inline void ExplicitIntegrater(Body& body, float timeStep) {
	body.position += (body.velocity * timeStep);
	body.velocity += (body.acceleration * timeStep);
	body.velocity *= 1 / (1 + body.damping * timeStep);
}

inline void SemiImpilicitIntegrater(Body& body, float timeStep) {
	body.velocity += (body.acceleration * timeStep);
	body.position += (body.velocity * timeStep);
	
	body.velocity *= 1 / (1 + body.damping * timeStep);
}