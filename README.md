
<img src="./img/cplus.png" width="20%" style="float:right">

# Práctica 1 Calculadora de expresiones en notación postfija

## Repositorio AYEDDA-practica2

El objetivo de esta práctica es trabajar la definición de clases, la implementación de operaciones
mediante métodos, uso de funciones amigas y la sobrecarga de operadores. También se introduce las
plantillas para definir clases genéricas.

* author  Carlos Troyano Carmona
* version 1.1
* since   2016-03-08


### Calculadora
Calculadora es una practica de la asignatura:
Algoritmo y estructuras de datos avanzados
Calculadora es una clase que sirve para calcular operaciones en notación posfija. Para ello utiliza la entrada IStream para leer desde un fichero los operandos y los operadores.

A través de una pila del tipo de dato necesario calculara la solución.

La calculadora está preparada para funcionar con al clase Numero. y todas sus clases derivadas.

Implementa las operaciones de:
  1.  Suma
  2.  Diferencia
  3.  Producto
  4.  División

* [Cabeceras  documentadas]()

### Numero
Numero es una practica de la asignatura:
Algoritmo y estructuras de datos avanzados
Numero es una clase que representa a los números complejos, y todos los conjuntos que estos abarcan. Esta clase se utiliza para implementar las operaciones entre estos tipos de números.

* [Cabeceras  documentadas]()

### Entero
Entero es una practica de la asignatura:
Algoritmo y estructuras de datos avanzados
Entero es una clase que representa a los números enteros. Es hija de la clase número.

* [Cabeceras  documentadas]()

### Real
Real es una practica de la asignatura:
Algoritmo y estructuras de datos avanzados
Real es una clase que representa a los números reales. Es hija de la clase número.

* [Cabeceras  documentadas]()

### Complejo
Complejo es una practica de la asignatura:
Algoritmo y estructuras de datos avanzados
Complejo es una clase que representa a los números Complejos. Es hija de la clase número.

* [Cabeceras  documentadas]()

### nodo
nodo es una clase para una practica de la asignatura:
Algoritmo y estructuras de datos avanzados
Nodo sirve para almacenar datos de contenedores contiene un puntero al siguiente y al anterior nodo que debe estar en un contenedor, también contiene un dato del tipo tipoDato.

* [Cabeceras  documentadas]()

### Pila
Pila es una clase que sirve para almacenar datos, del tipo predefinido tipoDato a través de nodos,
definidos en este mismo proyecto. El almacenamiento se realiza con el algoritmo LIFO. A través de un puntero
a la cima de la pila. Se implementa también un puntero a la base de la pila para poder invertir la pila.<br/>
También se almacena un natural que contiene el número de elementos en la pila.
* [Cabeceras  documentadas]()
