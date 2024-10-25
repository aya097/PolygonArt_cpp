#pragma once
#include "PaintParams.h"

class PaintModeUpdater
{
public:
	void Init();
	void Update();
	const PaintMode& GetPaintMode() const;
private:
	PaintMode paintMode = PaintMode::ShowCanvas;
	const Font instructionFont{ 15 };
	std::unordered_map<PaintMode, String> instructionTexts;
};
