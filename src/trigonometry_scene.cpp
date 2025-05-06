#include "trigonometry_scene.h"

void TrigonometryScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ static_cast<float>(m_width) / 2, m_height / 2.0f });
}

void TrigonometryScene::Update()
{
}


float DegToRad(float degrees)
{
	return degrees * (PI / 180.0f);
}

float RadToDeg(float radians)
{
	return radians * (180.0f / PI);
}

float Vector2Length(const Vector2& v) 
{
	return sqrtf(v.x * v.x + v.y * v.y);
}

Vector2 Vector2Normalize(const Vector2& v)
{
	float length = Vector2Length(v);
	if (length == 0) return { 0, 0 };
	return { v.x / length, v.y / length };
}

void TrigonometryScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, WHITE);
	//Scene::DrawCircle(Vector2{ 0, 0 },1, RED);

	float radius = 3.0f;
	int steps = 100;
	
	float rate = 0.5f;
	float time = ((float) GetTime()) * rate;

	float radians = 180 * DEG2RAD;

	for (int i = 0; i < steps; i++) 
	{ 
		float theta = time + i / (float) steps * (2 * PI);
		float x = 2* cosf(theta) * radius;
		float y = sinf(theta) * radius;

		DrawCircle(Vector2{ x, y }, 0.25f, RED);
	}

	for (float x = -10; x < 10; x += 0.2f)
	{
		float theta = time + (x / 20) * (2 * PI);
		float y = cosf(theta) * radius;
		float s =-1 *  cosf(theta) * radius;
		


		DrawCircle(Vector2{ x, y }, 0.25f, GREEN);
		DrawCircle(Vector2{ x, s }, 0.25f, PINK);
	}

	float theta = -time;
	float x = cosf(theta) * radius;
	float y = sinf(theta) * radius;
	DrawCircle(Vector2{ x, y }, 0.5f, BLUE);


	m_camera->EndMode();
}

void TrigonometryScene::DrawGUI()
{
}


