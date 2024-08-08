#pragma once
#include <Siv3D.hpp>
#include "../Canvas/PolygonCanvas.h"

struct PaintOptions
{

};

class PaintScene
{
public:
	void Init();
	void Update();
	void Draw();
private:
	PolygonCanvas canvas;
	Rect canvasRect;
};
