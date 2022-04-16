/*
 * Funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: ivank
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 *\brief -Crea lineas '='.
 */
void lineas(void);
/**
 * \brief -Muestra por pantalla un menu de opciones, mostrando las variables kilometro, precio de Aerolíneas y precio de Latam, y permite el ingreso de un número int, opción.
 * \param km -Kilometros ingresados cuando se efectua la opcion 1.
 * \param precioAero -Precio de Aerolíneas ingresado cuando se efectua la opción 2.
 * \param precioLatam -Precio de Latam ingresado cuando se efectua la opción 2.
 * \return devuelve el numero int ingresado, opción.
 */
int menu(float km, float precioAero, float precioLatam);
/**
 * \brief -Permite pedir e ingresar un número flotante por pantalla, validando que sea mayor que cero(0), y  se guardará en el puntero que se le de a la función.
 * \param pFloat -Puntero a flotante, el espacio en memoria donde quiero guardar el flotante pedido.
 * \param msj -El mensaje que le doy a la función, para aclarar para que es el número flotante a ingresar.
 * \return -Devuelve 0, si no se pudo efectuar la función y 1, se efectuo la función con exito.
 */
int ingresoFloat(float* pFloat, char* msj);
/**
 * \brief -Hace uso de la función "ingresarFloat", para pedir el ingreso de la cantidad de kilometros del viaje.
 * \param kmVuelo -Dirección de memoria donde se guarda la cantidad de kilometros del viaje.
 * \return -Devuelve 0, si no se pudo efectuar la función y 1, se efectuo la función con exito.
 */
int ingresoOpcionUno(float* kmVuelo);
/**
 * \brief -Hace uso de la función "ingresarFloat", para pedir el ingreso de los precios de los vuelos de Aerolíneas y Latam.
 * \param precioAero -Dirección de memoria donde se guarda el precio de vuelo de Aerolíneas.
 * \param precioLatam -Dirección de memoria donde se guarda vuelo de Latam.
 * \return -Devuelve 0, si no se pudo efectuar la función y 1, se efectuo la función con exito.
 */
int ingresoOpcionDos(float* precioAero, float* precioLatam);
/**
 * \brief -Calcula el descuento que se le pase a la función en base al precio que se le pase a la función y guarda el valor del precio con descuento en el puntero que se le pase a la función.
 * \param descuento -Cantidad de descuneto que se le hace al precio.
 * \param precio -El precio que se le pasa a la función.
 * \param pPrecioConDescuento -El puntero que se le pasa a la función, y donde se guardará el precio con el descuento ya hecho.
 * \return -Devuelve 0, si no se pudo efectuar la función y 1, se efectuo la función con exito.
 */
int hacerDescuento(float descuento, float precio, float* pPrecioConDescuento);
/**
 * \brief -Calcula el aumento que se le pase a la función en base al precio que se le pase a la función y guarda el valor del precio con aumento en el puntero que se le pase a la función.
 * \param aumento -Cantidad de aumento que se le hace al precio.
 * \param precio -El precio que se le pasa a la función.
 * \param pPrecioConAumento -El puntero que se le pasa a la función, y donde se guardará el precio con el aumento ya hecho.
 * \return -Devuelve 0, si no se pudo efectuar la función y 1, se efectuo la función con exito.
 */
int hacerAumento(float aumento, float precio, float* pPrecioConAumento);
/**
 * \brief -Calcula la converci�n a bitcoin en base al precio que se le pase a la funci�n y guarda el valor del precio en bitcoins en el puntero que se le pase a la funci�n.
 * \param precio -El precio que se le pasa a la funci�n.
 * \param bitcoin -Un n�mero flotante, el valor de bitcoin.
 * \param precioBitcoin	-El puntero que se le pasa a la funci�n, y donde se guardar� el valor con la converci�n de peso a bitcoin ya hecha.
 * \return -Devuelve 0, si no se pudo efectuar la funci�n y 1, se efectuo la funci�n con exito.
 */
int pasarBitcoin(float precio, float bitcoin, float* precioBitcoin);
/**
 * \brief -Calcula el precio por kilometro, en base a los kilometros y precio que se le pasa a la funci�n, y guarda el precio por kilometro en el puntero que se le pase a la funci�n.
 * \param precio -El precio que se le pasa a la funci�n.
 * \param km -La cantidad de kilometros que se le pasa a la funci�n.
 * \param precioUnitario -El puntero que se le pasa a la funci�n, y donde se guardar� el valor luego de haber calculado el precio unitario.
 * \return -Devuelve 0, si no se pudo efectuar la funci�n y 1, se efectuo la funci�n con exito.
 */
