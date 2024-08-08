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
	PolygonCanvas();
	void AddVertex(const Canvas::Vertex& vertex);
	void RemoveVertex(int const number);
	const Array<Canvas::Vertex>& GetVertices() const;
private:
	Array<Canvas::Vertex> Vertices;
	Array<Canvas::Polygon> Polygons;
};
