#include "FileReader.h"

void FileReader::Read(PolygonCanvas& canvas)
{
	Optional<FilePath> path = Dialog::OpenFile({ FileFilter::CSV() });
	if (not path) return;
	CSV csv{ *path };


	// canvasの消去
	while (0 < canvas.GetVertices().size())
	{
		canvas.RemoveVertex(0);
	}

	int row = 0;
	// vertex を探索
	for (; row < csv.rows(); row++)
	{
		if (csv[row][0] == U"vertex")
		{
			row++;
			break;
		}
	}
	// vertex を読み込み
	for (; row < csv.rows(); row++)
	{
		if (csv[row][0] == U"polygon")
		{
			row++;
			break;
		}
		canvas.AddVertex(Canvas::Vertex{ Parse<Point>(csv[row][0]) });
	}
	// polygon を読み込み
	for (; row < csv.rows(); row++)
	{
		Array a = csv[row][0].split(U',').map(Parse<int>);
		row++;
		canvas.AddPolygon(Canvas::Polygon{ {a[0],a[1],a[2]},Parse<Color>(csv[row][0]) });
	}

}
