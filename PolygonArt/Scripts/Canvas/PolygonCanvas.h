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
	Color SelectedColor;
	int Radius;
	int Thinkness;
};

struct DrawPolygonOptions
{
	Color SlectedEdgeColor;
	int Thinckness;
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
	void ExchangePolygon(const int number, const Canvas::Polygon& polygon);
	const Array<Canvas::Polygon>& GetPolygons() const;

	void FillIsSelected(bool isSelected);


	const DrawVertexOptions VertexOptions{ Palette::Green,Palette::Red,10,10 };
	const DrawPolygonOptions PolygonOptions{ Palette::Aqua , 10};

private:
	// Vertex が削除さえれたときの Polyognの処理
	void UpdatePolygonByRemoveVertex(const int number);

	Array<Canvas::Vertex> vertices;
	Array<Canvas::Polygon> polygons;
};
