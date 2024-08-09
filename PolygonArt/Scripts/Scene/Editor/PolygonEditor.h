#pragma once
#include "Editor.h"

class PolygonEditor : public Editor
{
public:
	void Edit(PolygonCanvas& canvas) override;
private:
	bool EditVertex(PolygonCanvas& canvas);
	bool EditPolygon(PolygonCanvas& canvas);
	void UpdateStatus(PolygonCanvas& canvas);

	// 選択されている頂点リスト
	Array<int> selectedVertexIndices;
	// 選択されているポリゴン
	int selectedPolyognIndex = -1;
};
