#include "FileWriter.h"

void FileWriter::Write(const PolygonCanvas& canvas)
{
	// 保存するフォルダのパス
	path = Dialog::SelectFolder();
	if (path == none) return;

	CSV csv{};
	// Vertex の保存
	auto vertex = canvas.GetVertices();
	csv.writeRow(U"vertex");
	for (auto v : vertex)
	{
		csv.writeRow(U"{}"_fmt(v.Pos));
	}

	// Polygon の保存
	auto polygon = canvas.GetPolygons();
	csv.writeRow(U"polygon");
	for (auto p : polygon)
	{
		csv.writeRow(U"{}:{}"_fmt(p.Index,p.Color));
	}

	csv.save(FileSystem::PathAppend(*path, U"{}.csv"_fmt(Time::GetSecSinceEpoch())));
}
