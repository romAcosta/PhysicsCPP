#pragma once
#include "raylib.h"
#include "scene.h"


class World;

struct Body {

public:
	enum class Type {
		Dynamic,
		Kinematic,
		Static
		
		
	};

public:
	Body() = default;
	Body(const Vector2& pos, const Vector2& vel, float s, const Color& c) :
		position{ pos }, 
		velocity{ vel }, 
		size{ s },
		color{ c } 
	{}
	Body(const Vector2& pos,  float s, const Color& c) : // No Velocity
		position{ pos }, 
		size{ s },
		color{ c } 
	{}

	Body(Type type, const Vector2& pos,float mass, float s, const Color& c) : // No Velocity
		type{ type },
		position{ pos },
		mass{ mass },
		size{ s },
		color{ c }
	{

		invMass = (type == Type::Dynamic && mass != 0)? 1 / mass : 0;
	}
	
	Body(Type type, const Vector2& pos,float mass, float s,float restitution, const Color& c) : // No Velocity
		type{ type },
		position{ pos },
		mass{ mass },
		size{ s },
		restitution{restitution},
		color{ c }
	{

		invMass = (type == Type::Dynamic && mass != 0)? 1 / mass : 0;
	}


	void Step(float dt);
	void Draw(const Scene& scene);
	void ApplyForce(const Vector2& force);
	void ClearForce() { force = Vector2{ 0,0 }; }

	Body* next{ nullptr };
	Body* prev{ nullptr };

	struct AABB GetAABB() const;

public:
	Type type{ Type::Dynamic };

	Vector2 position{ 0,0 };
	Vector2 velocity{ 0,0 };
	Vector2 acceleration{ 0,0 };
	Vector2 force{ 0,0 };

	float gravityScale{ 1 };
	float mass{ 1 };
	float invMass{ 1 };
	float restitution{ 1.0f }; // Bounciness

	float damping{ 0.3f };
	float size{ 1 };
	Color color{ WHITE };

	

};;