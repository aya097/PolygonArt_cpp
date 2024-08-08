#pragma once
#include <Siv3D.hpp>
#include "../Canvas/PolygonCanvas.h"
#include "Editor/VertexEditor.h"

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
	PolygonCanvas canvas;
	Rect canvasRect;
	PaintMode paintMode;
};

