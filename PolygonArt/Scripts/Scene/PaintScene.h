#pragma once
#include <Siv3D.hpp>
#include "../Canvas/PolygonCanvas.h"
#include "PaintParams.h"
#include "Selector/DrawerSelector.h"
//#include "Editor/VertexEditor.h"
//#include "Editor/PolygonEditor.h"
//#include "Drawer/VertexDrawer.h"
//#include "Drawer/PolygonDrawer.h"


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

	DrawerSelector drawSelector;
	PolygonCanvas canvas;
	Rect canvasRect;
	//PaintMode paintMode;
};

