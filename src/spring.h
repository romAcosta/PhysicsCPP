#pragma once
#include "scene.h"
#include "raylib.h"

struct Spring
{
public:
	struct Body* bodyA;
	struct Body* bodyB;
	
	float restLength;
	float stiffness;

	float damping;

public:
	Spring() = default;
	Spring(struct Body* bodyA, struct Body* bodyB, float restLength, float stiffness, float damping = 0)
		: bodyA(bodyA), bodyB(bodyB), restLength(restLength), stiffness(stiffness), damping(damping) {
	};

	void ApplyForce( float kMultiplier = 1);
	static void ApplyForce(const Vector2& position, struct Body& body, float restLength, float k, float damping);

	void Draw(const Scene& scene);

};