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
 *\brief -Crea lineas '=~'.
 */
void lineas(void);
/**
 * \brief -Muestra por pantalla un menu de opciones, y permite el ingreso de un número int, opción.
 * \return devuelve el numero int ingresado, opción.
 */
int menu(char* msj);
/**
 * \brief permite pedir un numero float, y valida que este dentro del rango que le pasemos a la funcion.
 * \param msj mensaje para pedir el numero float.
 * \param msjError mensaje de error para volver pedir el numero float.
 * \param rangoBajo rango minimo, valor mas bajo que puede tener el numero float.
 * \param rangoAlto rango maximo, valor mas alto que puede tener el numero float.
 * \return devuelve el numero que haya recibido, ya validado.
 */
float ingresoFloat(char* msj, char* msjError, int rangoBajo, int rangoAlto);
/**
 * \brief permite pedir un numero int, y valida que este dentro del rango que le pasemos a la funcion.
 * \param msj mensaje para pedir el numero int.
 * \param msjError mensaje de error para volver pedir el numero int.
 * \param rangoBajo rango minimo, valor mas bajo que puede tener el numero int.
 * \param rangoAlto rango maximo, valor mas alto que puede tener el numero int.
 * \return devuelve el numero que haya recibido, ya validado.
 */
int ingresarInt(char* msj, char* msjError, int rangoBajo, int rangoAlto);
/**
 * \brief permite pedir una cadena de caracteres, string, validando que su largo este dentro del rango dado a la funcion.
 * \param pString una cadena de caracteres, string.
 * \param msj mensaje para pedir cadena de caracteres, string.
 * \param msjError mensaje de error para volver a pedir la cadena de caracteres, string.
 * \param rangoBajo el largo minimo que puede tener la cadena de caracteres, string.
 * \param rangoAlto el largo maximo que puede tener la cadena de caracteres, string.
 * \return devuelve 1, si se logro ingresar correctamente la cadena de caracteres, string, y 0, de ser el caso contrario.
 */
int ingresarString(char pString[], char* msj, char* msjError, int rangoBajo, int rangoAlto);
/**
 * \brief permite validar un numero int entre un rango que le demos.
 * \param valor	numero int a validar.
 * \param inferior rango minimo, valor mas bajo que puede tener el numero int.
 * \param superior rango maximo, valor mas alto que puede tener el numero int.
 * \return devuelve 1, si el valor es validado correctamente y 0, de no haber sido validado.
 */
int validarRangoEntero(int valor, int inferior, int superior);
/**
 * \brief permite validar un numero float entre un rango que le demos.
 * \param valor	numero float a validar.
 * \param inferior rango minimo, valor mas bajo que puede tener el numero float.
 * \param superior rango maximo, valor mas alto que puede tener el numero float.
 * \return devuelve 1, si el valor es validado correctamente y 0, de no haber sido validado.
 */
int validarRangoFlotante(float valor, float inferior, float superior);
/**
 * \brief permite intercambiar el valor de dos numeros int entre si.
 * \param n1 un puntero a un numero int.
 * \param n2 un puntero a un numero int.
 */
void swapEnteros(int* n1,int* n2);
/**
 * \brief permite intercambiar el valor de dos numeros float entre si.
 * \param n1 un puntero a un numero float.
 * \param n2 un puntero a un numero float.
 */
void swapFlotantes(float* n1,float* n2);
/**
 * \brief permite intercambiar el contenido de dos cadenas de caracteres, strings, entre si.
 * \param n1 una cadena de caracteres, string.
 * \param n2 una cadena de caracteres, string.
 */
void swapString (char* n1,char* n2);
/**
 * \brief -Una función usada para confirmar la salida del programa, validando si quiere realmente salir o no.
 * \param p -El puntero a char, donde se guarda el caracter ingresado por el usuario.
 */
void confirmarSalida(char* p);

#endif /* FUNCIONES_H_ */
