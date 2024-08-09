#pragma once
#include "../../Canvas/PolygonCanvas.h"

class Editor
{
public:
	virtual void Edit(PolygonCanvas& canvas) = 0;
	virtual ~Editor() {}
};

class NoneEditor : public Editor
{
public:
	void Edit(PolygonCanvas& canvas) override {};
};
