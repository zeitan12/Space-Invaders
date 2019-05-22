/****** disparo.cpp *******************************************/
/**
* @file disparo.cpp
*
* @brief Prácticas de Programación. Práctica 5
*
* Implementación de los métodos de la clase Disparo
*
* @version 1.0
* @author Raül Saavedra Morato
* @author Alexander Scholte
* @date 30-4-2016
**/
/***************************************************************/

#include <iostream>

#include "disparo.h"
#include "global.h"
using namespace std;

/***************************************************************/
/**
* Constructor con valores de la clase Disparo
*
* @param[in] a Valor a asignar a la posicion x
* @param[in] b Valor a asignar a la posicion y
*
* @return   Disparo
**/
/***************************************************************/
Disparo::Disparo(int a, int b)
:Elemento(a,b,1),activo(false),c(DISPARO)
{}

/***************************************************************/
/**
* Pone el disparo en activo
**/
/***************************************************************/
void Disparo::Activo()
{
    activo = true;
    
    return;
}

/***************************************************************/
/**
* Nos dice si el disparo esta o no activo
*
* @return activo 
**/
/***************************************************************/
bool Disparo::IsActivo()
{
    return activo;
}

/***************************************************************/
/**
* Consulta el caracter que representa el disparo
*
* @return c Caracter que representa el diparo
**/
/***************************************************************/
char Disparo::GetS()
{
    return c;
}

/***************************************************************/
/**
* Mueve el disparo
*
* @param[in, out] vector_aliens vector de aliens
*
**/
/***************************************************************/
void Disparo::Mover(vector<Alien> & vector_aliens)
{
    int i = 0;
    
    if (GetY() < 0)
        activo = false;
    
    while(i < vector_aliens.size() && activo)
    {
        if (*this == vector_aliens[i])
        {
            vector_aliens.erase(vector_aliens.begin()+i); 
            activo = false;  
        }
        else
            i++;
    }
    SetY(GetY() - GetV());
    
    return;
}

/***************************************************************/
/**
* Funcion que comprueba si un alien y un disparo estan en la 
* misma posicion
*
* @param[in] d Disparo
* @param[in] a Alien
*
* @return ok    true Si el alien y el disparo coinciden
                false Si el alien y el disparo no coinciden
                
**/
/***************************************************************/
bool operator == (Disparo d, Alien a)
{
    bool ok = false;
    
    if((Punto)d == (Punto)a)
        ok = true;    
    
    return ok;
}
