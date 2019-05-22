/****** p5.cpp *************************************************/
/**
* @file p5.cpp
*
* @brief Prácticas de Programación. Práctica 5
*
* Ejecuta un videojuego ASCII
*
* @version 1.0
* @author Enrique Bonet
* @date 14-06-2016
**/
/***************************************************************/

#include <vector>

#include "global.h"
#include "alien.h"
#include "tanque.h"
#include "disparo.h"
#include "entsal.h"

const unsigned char ESC = '\x1B'; ///< Valor de la tecla Escape

const int FILAS_ALIENS = 4;       ///< Número de filas de aliens que atacan
const int COLUMNAS_ALIENS = 10;   ///< Número de alines en cada fila

const int TIEMPO_ESPERA = 100;    ///< Tiempo de espera entre cada movimiento
/*
 * Prototipos de las funciones
 */
 
void CrearAliens(vector<Alien> &);
void DibujarPantallaDeJuego(EntSal, vector<Alien>, Tanque, Disparo);
bool MoverAliens(vector<Alien> &);
bool AtenderUsuario(EntSal, Tanque &, Disparo &);
void MensajeInicio(EntSal);
void MensajeFin(EntSal, bool);

/***************************************************************/
/**
* Programa principal
**/
/***************************************************************/
int main(void)
{
    vector<Alien> aliens;                          // Vector con los aliens del juego
    Tanque tanque(TABLERO_X / 2, TABLERO_Y -1, 1); // Tanque del juego
    Disparo disparo(TABLERO_X / 2, TABLERO_Y -2);  // Disparo del juego
    EntSal io;                                     // Objeto para manejar los métodos de I/O del juego.
    int bucle;                                     // Variable que controla si seguimos jugando o no.
 
    // Creamos los aliens
    CrearAliens(aliens);
    
    // Mostramos el mensaje de inicio
    MensajeInicio(io);

    /*
     * EMPEZAMOS EL JUEGO
     */
    bucle = true;
    /*
     * La variable 'bucle' se mantendrá activa mientras no nos maten o
     * no decidamos salir del juego.
     * También nos mantendremos en el juego mientras queden aliens en el vector.
     */
    while (bucle && !aliens.empty()) // Mientras no nos maten y hayan aliens
    {
        /*
         * Dibujamos el estado actual de todos los elementos del juego
         */
        DibujarPantallaDeJuego(io, aliens, tanque, disparo);
    
        /*
         * Hacemos una pausa en el programa para que se vea y los invaders no vayan
         * demasiado deprisa :-)
         */
        io.Espera(TIEMPO_ESPERA);
       
        /*
         * Movemos los aliens de forma automática
         * Si alguno ha llegado al final, el juego ha terminado y hemos perdido
         */
        bucle = MoverAliens(aliens);
        
        /*
         * Movemos el disparo de foram automática si hay disparo
         * Si el disparo encuentra un alien, mata al alien y se desactiva
         */
        if (disparo.IsActivo())
            disparo.Mover(aliens);
            
        /*
         * Atendemos las acciones del jugador leyendo el teclado y movemos el tanque
         * o disparamos o decidimos salir
         */
        bucle = bucle && AtenderUsuario(io, tanque, disparo);
    }

    /*
     * Mostramos el mensaje final dependiendo del motivo por el que hemos salido
     * del bucle
     */
    MensajeFin(io,bucle);
    
    return 0;
}

/***************************************************************/
/**
* Crea los aliens del juego
*
* @param [in] aliens   Elemento de la TLS que contendrá el vector de aliens
**/
/***************************************************************/
void CrearAliens(vector<Alien> & aliens)
{
    // Reservamos FILAS_ALIENS * COLUMNAS_ALIENS en el vector que contendrá los aliens
    aliens.reserve(FILAS_ALIENS*COLUMNAS_ALIENS);

    // Para todas las filas de aliens
    for(int i = 0; i < FILAS_ALIENS; i++)
        // Para todas las columnas de aliens
        for(int j = 0; j < COLUMNAS_ALIENS; j++)
            /*
            * Añadimos cada uno de los aliens al vector
            * Creamos cada alien en una posición determinada en función
            * de la fila y la columna
            */
            aliens.push_back(Alien(3 * j, 2 * i, 1, DERECHA));

    return;
}

