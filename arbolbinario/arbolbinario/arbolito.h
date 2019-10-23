#pragma once
#include <functional>
using namespace std;
template <typename T, typename comparable = T,T NADA=0>

class arbol
{
	struct Nodo {
		T elem;
		Nodo* izquierdo;
		Nodo* derecha;
		Nodo(T elem) : elem(elem), izquierdo(nullptr), derecha(nullptr) {}

		
};
	

	Nodo* raiz;
	int tamaño;
	function<comparable(T)> llave;

	void destruir(Nodo* nodito) {
		if (nodito != nullptr) {
			destruir(nodito->izquierdo);
			destruir(nodito->derecha);
			delete nodito;
		}
	}
	Nodo* añadir(Nodo* nodito, T elem) {
		if (nodito == nullptr) {
			nodito = new Nodo(elem);
		}
		else if(llave(elem)<llave(nodito->elem))
		{
			nodito->izquierdo = añadir(nodito->izquierdo, elem);
		}
 else {
	 nodito->derecha = añadir(nodito->derecha, elem);
 }
 return nodito;
	}

	T find(Nodo* nodito, comparable val) {
		if (nodito == nullptr) {
			return NADA;
		}
		else if (val == llave(nodito->elem)) {
			return nodito->elem;
		}
		else if (val == llave(nodito->elem)) {
			return find(nodito->izquierdo, val);
		}
		else {
			return find(nodito->derecha, val);
		}
	}

	void preorden(Nodo* nodito, function<void(T)>proc) {
		if (nodito != nullptr) {
			proc(nodito->elem);
			preorden(nodito->izquierdo,proc);
			preorden(nodito->derecha,proc);

		}
	}
	void postorden(Nodo* nodito, function<void(T)>proc) {
		if (nodito != nullptr) {
			postorden(nodito->izquierdo, proc);
			postorden(nodito->derecha, proc);
			proc(nodito->elem);

		}
	}
	void enorden(Nodo* nodito, function<void(T)>proc) {
				if (nodito != nullptr) {
					enorden(nodito->izquierdo,proc);
					proc(nodito->elem);
					enorden(nodito->derecha,proc);

				}

	}
public:
	arbol (function<comparable(T)> llave = [](T a) {return a;})
	:raiz(nullptr),tamaño(0),llave(llave){}
	~arbol() {
		destruir(raiz);
	}

	int tamaños() {
		return tamaño;
	}
	void añadir(T elem) {
		raiz = añadir(raiz, elem);
	}

	T buscar(comparable val) {
		return buscar(raiz, val);
	}

	void preorden(function<void(T)>proc) {
		preorden(raiz, proc);
	}
	void postorden(function<void(T)>proc) {
		postorden(raiz, proc);
	}
	void enorden(function<void(T)>proc) {
		enorden(raiz, proc);
	}

};
