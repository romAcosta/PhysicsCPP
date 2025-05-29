#pragma once
#include "world.h"
#include "raylib.h"

class GUI {

public:

	static void Update();
	static void Draw();

	static struct Body* GetBodyIntersect(const Vector2& position, bodies_t& bodies, const class SceneCamera& camera);


	inline static bool mouseOverGUI{ false };
	
	inline static Vector2 anchor01 = { 40, 24 };
	
	inline static bool PhysicsWindowBoxActive = true;
	inline static float MassSliderValue = 1.0f;
	inline static float SizeSliderValue = 0.1f;
	inline static float ScaleSliderValue = 1.0f;
	inline static float DampingSliderValue = 0.1f;
	inline static float SpringDampingSliderValue = 0.1f;
	inline static float SpringStiffnessSliderValue = 15.0f;
	inline static float GravitationSliderValue = 0.15f;
	inline static bool DropdownBox006EditMode = false;
	inline static int DropdownBox006Active = 0;

	


};