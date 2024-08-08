#pragma once
#include<Siv3D.hpp>

namespace Canvas
{
	struct Vertex
	{
		Point Pos;
	};

	struct Polygon
	{
		int Index[3];
		Color Color;
	};
}
class PolygonCanvas
{
public:
	void AddVertex(Canvas::Vertex& const vertex);
	void RemoveVertex(int const number);
private:
	Array<Canvas::Vertex> Vertices;
	Array<Canvas::Polygon> Polygons;
};
