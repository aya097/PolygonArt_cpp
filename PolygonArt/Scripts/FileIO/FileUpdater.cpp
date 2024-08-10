#include "FileUpdater.h"

void FileUpdater::Update(PolygonCanvas& canvas)
{
	Vec2 leftop = Vec2{ 1530,950 };
	int width = 300;
	Vec2 distance = Vec2{ 0,40 };
	if (SimpleGUI::Button(U"読み込み", leftop, width))
	{

	}
	if (SimpleGUI::Button(U"保存", leftop + distance, width))
	{
		fileWriter.Write(canvas);
	}
}
