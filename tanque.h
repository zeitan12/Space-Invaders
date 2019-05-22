/****** tanque.h *************************************************/
/**
* @file tanque.h
*
* @brief Prácticas de Programación. Práctica 5
*
* Fichero de cabecera de la clase Tanque
*
* @version 1.0
* @author Enrique Bonet
* @date 14-06-2016
**/
/***************************************************************/

#ifndef __tanque_h
#define __tanque_h

#include "elemento.h"

const char TANQUE = 'A'; ///< Carácter que representa al tanque

/**
 * @brief Clase para el manejo de Tanque
 *
 * Clase para manejar la informacion de un tanque.
 * Esta informacion esta compuesta por:
 *  - x
 *  - y
 *  - v
 *  - c
 */
class Tanque : public Elemento
{
    public:
        // Constructor con parámetros
        Tanque(int, // Posicion x del tanque
               int, // Posicion y del tanque
               int); // Velocidad del tanque

        // Consulta el carácter que representa al tanque
        char GetS(void);

        // Metodo que mueve el tanque en dirección indicada por el entero
        void Mover(int);
    private:
        char c; ///< Caracter que representa al tanque
};

#endif

