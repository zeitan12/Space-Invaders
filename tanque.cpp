/****** tanque.cpp *******************************************/
/**
* @file tanque.cpp
*
* @brief Prácticas de Programación. Práctica 5
*
* Implementación de los métodos de la clase Tanque
*
* @version 1.0
* @author Raül Saavedra Morato
* @author Alexander Scholte
* @date 30-4-2016
**/
/***************************************************************/

#include <iostream>

#include "tanque.h"
#include "global.h"
using namespace std;

/***************************************************************/
/**
* Constructor con valores de la clase Tanque
*
* @param[in] a Valor a asignar a la posicion x
* @param[in] b Valor a asignar a la posicion y
* @param[in] vel Velocidad de movimiento del alien
*
* @return Tanque
**/
/***************************************************************/
Tanque::Tanque(int a, int b, int vel)
:Elemento(a,b,vel),c(TANQUE)
{}

/***************************************************************/
/**
* Consulta el caracter que representa el tanque
*
* @return c Caracter que representa el tanque
**/
/***************************************************************/
char Tanque::GetS()
{
    return c;
}

/***************************************************************/
/**
* Mueve el tanque en direccion indicada por un entero
*
* @param[in] dir direccion indicada
*
**/
/***************************************************************/
void Tanque::Mover(int dir)
{
    if(GetX() > 0 && GetX() < TABLERO_X - 1)
        SetX(GetX() + dir * GetV());
    else if (GetX() == 0 && dir == DERECHA)
        SetX(GetX() + dir * GetV());
    else if (GetX() == TABLERO_X - 1 && dir == IZQUIERDA)
        SetX(GetX() + dir * GetV());
        
    return;
}
