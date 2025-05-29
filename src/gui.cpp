#include "gui.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "world.h"

#define GUI_DATA(data) TextFormat("%.2F" , data), & data

void GUI::Update()
{
	mouseOverGUI = PhysicsWindowBoxActive && CheckCollisionPointRec(GetMousePosition(), Rectangle{ anchor01.x + -24, anchor01.y + 0, 288, 592 });
	if (IsKeyPressed(KEY_TAB)) PhysicsWindowBoxActive = !PhysicsWindowBoxActive;
}

void GUI::Draw()
{
	if (DropdownBox006EditMode) GuiLock();

	if (PhysicsWindowBoxActive)
	{
		PhysicsWindowBoxActive = !GuiWindowBox(Rectangle{ anchor01.x + -24, anchor01.y + 0, 288, 592 }, "Physics");
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 48, 120, 16 }, "Gravity", GUI_DATA(World::gravity.y), -20, 20);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 112, 120, 16 }, "Mass", GUI_DATA(MassSliderValue), 0, 5);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 136, 120, 16 }, "Size", GUI_DATA(SizeSliderValue), .01f, 2);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 160, 120, 16 }, "Gravity Scale", GUI_DATA(ScaleSliderValue), 0, 5);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 184, 120, 16 }, "Damping", GUI_DATA(DampingSliderValue), 0, 5);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 204, 120, 16 }, "S-Damping", GUI_DATA(SpringDampingSliderValue), 0, 5);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 224, 120, 16 }, "Stiffness", GUI_DATA(SpringStiffnessSliderValue), 1, 30);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 244, 120, 16 }, "Stiffness", GUI_DATA(World::springStiffnessMultiplier), 1, 30);
		GuiSlider(Rectangle{ anchor01.x + 72, anchor01.y + 320, 120, 16 }, "Gravitation", GUI_DATA(GravitationSliderValue), 0, 15);
		if (GuiDropdownBox(Rectangle{ anchor01.x + 72, anchor01.y + 280, 120, 24 }, "Dynamic;Kinematic;Static", &DropdownBox006Active, DropdownBox006EditMode)) {

			DropdownBox006EditMode = !DropdownBox006EditMode;
		}
	}

	GuiUnlock();
}

Body* GUI::GetBodyIntersect(const Vector2& position, bodies_t& bodies, const SceneCamera& camera)
{
	for (auto body : bodies)
	{
		if (CheckCollisionPointCircle(position, body->position, body->size))
		{
			return body;
		}
	}
	return nullptr;
}
