/****** elemento.h **********************************************/
/**
* @file elemento.h
*
* @brief Pr�cticas de Programaci�n. Pr�ctica 5
*
* Fichero de cabecera de la clase Elemento
*
* @version 1.0
* @author Enrique Bonet
* @date 14-06-2016
**/
/***************************************************************/

#ifndef __elemento_h
#define __elemento_h

#include "punto.h"

/**
 * @brief Clase para el manejo de Elemento
 *
 * Clase para manejar la informacion de un elemento.
 * Esta informacion esta compuesta por:
 *  - x
 *  - y
 *  - v
 */
class Elemento : public Punto
{
    public:
        // Constuctor con parametros
        Elemento(int, // Posici�n x del elemento
                 int, // Posici�n y del elemento
                 int); // Velocidad de movimiento del elemento

        // Consulta de la velocidad el elemento
        int GetV(void);
    private:
        int v; ///< Velocidad del elemento
};

#endif

