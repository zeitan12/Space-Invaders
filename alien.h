/****** alien.h *************************************************/
/**
* @file alien.h
*
* @brief Prácticas de Programación. Práctica 5
*
* Fichero de cabecera de la clase Alien
*
* @version 1.0
* @author Enrique Bonet
* @date 14-06-2016
**/
/***************************************************************/
#ifndef __alien_h
#define __alien_h

#include "elemento.h"

const int ALIEN = 'X'; ///< Carácter que representa al alien

/**
 * @brief Clase para el manejo de Alien
 *
 * Clase para manejar la informacion de un alien.
 * Esta informacion esta compuesta por:
 *  - x
 *  - y
 *  - v
 *  - c
 *  - dir
 */
class Alien : public Elemento
{
    public:
        // Constructor con parametros
        Alien(int, // Posicion x del alien
              int, // Posicion y del alien
              int, // Velocidad del alien
              int); // Direccion inicial de movimiento del alien

        // Consulta del caracter que representa al alien
        char GetS(); // Devuelve el caracter que representa el tanque

        // Metodo que mueve el alien. Devuelve false si se ha completado la invacion
        bool Mover(void);
    private:
        char c; ///< Caracter que representa al alien
        int dir; ///< Direccion del movimiento del alien (IZQUIERDA o DERECHA)
};

#endif

