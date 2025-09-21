#include "Ball.h"

using namespace System;
using namespace System::Drawing;

Ball* ball;

void Ball::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(_color));
	Pen pen(Color::FromArgb(_borderColor), 4);
	graphics->FillEllipse(% brush, (int)(_x - _size / 2), (int)(_y - _size / 2), _size, _size);
	graphics->DrawEllipse(% pen, (int)(_x - _size / 2), (int)(_y - _size / 2), _size, _size);
}

void Ball::setPos(int x, int y) {
	if (_size / 2 > x) x = _size / 2;
	if (x > _frameWidth - _size / 2) x = _frameWidth - _size / 2;
	if (_size / 2 > y) y = _size / 2;
	if (y > _frameHeight - _size / 2) y = _frameHeight - _size / 2;

	_x = x;
	_y = y;
}

Ball::Ball(int frameWidth, int frameHeight) {
	_x = frameWidth / 2;
	_y = frameHeight / 2;
	_size = 40;
	_color = Color::FromArgb(0, 255, 0).ToArgb();
	_borderColor = Color::FromArgb(255, 0, 0).ToArgb();
	_frameWidth = frameWidth;
	_frameHeight = frameHeight;
}

void Ball::setColor(int color, int borderColor) {
	_color = color;
	_borderColor = borderColor;
}

int Ball::getSize() {
	return _size;
}

void Ball::setSize(int size) {
	_size = size;
	setPos(_x, _y);
}