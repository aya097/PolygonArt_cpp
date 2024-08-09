#pragma once
#include "Editor.h"
#include "../../Canvas/PolygonCanvas.h"

class ApplyColorEditor : public Editor
{
public:
	void Edit(PolygonCanvas& canvas) override;
};
