#include "PolygonCanvas.h"

void PolygonCanvas::AddVertex(Canvas::Vertex& const vertex)
{
	Vertices << vertex;
}

void PolygonCanvas::RemoveVertex(int const number)
{
	Vertices.erase(Vertices.begin() + number);
}
