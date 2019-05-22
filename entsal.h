/****** entsal.h ************************************************/
/**
* @file entsal.h
*
* @brief Prácticas de Programación. Práctica 5
*
* Fichero de cabecera de la clase EntSal
*
* @version 1.0
* @author Enrique Bonet
* @date 14-06-2016
**/
/***************************************************************/

#ifndef __entsal_h
#define __entsal_h

#include <string>

using namespace std;

/**
 * @brief Clase para la entrada y salida
 *
 * Clase para la entrada y la salida
 */
class EntSal{
    public:
        EntSal(void); // Constructor de la clase
        char Teclado(void); // Devuelve una tecla sin esperar
        void Pausa(void); // Espera hasta que se pulse una tecla
        void Espera(int); // Espera los milisegundos indicados
        void ClrScr(void); // Limpia la pantalla
        void Escribir(int, // Posicion X
                      int, // Posicion Y
                      char); // Caracter a escribir
        void Escribir(int, // Posicion X
                      int, // Posicion Y
                      string s); // Cadena a escribir
    private:
        void flushTec(void); // Vacia el buffer de teclado
        void gotoXY(int,int); // Coloca el cursor en las coordenadas X,Y
};

#endif