/***************************************************************/
/**
* Refresca los elementos de la pantalla redibujando toda la pantalla
*
* @param [in] io   Clase que contiene los metodos de I/O
* @param [in] aliens   Vector con los aliens a dibujar
* @param [in] tanque   Tanque a dibujar
* @param [in] disparo   Disparo a dibujar
**/
/***************************************************************/
void DibujarPantallaDeJuego(EntSal io, vector<Alien> aliens, Tanque tanque, Disparo disparo)
{
    // Borramos la pantalla
    io.ClrScr();

    // Dibujamos los aliens
    for(unsigned i = 0; i < aliens.size(); i++)
        io.Escribir(aliens[i].GetX(),aliens[i].GetY(),aliens[i].GetS());

    // Dibujamos el tanque
    io.Escribir(tanque.GetX(),tanque.GetY(),tanque.GetS());
    
    // Dibujamos el disparo si esta activo
    if (disparo.IsActivo())
        io.Escribir(disparo.GetX(),disparo.GetY(),disparo.GetS());
        
    return;
}

/***************************************************************/
/**
* Mueve los aliens
*
* @param [in] aliens   Vector con los aliens a mover
*
* @return   Valor booleano que indica si no nos han invadido los aliens
*           y el juego debe continuar (true) o no (false)
**/
/***************************************************************/
bool MoverAliens(vector<Alien> & aliens)
{
    bool mover = true;
    unsigned i = 0;

    /*
     * Si algún alien no puede moverse es que ha llegado
     * al final de la pantalla y nos han invadido
    */
    while (i < aliens.size() && mover)
    {
        mover = aliens[i].Mover();
        i++;
    }

    return mover;    
}

/***************************************************************/
/**
* Atiende las ordenes del usuario leyendo el teclado y ejecutando
* las acciones solicitadas
*
* @param [in] io   Clase que contiene los metodos de I/O
* @param [in] tanque   Tanque que mueve el usuario
* @param [in] disparo   Disparo del usuario
*
* @return   Valor booleano que indica si debemos continuar en el
*           juego (true) o no (false)
**/
/***************************************************************/
bool AtenderUsuario(EntSal io, Tanque & tanque, Disparo & disparo)
{
    bool seguir = true;

    switch(io.Teclado()) // Atendemos las acciones del jugador leyendo el teclado
    {
        // Tecla Escape, 'q' o 'Q' para salir
        case '\x1B':
        case 'q':
        case 'Q':
            seguir = false;
            break;
        // 'a' o 'A' para mover el tanque hacia la IZQUIERDA
        case 'a':
        case 'A':
            tanque.Mover(IZQUIERDA);
            break;
        // 's' o 'S' para mover el tanque hacia la DERECHA
        case 's':
        case 'S':
            tanque.Mover(DERECHA);
            break;
        // Espacio para lanzar un disparo
        case ' ':
            // Si no hay espacio activo
            if (disparo.IsActivo()==false)
            {
                // Lo activamos y lo situamos en la columna del tanque y en la fila superior a él
                disparo.Activo();
                disparo.SetX(tanque.GetX());
                disparo.SetY(TABLERO_Y -2);
            }
            break;
        // Cualquier otra tecla no hace nada
        default:
            break;
    }
    
    return seguir;
}

/***************************************************************/
/**
* Muestra un mensaje en pantalla y espera que se pulse una tecla
*
* @param [in] io   Clase que contiene los metodos de I/O
*
* @return   Ningún valor
**/
/***************************************************************/
void MensajeInicio(EntSal io)
{
    io.ClrScr(); // Borramos la pantalla
    io.Escribir(20,10,"Salir - [Esc], q");
    io.Escribir(20,11,"Izquierda - a");
    io.Escribir(20,12,"Derecha - s");
    io.Escribir(20,13,"Disparo - [Espacio]");
    io.Escribir(20,15,"Pulsa una tecla para continuar...");
    io.Pausa(); // Esperamos la pulsación de una tecla
}

/***************************************************************/
/**
* Muestra un mensaje en pantalla y espera que se pulse una tecla
*
* @param [in] io   Clase que contiene los metodos de I/O
* @param [in] bucle   Nos permite saber como termino la
*                          ejecución
*
* @return   Ningún valor
**/
/***************************************************************/
void MensajeFin(EntSal io,bool bucle)
{
    io.ClrScr(); // Borramos la pantalla
    io.Escribir(30,12,(bucle) ? "HAS GANADO :-)" : "HAS PERDIDO :-("); // Escribimos el mensaje
    io.Escribir(20,15,"Pulsa una tecla para continuar...");
    io.Pausa();  // Esperamos la pulsación de una tecla
}


