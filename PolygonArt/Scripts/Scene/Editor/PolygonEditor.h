#pragma once
#include "Editor.h"

class PolygonEditor : public Editor
{
public:
	void Edit(PolygonCanvas& canvas) override;
private:
	// 選択されている頂点リスト
	Array<int> selectedVertexIndices;
	int radius = 10;
};
