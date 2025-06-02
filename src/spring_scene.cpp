#include "spring_scene.h"
#include "gui.h"
#include "body.h"
#include "world.h"
#include "gravitation.h"
#include "raymath.h"
#include "raygui.h"
#include <iostream>




void SpringScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ static_cast<float>(m_width) / 2, m_height / 2.0f });
	m_world = new World();
	m_world->Initialize();
	
	

}

void SpringScene::Update()
{
	float dt = GetFrameTime();

	float theta = randomf(360);
	GUI::Update();

	if (IsKeyPressed(KEY_SPACE))
	{
		World::simulate = !World::simulate;
	}
	if (IsKeyPressed(KEY_BACKSPACE))
	{
		m_world->DestroyAll();
	}

	if ( !GUI::mouseOverGUI)
	{
		if (IsMouseButtonPressed(0)) {
			auto body = m_world->CreatBody((Body::Type)GUI::DropdownBox006Active, m_camera->ScreenToWorld(GetMousePosition()),
				GUI::MassSliderValue, GUI::SizeSliderValue,GUI::RestitutionSliderValue, ColorFromHSV(randomf(360), 1, 1));

		}

		if (IsMouseButtonPressed(1))
		{
			Vector2 mousePos = m_camera->ScreenToWorld(GetMousePosition());
			m_selectedBody = GUI::GetBodyIntersect(mousePos, m_world->GetBodies(), *m_camera);
		}
		if (m_selectedBody)
		{
			if (IsMouseButtonDown(1))
			{
				Vector2 mousePos = m_camera->ScreenToWorld(GetMousePosition());
				m_connectBody = GUI::GetBodyIntersect(mousePos, m_world->GetBodies(), *m_camera);
			}
			else
			{
				if (m_selectedBody && m_connectBody)
				{
					float distance = Vector2Distance(m_selectedBody->position, m_connectBody->position);
					m_world->CreateSpring(m_selectedBody, m_connectBody, distance, GUI::SpringStiffnessSliderValue, GUI::DampingSliderValue);

				}
				m_selectedBody = nullptr;
				m_connectBody = nullptr;
			} 
		}
		
		
		
		
		
	}

	
	

	for (auto body : m_world->GetBodies())
	{
		body->gravityScale = GUI::ScaleSliderValue;
		body->damping = GUI::DampingSliderValue;

		if (body->position.y < -5)
		{
			body->position.y = -5;
			body->velocity.y *= -body->restitution;
		}

		if (body->position.x < -9)
		{
			body->position.x = -9;
			body->velocity.x *= -body->restitution;
		}
		if (body->position.x > 9)
		{
			body->position.x = 9;
			body->velocity.x *= -body->restitution;
		}

		
	}
	
}

void SpringScene::FixedUpdate()
{
	

	m_world->Step(Scene::fixedTimeStep);
}

void SpringScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, DARKGRAY);


	m_world->Draw(*this);
	if (m_selectedBody)
	{
		DrawCircleLine(m_selectedBody->position, m_selectedBody->size, YELLOW, 2);
		if (m_connectBody)
		{
			DrawCircleLine(m_connectBody->position, m_connectBody->size, YELLOW, 2);
			DrawLine(m_selectedBody->position, m_connectBody->position, 2, GREEN);

		}
		else
		{
			DrawLine(m_selectedBody->position, m_camera->ScreenToWorld(GetMousePosition()), 2, RED);
		}
	}

	m_camera->EndMode();
}

void SpringScene::DrawGUI()
{
	
	GUI::Draw();
	
}
