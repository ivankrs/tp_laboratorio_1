/*
 * ArrayPasajeros.h
 *
 *  Created on: 26 abr. 2022
 *      Author: ivank
 */

#ifndef ARRAYPASAJEROS_H_
#define ARRAYPASAJEROS_H_


typedef struct
{
    int id; //lo genero antes de hacer un ingreso... No se pide al usuario
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoVuelo[10];
    int tipoPasajero;
    int statusVuelo;
    int isEmpty; //No se pide al usuario
} ePasajero;

#endif /* ARRAYPASAJEROS_H_ */
/**
 * \brief permite inicializar el campo isEmpty con 0.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 */
void isEmpty(ePasajero vec[], int tam);
/**
 * \brief permite recorrer el vector de pasajeros buscando los indices donde todavia no se cargo ningun pasajero, para asignarle un id.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 * \return devuelve el id generado.
 */
int generarId(ePasajero vec[], int tam);
/**
 * \brief permite el ingreso de un pasajero, validando todos sus campos.
 * \param vec un vector de pasajeros.
 * \param id el indice donde se cargara el pasajero ingresado.
 * \return devuelve 1, si se logro ingresar correctamente y 0, de ser el caso contrario.
 */
int cargarUnPasajero(ePasajero vec[], int  id);
/**
 * \brief permite modificar un pasajero, ya sea un solo campo de este o todo los campos. Se utiliza un sub menu.
 * \param vec un vector de pasajeros.
 * \param id el indice donde se encuentra el pasajero a modificar.
 * \return devuelve 1, si se logro modificar correctamente y 0, de ser el caso contrario.
 */
int modificarUnPasajero(ePasajero vec[], int  id);
/**
 * \brief un menu de opciones, para modificar un pasajero.
 * \param vec un vector de pasajeros.
 * \param idX indice donde se encuentra el pasajero a modificar.
 * \return devuelve el numero int que el usuario haya elegido de entre 1 a 7.
 */
int menuModificaUnPasajero(ePasajero vec[], int  idX);
/**
 * \brief permite dar de baja un pasajero.
 * \param vec un vector de pasajeros.
 * \param id indice donde se encuentra el pasajero a dar de baja.
 * \return devuelve 1, si se logro dar de baja correctamente y 0, de ser el caso contrario.
 */
int bajarUnPasajero(int* flagAlta,ePasajero vec[], int tam, int  id);
/**
 * \brief permite mostrar un pasajero.
 * \param vec un vector de pasajeros.
 * \param id indice donde se encuentra el pasajero a mostrar.
 * \return devuelve 1, si se logro mostrar correctamente y 0, de ser el caso contrario.
 */
int mostrarUnPasajero(ePasajero vec[], int id);
/**
 * \brief permite mostra un lista de pasajeros.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 * \return devuelve 1, si se logro mostrar correctamente y 0, de ser el caso contrario.
 */
int mostrarListaPasajeros(ePasajero vec[], int tam);
/**
 * \brief permite mostra un lista de pasajeros con el estado "Activo"==1.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 * \return devuelve 1, si se logro mostrar correctamente y 0, de ser el caso contrario.
 */
int mostrarListaPasajerosActivos(ePasajero vec[], int tam);
/**
 * \brief permite ordenar la lista de pasajeros por apellido alfabeticamente y tipo de pasajero.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 * \return devuelve 1, si se logro ordenar correctamente y 0, de ser el caso contrario.
 */
int ordenarListaPasajerosPorApellido(ePasajero vec[], int tam);
/**
 * \brief permite ordenar la lista de pasajeros por codigo de vuelo alfabeticamente y status de vuelo.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 * \return devuelve 1, si se logro ordenar correctamente y 0, de ser el caso contrario.
 */
int ordenarListaPasajerosPorCodigo(ePasajero vec[], int tam);
/**
 * \brief permite recorrer el vector de pasajeros, permitiendo, acumular el coste a todos los pasajero ingresado y poder calcular el precio total, el precio promedio y la cantidad de pasajeros que pagaron por sobre el precio promedio.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 * \param total un puntero a flotante, donde se guarda el precio total.
 * \param promedio un puntero a flotante, donde se guarda el precio promedio.
 * \param cant un puntero a entero, donde se guarda la cantidad de personas que pagaron por sobre el precio promedio.
 * \return devuelve 1, si se logro calcular correctamente y 0, de ser el caso contrario.
 */
int hacerPromediosPrecios(ePasajero vec[], int tam, float* total, float* promedio, int* cant);
/**
 * \brief permite mostrar el precio total, el precio promedio y la cantidad de personas que pagaron por sobre el precio promedio.
 * \param vec un vector de pasajeros.
 * \param tam el tamaño del vector de pasajeros.
 * \return devuelve 1, si se logro calcular correctamente y 0, de ser el caso contrario.
 */
int mostraPrecios(ePasajero vec[], int tam);