int precioUnitario(float precio, float km, float* precioUnitario);
/**
 * \brief -Una resta entre dos flotantes, como se busca la diferencia entre ambos, el valor devuelto siempre es positivo.
 * \param a -Un n�mero flotante que se le pasa a la funci�n.
 * \param b -Un n�mero flotante que se le pasa a la funci�n.
 * \param rst -El puntero que se le pasa a la funci�n, y donde se guardar� el valor del resto.
 * \return -Devuelve 0, si no se pudo efectuar la funci�n y 1, se efectuo la funci�n con exito.
 */
int restarFloat(float a, float b, float* rst);
/**
 * \brief -Una funcion que llama a todas las funciones de calculo.
 * \param precioAero -Precio de Aerol�neas ingresado cuando se efectua la opci�n 2.
 * \param precioLatam -Precio de Latam ingresado cuando se efectua la opci�n 2.
 * \param kilometros -Kilometros ingresados cuando se efectua la opcion 1.
 * \param bitcoin -Un n�mero flotante, el valor de bitcoin.
 * \param precioDescuentoAero -El puntero que se le pasa a la funci�n, y donde se guardar� el precio con el descuento ya hecho.
 * \param descuento -Cantidad de descuneto que se le hace al precio.
 * \param precioInteresAero -El puntero que se le pasa a la funci�n, y donde se guardar� el precio con el aumento ya hecho.
 * \param aumento -Cantidad de aumento que se le hace al precio.
 * \param precioAeroEnBitcoin -El puntero que se le pasa a la funci�n, y donde se guardar� el valor con la converci�n de peso a bitcoin ya hecha.
 * \param precioUnitarioAero -El puntero que se le pasa a la funci�n, y donde se guardar� el valor luego de haber calculado el precio unitario.
 * \param precioDescuentoLatam -El puntero que se le pasa a la funci�n, y donde se guardar� el precio con el descuento ya hecho.
 * \param precioInteresLatam -El puntero que se le pasa a la funci�n, y donde se guardar� el precio con el aumento ya hecho.
 * \param precioLatamEnBitcoin -El puntero que se le pasa a la funci�n, y donde se guardar� el valor con la converci�n de peso a bitcoin ya hecha.
 * \param precioUnitarioLatam -El puntero que se le pasa a la funci�n, y donde se guardar� el valor luego de haber calculado el precio unitario.
 * \param diferenciaPrecios -El puntero que se le pasa a la funci�n, y donde se guardar� el valor resultante del resto entre dos n�meros flotantes.
 * \return -Devuelve 0, si no se pudo efectuar la funci�n y 1, se efectuo la funci�n con exito.
 */
int hacerCalculos(float precioAero, float precioLatam, float kilometros,float bitcoin,float* precioDescuentoAero, float descuento, float* precioInteresAero, float aumento, float* precioAeroEnBitcoin,float* precioUnitarioAero,float* precioDescuentoLatam,float* precioInteresLatam,float* precioLatamEnBitcoin, float* precioUnitarioLatam, float* diferenciaPrecios);
/**
 * \brief -Una funci�n usada para mostrar volaros.
 * \param agencia -El nombre de la agencia de los valores que se muestran.
 * \param pDescuento -El valor del precio con descuento que se muestra.
 * \param pAumento -El valor del precio con aumento que se muestra.
 * \param pBitcoin -El valor del precio convertido de peso a bitcoin que se muestra.
 * \param pUnitario -El valor por kilometro que se muestra.
 */
void mostrarResultado(char* agencia, float pDescuento, float pAumento, float pBitcoin, float pUnitario);
/**
 * \brief -Una funci�n que permite la carga forzada de datos.
 * \param precioAero -El precio del vuelo con Aerol�aneas que se carga.
 * \param precioLatam -El precio del vuelo con Latam que se carga.
 * \param kilometros -La cantidad de kilometros de viajes realizado que se carga.
 * \param descuento -Cantidad de descuento que se le hace al precio.
 * \param aumento -Cantidad de aumento que se le hace al precio.
 * \param bitcoin -Un n�mero flotante, el valor de bitcoin.
 * \return -Devuelve 0, si no se pudo efectuar la funci�n y 1, se efectuo la funci�n con exito.
 */
int cargaForzada(float precioAero, float precioLatam, float kilometros, float descuento, float aumento, float bitcoin);
/**
 * \brief -Una funci�n usada para confirmar la salida del programa, validando si quiere realmente salir o no.
 * \param p -El puntero a char, donde se guarda el caracter ingresado por el usuario.
 */
void confirmarSalida(char* p);


#endif /* FUNCIONES_H_ */

