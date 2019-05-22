/****** punto.h *************************************************/
/**
* @file punto.h
*
* @brief Prácticas de Programación. Práctica 5
*
* Fichero de cabecera de la clase Punto
*
* @version 1.0
* @author Enrique Bonet
* @date 14-06-2016
**/
/***************************************************************/
#ifndef __punto_h
#define __punto_h

/**
 * @brief Clase para el manejo de Punto
 *
 * Clase para manejar la informacion de un punto.
 * Esta informacion esta compuesta por:
 *  - x
 *  - y
 */
class Punto
{
    public:
        // Constructor con parametros
        Punto(int, // Valor x del elemento
              int); // Valor y del elemento

        // Da un nuevo valor a la posicion 'x' del punto
        void SetX(int);

        // Da un nuevo valor a la posicion 'y' del punto
        void SetY(int);

        // Consulta de la posicion 'x' del punto
        int GetX(void);

        // Consulta de la posicion 'y' del punto
        int GetY(void);

        // Sobrecarga del operador comparacion para poder comparar puntos
        friend bool operator == (Punto,Punto);
    private:
        int x; ///< Valor x del elemento
        int y; ///< Valor y del elemento
};

#endif

