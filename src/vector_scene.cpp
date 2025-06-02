#include "vector_scene.h"
#include "gui.h"
#include "body.h"
#include "world.h"
#include "gravitation.h"
#include "raymath.h"
#include "raygui.h"
#include <iostream>
#include "aabb.h"




void VectorScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ static_cast<float>(m_width) / 2, m_height / 2.0f });
	m_world = new World();
	m_world->Initialize();
	
	

}

void VectorScene::Update()
{
	float dt = GetFrameTime();

	float theta = randomf(360);
	GUI::Update();


	if (IsMouseButtonPressed(0) && !GUI::mouseOverGUI)
	{
		for (int i = 0; i < 20; i++)
		{
			auto body = m_world->CreatBody(m_camera->ScreenToWorld(GetMousePosition()), 0.05f, ColorFromHSV(randomf(360),1,1));
			float offset =  randomf();//randomf();
			float x = cosf(theta * offset);
			float y = sinf(theta * offset);
			body->velocity += Vector2{ x, y } * randomf(3, 15);
		}
		
	}

	
	

	for (auto body : m_world->GetBodies())
	{
		body->mass = GUI::MassSliderValue;
		body->size = GUI::SizeSliderValue;
		body->gravityScale = GUI::ScaleSliderValue;
		body->damping = GUI::DampingSliderValue;
		body->restitution = GUI::RestitutionSliderValue;


		switch (GUI::DropdownBox006Active)
		{
		case 0: // Dynamic
			body->type = Body::Type::Dynamic;
			break;
		case 1: // Kinematic
			body->type = Body::Type::Kinematic;
			break;
		case 2: // Static
			body->type = Body::Type::Static;
			break;

		default:
			break;
		}
	}

	for (auto body : m_world->GetBodies())
	{
		AABB aabb = body->GetAABB();
		AABB worldAABB = m_camera->GetAABB();

		if ((aabb.min().y) < worldAABB.min().y)
		{
			float overlap = (worldAABB.min().y - aabb.min().y); // calculate how far the body has penetrated beyond the world boundary
			body->position.y += 2 * overlap; // move the body back inside the world bounds
			body->velocity.y *= -body->restitution; // multiple by -restituion to scale and flip velocity
		}
		else if ((aabb.max().y) > worldAABB.max().y)
		{
			float overlap = (worldAABB.max().y - aabb.max().y);  // calculate how far the body has penetrated beyond the world boundary
			body->position.y += 2 * overlap; // move the body back inside the world bounds
			body->velocity.y *= -body->restitution; // multiple by -restituion to scale and flip velocity
		}

		if ((aabb.min().x) < worldAABB.min().x)
		{
			
			float overlap = (worldAABB.min().x - aabb.min().x); // calculate how far the body has penetrated beyond the world boundary
			body->position.x += 2 * overlap; // move the body back inside the world bounds
			body->velocity.x *= -body->restitution; // multiple by -restituion to scale and flip velocity
			
		}
		else if (aabb.max().x > worldAABB.max().x)
		{
			
			float overlap = (worldAABB.max().x - aabb.max().x);  // calculate how far the body has penetrated beyond the world boundary
			body->position.x += 2 * overlap; // move the body back inside the world bounds
			body->velocity.x *= -body->restitution; // multiple by -restituion to scale and flip velocity
		}
	}
	
}

void VectorScene::FixedUpdate()
{
	

	m_world->Step(Scene::fixedTimeStep);
}

void VectorScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, DARKGRAY);

	m_world->Draw(*this);

	m_camera->EndMode();
}

void VectorScene::DrawGUI()
{
	
	GUI::Draw();
	
}
