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
		std::array<int ,3> Index;
		Color Color;
	};
}
class PolygonCanvas
{
public:
	PolygonCanvas();
	// Vertex の処理 
	void AddVertex(const Canvas::Vertex& vertex);
	void RemoveVertex(int const number);
	const Array<Canvas::Vertex>& GetVertices() const;

	// Polygon の処理
	void AddPolygon(const Canvas::Polygon& polygon);
	void RemovePolygon(const int number);
	const Array<Canvas::Polygon>& GetPolygons() const;
	
private:
	// Vertex が削除さえれたときの Polyognの処理
	void UpdatePolygonByRemoveVertex(const int number);

	Array<Canvas::Vertex> Vertices;
	Array<Canvas::Polygon> Polygons;
};
