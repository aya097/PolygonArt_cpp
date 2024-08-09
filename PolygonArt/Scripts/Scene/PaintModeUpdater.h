#pragma once
#include "PaintParams.h"

class PaintModeUpdater
{
public:
	void Update();
	const PaintMode& GetPaintMode() const;
private:
	PaintMode paintMode = PaintMode::ShowCanvas;
};
