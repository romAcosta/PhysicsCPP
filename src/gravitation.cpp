#include "gravitation.h"
#include "raymath.h"

void ApplyGravitation(bodies_t& bodies, float strength)
{
	for (int i = 0; i < bodies.size(); i++) {

		for (int j = i + 1; j < bodies.size(); j++) {


			Vector2 direction = bodies[j]->position - bodies[i]->position;
			float distance = Vector2Length(direction);
			if (distance == 0) continue; // Avoid division by zero
			direction = Vector2Normalize(direction);
			float forceMagnitude = strength * (bodies[i]->mass * bodies[j]->mass) / (distance * distance);
			Vector2 force = Vector2Scale(direction, forceMagnitude);
			bodies[i]->ApplyForce(force);
			bodies[j]->ApplyForce(Vector2Negate(force));
		}
	}
}
