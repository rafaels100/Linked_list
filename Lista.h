#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

typedef unsigned long Nat;

class Lista{
public:
	//default constructor
	Lista();
	//constructor por copia de la lista
	Lista(const Lista& l);
	//destructor
	~Lista();

	//operador asignacion
	Lista& operator=(const Lista& aCopiar);
	//mutadores
	//agregar adelante
	//Agrega al final de los nodos, si estos estuvieran
	//ordenados como una lista con indices (I know, poco intuitivo)
	void agregarAtras(int x);
	//agregar adelante
	//agrega al frente de la lista, es decir, el que agregue
	//sera el nuevo prim
	void agregarAdelante(int x);
	//eliminar iesimo: where boys come to die and men are born
	void eliminar(int i);

	//otros metodos
	void mostrar(ostream& o);
	//obtener valor del iesimo nodo
	const int& iesimo(Nat i) const;
	//obtener valor del iesimo nodo, modificable
	int& iesimo(Nat i);
	//obtener la longitud de la lista
	int longitud() const;

	friend ostream& operator<<(ostream& os, Lista& l){
		l.mostrar(os);
		return os;
	}
	
private:
	int longitud_;
	struct Nodo{
		int valor;
		Nodo* sig;
		Nodo* ant;
		Nodo(int v, Nodo* a, Nodo* s) : valor(v), ant(a), sig(s) {}
	};
	Nodo* prim;

	void destruirNodos();
	void copiarNodos(const Lista &o);
};
#endif