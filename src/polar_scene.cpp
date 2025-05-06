#include "polar_scene.h"
#include "polar.h"



void DrawArchimedeanSpiral(float a, float b)
{
    float rate = 2.0f;
    float time = ((float)GetTime()) * rate;

    float step = 0.01f;
    float maxAngle = 30 * 2 * PI;

    Vector2 prev;
    bool first = true;

    for (float theta = 0; theta < maxAngle; theta += step)
    {
        float r = a + b * (theta + time);
        Polar p(theta, r);
        Vector2 current = p;

        if (!first)
            DrawLineV(prev, current, Color{ (unsigned char)((time + 10) * 10), 100, 100, 255 });
        else
            first = false;

        prev = current;
    }
}

void DrawCardioid(float a)
{
    float rate = 2.0f;
    float time = ((float)GetTime()) * rate;

    float step = 0.01f;
    float maxAngle = 30 * 2 * PI;

    Vector2 prev;
    bool first = true;

    for (float theta = 0; theta < maxAngle; theta += step)
    {
        float r = a * (cos(theta) + 1);
        Polar p(theta, r);
        Vector2 current = p;

        if (!first)
            DrawLineV(prev, current, Color{ (unsigned char)((time + 10) * 10), 100, 100, 255 });
        else
            first = false;

        prev = current;
    }
}

void DrawLimacon(float a, float b)
{
    float rate = 2.0f;
    float time = ((float)GetTime()) * rate;

    float step = 0.01f;
    float maxAngle = 30 * 2 * PI;

    Vector2 prev;
    bool first = true;

    for (float theta = 0; theta < maxAngle; theta += step)
    {
        float r = a + b * cos(theta);
        Polar p(theta, r);
        Vector2 current = p;

        if (!first)
            DrawLineV(prev, current, Color{ (unsigned char)((time + 10) * 10), 100, 100, 255 });
        else
            first = false;

        prev = current;
    }
}

void DrawRoseCurve(float a, int k)
{
    float rate = 2.0f;
    float time = ((float)GetTime()) * rate;

    float step = 0.01f;
    float maxAngle = 30 * 2 * PI;

    Vector2 prev;
    bool first = true;

    for (float theta = 0; theta < maxAngle; theta += step)
    {
        float r = a * cos(k * (theta+ time));
        Polar p(theta, r);
        Vector2 current = p;

        if (!first)
            DrawLineV(prev, current, Color{ (unsigned char)((time + 10) * 10), 100, 100, 255 });
        else
            first = false;

        prev = current;
    }
}

void DrawUserDefined(float a)
{
    float rate = 2.0f;
    float time = ((float)GetTime()) * rate;
    float scale = 200;
    float step = 0.01f;
    float maxAngle = 160 * 2 * PI;

    Vector2 prev;
    bool first = true;

    for (float theta = 0; theta < maxAngle; theta += step)
    {
        float r = sqrt(cos(theta * 2));
        Polar p(theta, r * scale);
        Vector2 current = p;

        if (!first)
            DrawLineV(prev, current, Color{ (unsigned char)((time + 10) * 10), 100, 100, 255 });
        else
            first = false;

        prev = current;
    }
}


void PolarScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ static_cast<float>(m_width) / 2, m_height / 2.0f });
}

void PolarScene::Update()
{

}

void PolarScene::Draw()
{
	m_camera->BeginMode();

	
	
    //DrawArchimedeanSpiral(4, 6);
    //DrawLimacon(300, 400);
    //DrawCardioid(300);
    DrawUserDefined(30);
    //DrawRoseCurve(300, 25);
    
	m_camera->EndMode();
}

void PolarScene::DrawGUI()
{
}

