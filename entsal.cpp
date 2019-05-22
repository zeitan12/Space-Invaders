/****** entsal.cpp ***********************************************/
/**
* @file entsal.cpp
*
* @brief Prácticas de Programación. Práctica 5
*
* Implementación de los métodos de la clase EntSal
*
* @version 1.0
* @author Enrique Bonet
* @date 14-06-2016
**/
/***************************************************************/

#include <iostream>
#include <conio.h>
#include <windows.h>

#include "entsal.h"

using namespace std;

/***************************************************************/
/**
* Constructor de la clase EntSal
*
* @return   No aplicable
**/
/***************************************************************/
EntSal::EntSal(void)
{
}

/***************************************************************/
/**
* Lee una tecla del teclado sin esperar y sin hacer eco en la
* pantalla
*
* @return   Carácter leído, \0 si no se lee un carácter
**/
/***************************************************************/
char EntSal::Teclado(void)
{
    char d;

    if (_kbhit()) // Si hay una tecla pulsada
    {
        d=_getch(); // Leemos la tecla

        flushTec(); // Vaciomos el buffer de teclado
    }
    else
        d = '\0';
    
    return d;
}

/***************************************************************/
/**
* Realiza una pausa hasta que se pulse una tecla
*
* @return   Ningún valor
**/
/***************************************************************/
void EntSal::Pausa(void)
{
    flushTec(); // Vaciamos el buffer de teclado
    _getch(); // Leemos una tecla
}

/***************************************************************/
/**
* Espera un timepo determinado.
*
* @param [in] t   Tiempo de espera, en milisegundos
*
* @return   Ningún valor
**/
/***************************************************************/
void EntSal::Espera(int t)
{
    Sleep(t); // Esperamos los milisegundos indicados
}

/***************************************************************/
/**
* Borra la pantalla
*
* @return   Ningún valor
**/
/***************************************************************/
void EntSal::ClrScr(void)
{
    system("cls"); // Borramos la pantalla
}

/***************************************************************/
/**
* Escribe un carácter en la pantalla en la posición indicada
*
* @param [in] x   Posición X en la pantalla
* @param [in] y   Posición Y en la pantalla
* @param [in] d   Carácter que se quiere escribir
*
* @return   Ningún valor
**/
/***************************************************************/
void EntSal::Escribir(int x, int y, char d)
{
    gotoXY(x,y); // Nos ponemos en la posición X,Y de la pantalla
    cout << d; // Escribimos el caracter
}

/***************************************************************/
/**
* Escribe un string en la pantalla en la posición indicada
*
* @param [in] x   Posición X en la pantalla
* @param [in] y   Posición Y en la pantalla
* @param [in] s   String que se quiere escribir
*
* @return   Ningún valor
**/
/***************************************************************/
void EntSal::Escribir(int x, int y, string s)
{
    gotoXY(x,y); // Nos ponemos en la posición X,Y de la pantalla
    cout << s; // Escribiemos el string
}

/***************************************************************/
/**
* Vacía el buffer de teclado
*
* @return   Ningún valor
**/
/***************************************************************/
void EntSal::flushTec(void)
{
    while (_kbhit()) // While hayan teclas en el buffer de teclado
        _getch(); // Leemos una tecla
}

/***************************************************************/
/**
* Coloca el cursor en una posición de la pantalla
*
* @param [in] x   Posición X en la pantalla
* @param [in] y   Posición Y en la pantalla
*
* @return   Ningún valor
**/
/***************************************************************/
void EntSal::gotoXY(int x, int y)
{
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE); // Cogemos el manejador de la pantalla
    COORD cursor;
    
    cursor.X = x; // Columna
    cursor.Y = y; //Fila
    SetConsoleCursorPosition(consola,cursor); // Ponemos el cursor de la pantalla en X,Y
}

