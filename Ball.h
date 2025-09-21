#pragma once
using namespace System::Drawing;

class Ball
{
private:
	float _x, _y;
	int _color;
	int _borderColor;
	int _size;
	int _frameWidth, _frameHeight;

public:
	void draw(Graphics^ graphics);
	void setPos(int x, int y);
	Ball(int frameWidth, int frameHeight);
	void setColor(int color, int borderColor);
	int getSize();
	void setSize(int size);
};

extern Ball* ball;