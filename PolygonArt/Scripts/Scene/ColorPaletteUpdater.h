#pragma once
#include "../Canvas/PolygonCanvas.h"

class ColorPaletteUpdater
{
public:
	void Update();
	const Color& GetColor();
private:
	Color color = Palette::White;
};
