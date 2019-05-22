/****** alien.cpp *******************************************/
/**
* @file alien.cpp
*
* @brief Prácticas de Programación. Práctica 5
*
* Implementación de los métodos de la clase Alien
*
* @version 1.0
* @author Raül Saavedra Morato
* @author Alexander Scholte
* @date 30-4-2016
**/
/***************************************************************/

#include <iostream>

#include "alien.h"
#include "global.h"
using namespace std;

/***************************************************************/
/**
* Constructor con valores de la clase Alien
*
* @param[in] a Valor a asignar a la posicion x
* @param[in] b Valor a asignar a la posicion y
* @param[in] vel Velocidad de movimiento del alien
* @param[in] d Direccion del movimiento del alien
*
* @return Alien
**/
/***************************************************************/
Alien::Alien(int a, int b, int vel, int d)
:Elemento(a,b,vel),dir(d),c(ALIEN)
{}

/***************************************************************/
/**
* Consulta el caracter que representa el alien
*
* @return c Caracter que representa el alien
**/
/***************************************************************/
char Alien::GetS()
{
    return c;
}

/***************************************************************/
/**
* Mueve los aliens cambiando de direccion
*
* @return ok    true Si no se a completado la invacion
                false Si se ha completado la invavion
*
**/
/***************************************************************/
bool Alien::Mover()
{
    bool ok = true;
    
    if(GetY() >= TABLERO_Y - 1)
        ok = false;        
    else if (GetX() > 0 && GetX() < TABLERO_X - 1)
        SetX(GetX() + dir * GetV());
    else if ((GetX() == 0 && dir == DERECHA) || (GetX() == TABLERO_X - 1 && dir == IZQUIERDA))
        SetX(GetX() + dir * GetV());
    else if ((GetX() == 0 && dir == IZQUIERDA) || (GetX() == TABLERO_X - 1 && dir == DERECHA))
    {
        if(dir == IZQUIERDA)
            dir = DERECHA;
        else
            dir = IZQUIERDA;
         
        SetY(GetY() + 1);
    }    
        
    return ok;
}
