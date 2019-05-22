/****** elemento.cpp *******************************************/
/**
* @file elemento.cpp
*
* @brief Pr�cticas de Programaci�n. Pr�ctica 5
*
* Implementaci�n de los m�todos de la clase Elemento
*
* @version 1.0
* @author Ra�l Saavedra Morato
* @author Alexander Scholte
* @date 30-4-2016
**/
/***************************************************************/

#include <iostream>

#include "elemento.h"
using namespace std;

/***************************************************************/
/**
* Constructor con valores de la clase Elemento
*
* @param[in] a valor a asignar a x
* @param[in] b valor a asignar a y
* @param[in] vel valor a asignar a v
*
* @return   Elemento
*
**/
/***************************************************************/
Elemento::Elemento(int a, int b, int vel)
:Punto(a,b),v(vel)
{}

/***************************************************************/
/**
* Consulta de la velcidad 'v' del elemento
*
* @return v velocidad v del elemento
*
**/
/***************************************************************/
int Elemento::GetV()
{
    return v;
}
