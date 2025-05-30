#include "world.h"
#include "body.h"
#include "gui.h"
#include "gravitation.h"
#include "collision.h"



World::~World()
{

}

void World::Initialize(Vector2 gravity, size_t poolSize)
{
	this->gravity = gravity;
	m_bodies.reserve(poolSize);
}

Body* World::CreatBody(const Vector2& position, float size, const Color& color)
{
	Body* body = new Body(position,size,color);
	//Body* body = new Body(position,size,color);
	m_bodies.push_back(body);

    return body;
}

Body* World::CreatBody(Body::Type type, const Vector2& position, float mass, float size, const Color& color)
{
	Body* body = new Body(type,position, mass, size, color);
	
	m_bodies.push_back(body);
	return body;
}

Spring* World::CreateSpring(Body* bodyA, Body* bodyB, float restLength, float stiffness, float damping)
{
	Spring* spring = new Spring(bodyA, bodyB, restLength, stiffness, damping);
	m_springs.push_back(spring);
	return spring;
}

void World::Step(float timeStep)
{
	if (!simulate) return;

	for (auto spring : m_springs)
	{
		spring->ApplyForce(springStiffnessMultiplier);
	}

	if(GUI::GravitationSliderValue > 0) ApplyGravitation(m_bodies, GUI::GravitationSliderValue);
	for (auto body : m_bodies)
	{
		body->Step(timeStep);
		body->ClearForce();
	}

	m_contacts.clear();
	CreateContacts(m_bodies, m_contacts);
	SeparateContacts(m_contacts);
}

void World::Draw(const Scene& scene) const
{
	for (auto body : m_bodies)
	{
		body->Draw(scene);
	}
	for (auto spring : m_springs)
	{
		spring->Draw(scene);
	}	
}

void World::DestroyAll()
{
	for (auto body : m_bodies)
	{
		delete body;
	}
	for (auto spring : m_springs)
	{
		delete spring;
	}
	m_bodies.clear();
	m_springs.clear();
}
