#include "PolygonCanvas.h"

PolygonCanvas::PolygonCanvas() = default;

void PolygonCanvas::AddVertex(const Canvas::Vertex& vertex)
{
	vertices << vertex;
}

void PolygonCanvas::RemoveVertex(int const number)
{
	vertices.erase(vertices.begin() + number);
	UpdatePolygonByRemoveVertex(number);
}

void PolygonCanvas::ExchangeVertex(const int number, const Canvas::Vertex& vertex)
{
	vertices[number] = vertex;
}

const Array<Canvas::Vertex>& PolygonCanvas::GetVertices() const
{
	return vertices;
}

void PolygonCanvas::AddPolygon(const Canvas::Polygon& polygon)
{
	polygons << polygon;
}

void PolygonCanvas::RemovePolygon(const int number)
{
	polygons.erase(polygons.begin() + number);
}

const Array<Canvas::Polygon>& PolygonCanvas::GetPolygons() const
{
	return polygons;
}

void PolygonCanvas::UpdatePolygonByRemoveVertex(const int number)
{
	// 削除されたインデックスを含む Polygon を削除 
	polygons.remove_if([&number](const Canvas::Polygon& p)
		{
			return std::any_of(p.Index.begin(), p.Index.end(), [&number](int n) { return n == number; });
		});

	// インデックスを前に詰める
	polygons = polygons.map([&number](Canvas::Polygon p)
	{
		for (int& i : p.Index)
		{
			if (i > number) i--;
		}
		return p;
	});
}
