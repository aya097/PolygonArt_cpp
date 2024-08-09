#include "PolygonEditor.h"

void PolygonEditor::Edit(PolygonCanvas& canvas)
{

	// 頂点の選択
	{
		auto v = canvas.GetVertices();
		bool isSelected = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (Circle{ v[i].Pos,radius }.leftClicked())
			{
				if(not selectedVertexIndices.contains(i))
					selectedVertexIndices << i;
				isSelected = true;
				Print << selectedVertexIndices;
				break;
			}
		}
		// 頂点以外を押していたら選択解除
		if (not isSelected && MouseL.down())
		{
			selectedVertexIndices.clear();
		}
	}
	// 選択解除
	{
		auto v = canvas.GetVertices();
		for (int i = 0; i < v.size(); i++)
		{
			if (Circle{ v[i].Pos,radius }.rightClicked())
			{
				selectedVertexIndices.remove_if([i](int n) { return n == i; });
				break;
			}
		}
	}
	// Polygon 生成
	{
		auto v = canvas.GetVertices();
		if (selectedVertexIndices.size() >= 3)
		{
			// todo : 色指定
			Triangle tri{ v[selectedVertexIndices[0]].Pos
			,v[selectedVertexIndices[1]].Pos
			,v[selectedVertexIndices[2]].Pos
			};
			// 生成される三角形の中に他の頂点があれば生成しない
			if (std::none_of(v.begin(), v.end(), [&tri](Canvas::Vertex v)
				{
					return tri.contains(v.Pos);
				}))
			{
				canvas.AddPolygon(Canvas::Polygon{
					{selectedVertexIndices[0],selectedVertexIndices[1],selectedVertexIndices[2]}, Palette::Red });
			}
			selectedVertexIndices.clear();
		}
	}
}
