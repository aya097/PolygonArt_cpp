#include "FileWriter.h"

void FileWriter::Write(const PolygonCanvas& canvas)
{
	// 保存するフォルダのパス
	path = Dialog::SelectFolder();
	if (path == none) return;

	

	CSV csv{};
	auto vertex = canvas.GetVertices();
	csv.writeRow(U"vertex");
	for (auto v : vertex)
	{
		csv.writeRow(U"{}"_fmt(v.Pos));
	}

	csv.save(FileSystem::PathAppend(*path, U"{}.csv"_fmt(Time::GetSecSinceEpoch())));
}
