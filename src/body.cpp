#include "body.h"
#include "raymath.h"
#include "world.h"
#include "Integrater.h"
#include "aabb.h"


void Body::Step(float dt)
{
	if (type != Type::Dynamic) return;
	
	acceleration = (World::gravity * gravityScale) * mass;
	acceleration += (force * (invMass)) * dt;
	
	SemiImpilicitIntegrater(*this, dt);

	
	
    
}

void Body::Draw(const Scene& scene)
{
	scene.DrawCircle(position,size,color);
}

void Body::ApplyForce(const Vector2& force)
{
	this->force += force;
}

AABB Body::GetAABB() const
{
	return AABB{ position, Vector2{ size * 2, size * 2 } }; 
}
