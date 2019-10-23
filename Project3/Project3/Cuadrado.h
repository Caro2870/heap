#pragma once
#include "Figuras.h"

class Cuadrado:public Figura
{
private:

	int lado;
	float r;

public:
	Cuadrado(int x, int y, int color) {
		this->x = x;
		this->y = y;
		this->color = color;
		this->r = 20;//para que la figura gire
		this->dx = 5;
		this->dy = 5;
		this->rotacion = 0;
		this->lado = 4;
	}
	~Cuadrado() {};
	void Dibujar(Graphics ^g, Color c) {
		//definir rotacion 
		double a = 0;
		//desplazamiento
		float desplazamiento = 360 / 4;
		//uso recolector de objectos 
		array<Point>^puntos = gcnew array <Point>(lado);
		int x1, x2;
		for (int i = 0; i < lado; i++)
		{
			a = (rotacion + desplazamiento*i)*Math::PI / 180;
		}
		SolidBrush^brush = gcnew SolidBrush(c);
		g->FillPolygon(brush, puntos);
	/*	Color c = ColorTranslator::FromWin32(color);*/
	}
	void Pintar(Graphics ^g) {
		Color c = ColorTranslator::FromWin32(color);
		//invocar dibujar
		Dibujar(g, c);
	}
	void Borra(Graphics^g) {
		Dibujar(g,Color::Black);
	}
};
