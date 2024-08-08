#include "PolygonCanvas.h"

PolygonCanvas::PolygonCanvas() = default;

void PolygonCanvas::AddVertex(const Canvas::Vertex& vertex)
{
	Vertices << vertex;
}

void PolygonCanvas::RemoveVertex(int const number)
{
	Vertices.erase(Vertices.begin() + number);
	UpdatePolygonByRemoveVertex(number);
}

const Array<Canvas::Vertex>& PolygonCanvas::GetVertices() const
{
	return Vertices;
}

void PolygonCanvas::AddPolygon(const Canvas::Polygon& polygon)
{
	Polygons << polygon;
}

void PolygonCanvas::RemovePolygon(const int number)
{
	Polygons.erase(Polygons.begin() + number);
}

const Array<Canvas::Polygon>& PolygonCanvas::GetPolygons() const
{
	return Polygons;
}

void PolygonCanvas::UpdatePolygonByRemoveVertex(const int number)
{
	
	Polygons.remove_if([&number](const Canvas::Polygon& p)
		{
			return std::any_of(p.Index.begin(), p.Index.end(), [&number](int n) { return n == number; });
		});

	Polygons = Polygons.map([&number](Canvas::Polygon p)
	{
		for (int& i : p.Index)
		{
			if (i > number) i--;
		}
		return p;
	});
}
