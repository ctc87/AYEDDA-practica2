/**
 * <h1>Nodo</h1>
 * nodo es una clase para una practica de la asignatura: <br/>
 * <em>Algoritmo y estructuras de datos avanzados</em> <br/>
 * Nodo sirve para almacenar datos de contenedores contiene
 * un puntero al siguiente y al anterior nodo que debe estar
 * en un contenedor, también contiene un dato del tipo
 * tipoDato.
 *
 * @author  Carlos Troyano Carmona
 * @version 1.1
 * @since   2015-02-15
 * @see tipoDato
*/
#pragma once
#include <cstdio>

template <class tipoDato>
class nodo {
	private:
/**
 *  Puntero al nodo anterior.
*/
		nodo* prev;

/**
 *  Puntero al nodo siguiente.
*/

		nodo* next;
/*
 * Dato del tipo tipoDato
 * @see tipoDato
*/
		tipoDato dato;

	public:
/**
 * Constructor por defecto para nodo. Inicializa los puntero
 * a NULL.
*/
		nodo();

/**
 * Constructor con dato para nodo. Inicializa los punteros
 * a NULL y el dato con idato que es el dato pasado por
 * parámetro.
 * @param idato Dato que se va almacenar en el nodo.
*/
		nodo(tipoDato idato);

/**
 * @return next Retorna el el puntero al siguiente nodo.
*/
		nodo<tipoDato>* getNext();

/**
 * @return prev Retorna el el puntero al anterior nodo.
*/
		nodo<tipoDato>* getPrev();

/**
 * @param t Establece el puntero al siguiente nodo.
*/
		void setNext(nodo<tipoDato>* t);

/**
 * @param t Establece el puntero al anterior nodo.
*/
		void setPrev(nodo<tipoDato>* t);

/*
 * @return dato Retorna el dato guardado en el nodo.
*/
		tipoDato getDato();

/*
 * @param d Establece el dato guardado en el nodo.
*/
		void setDato(tipoDato d);

/*
 * Destructor de la clase. No contiene código.
*/
		~nodo();
};

template <class tipoDato>
nodo<tipoDato>::nodo():
    next(NULL),
    prev(NULL),
    dato()
    {}

template <class tipoDato>
nodo<tipoDato>::nodo(tipoDato idato):
    next(NULL),
    prev(NULL),
    dato(idato)
    {}

template <class tipoDato>
nodo<tipoDato>* nodo<tipoDato>::getNext(){
	return(next);
}

template <class tipoDato>
nodo<tipoDato>* nodo<tipoDato>::getPrev(){
	return(prev);
}

template <class tipoDato>
void nodo<tipoDato>::setNext(nodo* t){
	next=t;
}

template <class tipoDato>
void nodo<tipoDato>::setPrev(nodo* t){
	prev=t;
}

template <class tipoDato>
tipoDato nodo<tipoDato>::getDato(){
	return(dato);
}

template <class tipoDato>
void nodo<tipoDato>::setDato(tipoDato d){
	this->dato=d;
}

template <class tipoDato>
nodo<tipoDato>::~nodo(){}



