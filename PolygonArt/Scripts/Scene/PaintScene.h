﻿#pragma once
#include <Siv3D.hpp>
#include "../Canvas/PolygonCanvas.h"
#include "PaintModeUpdater.h"
#include "Selector/DrawerSelector.h"
#include "Selector/EditorSelector.h"
#include "ColorPaletteUpdater.h"
#include "../FileIO/FileUpdater.h"


class PaintScene
{
public:
	PaintScene() = default;
	void Init();
	void Update();
	void Draw();
	~PaintScene();
private:
	PolygonCanvas canvas;
	PaintModeUpdater paintModeUpdater;
	DrawerSelector drawSelector;
	EditorSelector editSelector;
	ColorPaletteUpdater colorPaletteUpdater{canvas.polygonColor};
	FileUpdater fileUpdater;
	Rect canvasRect;
};

