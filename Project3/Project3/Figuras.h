#pragma once

using namespace System;
using namespace System::Drawing;

class Figura
{
public:
	Figura() {};
	~Figura();
	virtual void mover(Graphics ^g) {
		float x_max, y_max;
		//tamaño del formulario
		x_max = g->VisibleClipBounds.Right;
		x_max = g->VisibleClipBounds.Bottom;
		//si pasa el limite
		if (x + dx > x_max || x + dx < 0) {
			dx = dx*-1;	
		}
		if (y + dy > y_max || y + dy < 0) {
			dy = dy*-1;
		}
		x = x + dx; y = y + dy;
		// 
		rotacion = rotacion + 3;
		if (rotacion == 360)
			rotacion = 0;
	}
	virtual void pintar(Graphics^g) = 0;
	virtual void borrar(Graphics^g) = 0;

protected:
	int x, y, dx, dy, color, rotacion;
};

Figura::Figura()
{
}

Figura::~Figura()
{
}