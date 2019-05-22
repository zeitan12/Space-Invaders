/****** punto.cpp ***********************************************/
/**
* @file punto.cpp
*
* @brief Prácticas de Programación. Práctica 5
*
* Implementación de los métodos de la clase Punto
*
* @version 1.0
* @author Raül Saavedra Morato
* @author Alexander Scholte
* @date 23-4-2016
**/
/***************************************************************/

#include <iostream>

#include "punto.h"
using namespace std;

/***************************************************************/
/**
* Constructor con valores de la clase Punto
*
* @param[in] a valor a asignar a x
* @param[in] b valor a asignar a y
*
* @return Punto
**/
/***************************************************************/
Punto::Punto(int a, int b)
:x(a),y(b)
{}

/***************************************************************/
/**
* Da un nuevo valor a la posicion 'x' del Punto
*
* @param[in] a valor a asignar a x
*
**/
/***************************************************************/
void Punto::SetX(int a)
{
    x = a;
    
    return;
}

/***************************************************************/
/**
* Da un nuevo valor a la posicion 'y' del Punto
*
* @param[in] b valor a asignar a y
*
**/
/***************************************************************/
void Punto::SetY(int b)
{
    y = b;
    
    return;
}

/***************************************************************/
/**
* Consulta de la posicion 'x' del Punto
*
* @return x posicion x del punto
**/
/***************************************************************/
int Punto::GetX()
{
    return x;
}

/***************************************************************/
/**
* Consulta de la posicion 'y' del Punto
*
* @return y posicion y del punto
**/
/***************************************************************/
int Punto::GetY()
{
    return y;
}

/***************************************************************/
/**
* Esta funcion sobrecarga el operador == para comparar 
* dos Puntos
*
* @return ok    true si es la misma posicion
                false si la posicion es distinta
**/
/***************************************************************/
bool operator == (Punto p1, Punto p2)
{
	bool ok = false;
	if(p1.x == p2.x && p1.y == p2.y) 
		ok = true;
		
	return ok;
}
