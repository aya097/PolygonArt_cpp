#pragma once
#include "../Canvas/PolygonCanvas.h"

class ColorPaletteUpdater
{
public:
	ColorPaletteUpdater(Color& color) :color(color) {};
	void Update();
	const Color& GetColor();
private:
	Color& color;
};
