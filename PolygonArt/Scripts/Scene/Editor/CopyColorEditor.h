#pragma once
#include "Editor.h"
#include "../../Canvas/PolygonCanvas.h"

class CopyColorEditor : public Editor
{
public:
	void Edit(PolygonCanvas& canvas)override;
};
