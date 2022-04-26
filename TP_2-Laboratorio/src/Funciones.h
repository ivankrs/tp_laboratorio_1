/*
 * Funciones.h
 *
 *  Created on: 19 abr. 2022
 *      Author: ivank
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/**
 *\brief -Crea lineas '='.
 */
void lineas(void);
/**
 * \brief -Muestra por pantalla un menu de opciones, y permite el ingreso de un número int, opción.
 * \return devuelve el numero int ingresado, opción.
 */
int menu(char* msj);
/**
 * \brief -Permite pedir e ingresar un número flotante por pantalla, validando que sea mayor que cero(0), y  se guardará en el puntero que se le de a la función.
 * \param pFloat -Puntero a flotante, el espacio en memoria donde quiero guardar el flotante pedido.
 * \param msj -El mensaje que le doy a la función, para aclarar para que es el número flotante a ingresar.
 * \return -Devuelve 0, si no se pudo efectuar la función y 1, se efectuo la función con exito.
 */
int ingresoFloat(float* pFloat, char* msj);
int ingresarInt(char* mensaje);
int ingresarString(char pString[], int len, char* msj);

int validarRangoEntero(int valor, int inferior, int superior);
int validarRangoFlotante(float valor, float inferior, float superior);

/**
 * \brief -Una función usada para confirmar la salida del programa, validando si quiere realmente salir o no.
 * \param p -El puntero a char, donde se guarda el caracter ingresado por el usuario.
 */
void confirmarSalida(char* p);

#endif /* FUNCIONES_H_ */
