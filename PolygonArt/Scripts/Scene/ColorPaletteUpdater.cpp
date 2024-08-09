#include "ColorPaletteUpdater.h"

void ColorPaletteUpdater::Update()
{
	// RGB スライダー
	{
		Vec2 leftop = Vec2{ 1530,800 };
		int labelWidth = 100;
		int sliderWidth = 200;
		Vec2 distance = Vec2{ 0,35 };
		ColorF c = color;
		SimpleGUI::Slider(U"R : {}"_fmt(color.r), c.r, 0.0, 1.0, leftop, labelWidth, sliderWidth);
		SimpleGUI::Slider(U"G : {}"_fmt(color.g), c.g, 0.0, 1.0, leftop + distance, labelWidth, sliderWidth);
		SimpleGUI::Slider(U"B : {}"_fmt(color.b), c.b, 0.0, 1.0, leftop + distance * 2, labelWidth, sliderWidth);
		SimpleGUI::Slider(U"A : {}"_fmt(color.a), c.a, 0.0, 1.0, leftop + distance * 3, labelWidth, sliderWidth);
		color = c;
	}
	// 色サンプル
	{
		int radius = 150;
		Vec2 center = Vec2{ 1680 ,630 };
		Circle{ center,radius }.draw(color);
	}
}

const Color& ColorPaletteUpdater::GetColor()
{
	return color;
}
