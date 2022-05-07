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

int isEmpty(ePasajero vec[], int tam);
int generarId(ePasajero vec[], int tam);
int cargarUnPasajero(ePasajero vec[], int  id);
int modificarUnPasajero(ePasajero vec[], int  id);
int bajarUnPasajero(ePasajero vec[], int  id);
int mostrarUnPasajero(ePasajero vec[], int id);
int mostrarListaPasajeros(ePasajero vec[], int tam);
