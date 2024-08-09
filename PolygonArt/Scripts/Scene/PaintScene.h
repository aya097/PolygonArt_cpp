#pragma once
#include <Siv3D.hpp>
#include "../Canvas/PolygonCanvas.h"
#include "PaintModeUpdater.h"
#include "Selector/DrawerSelector.h"
#include "Selector/EditorSelector.h"


class PaintScene
{
public:
	PaintScene() = default;
	void Init();
	void Update();
	void Draw();
private:
	// PaintMode に応じて PaintOptions を返す
	//const PaintOptions PaintOptionSelector(PaintMode paintMode) const;

	//VertexEditor vertexEditor;
	//PolygonEditor polygonEditor;
	//VertexDrawer vertexDrawer;
	//PolygonDrawer polygonDrawer;
	PaintModeUpdater paintModeUpdater;
	DrawerSelector drawSelector;
	EditorSelector editSelector;
	PolygonCanvas canvas;
	Rect canvasRect;
	//PaintMode paintMode;
};

