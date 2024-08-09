#pragma once
#include<Siv3D.hpp>

namespace Canvas
{
	struct Vertex
	{
		Point Pos;
		bool IsSelected = false;
	};

	struct Polygon
	{
		std::array<int ,3> Index;
		Color Color;
		bool IsSelected = false;
	};
}

struct DrawVertexOptions
{
	Color DefaultColor;
	Color SelectedCplor;
	int Radius;
};

struct DrawPolygonOptions
{
	Color SlectedEdgeColor;
};

class PolygonCanvas
{
public:
	PolygonCanvas() = default;
	// Vertex の処理 
	void AddVertex(const Canvas::Vertex& vertex);
	void RemoveVertex(const int number);
	void ExchangeVertex(const int number, const Canvas::Vertex& vertex);
	const Array<Canvas::Vertex>& GetVertices() const;

	// Polygon の処理
	void AddPolygon(const Canvas::Polygon& polygon);
	void RemovePolygon(const int number);
	const Array<Canvas::Polygon>& GetPolygons() const;

	void FillIsSelected(bool isSelected);
	
private:
	// Vertex が削除さえれたときの Polyognの処理
	void UpdatePolygonByRemoveVertex(const int number);

	Array<Canvas::Vertex> vertices;
	Array<Canvas::Polygon> polygons;
};
