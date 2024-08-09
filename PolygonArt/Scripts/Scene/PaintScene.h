#pragma once
#include <Siv3D.hpp>
#include "../Canvas/PolygonCanvas.h"
#include "Editor/VertexEditor.h"
#include "Editor/PolygonEditor.h"
#include "Drawer/VertexDrawer.h"
#include "Drawer/PolygonDrawer.h"

enum class PaintMode
{
	ShowCanvas,
	EditVertex,
	EditPolygon,
};

struct PaintOptions
{
	bool IsPaintVertex;
	bool IsPaintPolygon;
};

class PaintScene
{
public:
	PaintScene() = default;
	void Init();
	void Update();
	void Draw();
private:
	// PaintMode に応じて PaintOptions を返す
	const PaintOptions PaintOptionSelector(PaintMode paintMode) const;

	VertexEditor vertexEditor;
	PolygonEditor polygonEditor;
	VertexDrawer vertexDrawer;
	PolygonDrawer polygonDrawer;


	PolygonCanvas canvas;
	Rect canvasRect;
	PaintMode paintMode;
};

