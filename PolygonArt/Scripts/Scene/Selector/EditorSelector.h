#pragma once
#include "../PaintParams.h"
#include "../Editor/Editor.h"
#include "../Editor/VertexEditor.h"
#include "../Editor/PolygonEditor.h"

class EditorSelector
{
public:
	EditorSelector();
	const std::shared_ptr<Editor> SelectByPaintMode(const PaintMode& paintMode);
private:
	std::unordered_map<PaintMode, std::shared_ptr<Editor>> editors;
};
