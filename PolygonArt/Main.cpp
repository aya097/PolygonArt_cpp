# include <Siv3D.hpp>
#include "Scripts/Scene/PaintScene.h"

void Main()
{
	Window::Resize(1920, 1080);

	PaintScene scene;

	scene.Init();

	while (System::Update())
	{
		scene.Update();
		scene.Draw();
	}
}
