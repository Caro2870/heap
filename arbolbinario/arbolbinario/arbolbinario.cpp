// arbolbinario.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "arbolito.h"
#include <string>
#include <vector>



using namespace System;
using namespace std;

class Libro
{
	string nombre;
	int año;
	float score;
public:
	Libro(string nombre, int año, float score) : nombre(nombre), año(año), score(score) {}

	string getNombre() { return nombre; }
	int getaño() { return año; }
	float getscore() { return score; }

	void setNombre(string nombre) { this->nombre = nombre; }
	void setTamaño(int año) { this->año = año; }
	void setScore(float score) { this->score = score; }
};
int main()
{
	/*arbol<int>* arbolito = new arbol<int>();
	auto proc = [](int x) { cout << x << " ";};

	srand(time(0));
	for (int i = 0;i < 20;i++) {
		int randon = rand() % 100;
		proc(randon);
		arbolito->añadir(randon);
	}
	cout << endl;
	arbolito->preorden(proc); cout << endl;
	arbolito->postorden(proc); cout << endl;
	arbolito->enorden(proc); cout << endl;
	system("pause");
	return 0;*/


	typedef arbol<Libro*, string, nullptr> arbolStr;
	typedef arbol<Libro*, int, nullptr> arbolInt;
	typedef arbol<Libro*, float, nullptr> arbolFlt;
	vector<Libro*> libros;
	libros.push_back(new Libro("Moby Dick", 1851, 4.2));
	libros.push_back(new Libro("Kokito", 2019, 5));
	libros.push_back(new Libro("El Principito", 1943, 4.3));
	libros.push_back(new Libro("Sangre de campeón", 2001, 3));
	libros.push_back(new Libro("El rey palido", 2011, 4.0));
	libros.push_back(new Libro("Boveda de acero", 1954, 5));
	libros.push_back(new Libro("La ciudad y los perros", 1963, 4.5));

	auto l1 = [](Libro*a) {return a->getNombre();};
	auto l2 = [](Libro*a) {return a->getaño();};
	auto l3 = [](Libro*a) {return a->getscore();};



	arbolStr* nombrearbol = new arbolStr(l1);
	arbolInt* añoarbol = new arbolInt(l2);
	arbolFlt* scorearbol = new arbolFlt(l3);

	for (auto libro : libros) {

		nombrearbol->añadir(libro);
		añoarbol->añadir(libro);
		scorearbol->añadir(libro);
	}

	auto prnt = [](Libro* a) {
		cout << "{"
			<< a->getNombre() << ", "
			<< a->getaño() << ", "
			<< a->getscore() << "}\n";
	};

	nombrearbol->enorden(prnt); cout << "-----------------------------------==\n";
	añoarbol->enorden(prnt); cout << "-----------------------------------==\n";
	scorearbol->enorden(prnt); cout << "-----------------------------------==\n";
	prnt(nombrearbol->buscar("El rey palido"));
	prnt(añoarbol->buscar(2011));
	prnt(scorearbol->buscar(4.5));

	delete nombrearbol;
		delete añoarbol;
		delete scorearbol;

	system("pause");
	return 0;

}
