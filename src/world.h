#pragma once
#include <vector>
#include "body.h"
#include "spring.h"
#include "raylib.h"
#include "contact.h"

using bodies_t = std::vector<Body*>;
using springs_t = std::vector<Spring*>;
using contacts_t = std::vector<Contact>;

class World
{
public:
	World() = default;
	~World();
	friend class VectorScene;

	void Initialize(Vector2 gravity = Vector2 {0,-9.81f}, size_t poolSize = 30);

	Body* CreatBody(const Vector2& position, float size, const Color& color);
	Body* CreatBody(Body::Type type, const Vector2& position, float mass, float size, float restitution, const Color& color);

	Spring* CreateSpring(Body* bodyA, Body* bodyB, float restLength, float stiffness, float damping);

	void Step(float timeStep);
	void Draw(const class Scene& scene) const;
	void DestroyAll();

	bodies_t& GetBodies() { return m_bodies; };
	inline static Vector2 gravity{0,-9.81};
	inline static float gravitation{ 0 };
	inline static float springStiffnessMultiplier{ 1 };
	inline static bool simulate{ true };

private:
	
	bodies_t m_bodies;
	springs_t m_springs;
	contacts_t m_contacts;

};

