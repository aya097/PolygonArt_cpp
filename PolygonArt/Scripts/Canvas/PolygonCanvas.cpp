#include "PolygonCanvas.h"

PolygonCanvas::PolygonCanvas() = default;

void PolygonCanvas::AddVertex(const Canvas::Vertex& vertex)
{
	Vertices << vertex;
}

void PolygonCanvas::RemoveVertex(int const number)
{
	Vertices.erase(Vertices.begin() + number);
}

const Array<Canvas::Vertex>& PolygonCanvas::GetVertices() const
{
	return Vertices;
}
