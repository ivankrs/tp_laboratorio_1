/*
 * ArrayPasajeros.c
 *
 *  Created on: 26 abr. 2022
 *      Author: ivank
 */

#include "ArrayPasajeros.h"
#include "Funciones.h"

int isEmpty(ePasajero vec[], int tam){
	int kay=0;

	if(vec != NULL && tam > 0){
		for(int i=0; i < tam; i++)
		{
			vec[i].isEmpty=0;
		}
		kay=1;
	}
	return kay;
}

int generarId(ePasajero vec[], int tam){
	int id;
	int maxId=0;

	if(vec != NULL && tam > 0){
		for(int i=0; i < tam; i++)
		{
			if(vec[i].isEmpty==1 && maxId < vec[i].id){
				maxId = vec[i].id;
			}
		}

		for(int i=0; i < tam; i++)
		{
			if(vec[i].isEmpty==0 && i==0){
				id = 1;
				break;
			}
			else if(vec[i].isEmpty==0 && maxId<2000){
				maxId += 1;
				id=maxId;
				break;
			}
		}
	}
	return id-1;
}
int cargarUnPasajero(ePasajero vec[], int id)
{
    int todoOk = 0;
    char auxCad[100];
    if(vec != NULL)
    {
		printf("Ingrese el nombre del pasajero: ");
		fflush(stdin);
		gets(auxCad);

		while(strlen(auxCad) >= 51 || strlen(auxCad) <= 0)
		{
			printf("\n¡Nombre demasiado largo o corto! Reingrese nombre: ");
			fflush(stdin);
			gets(auxCad);
		}
		strcpy(vec[id].nombre, auxCad);

		printf("Ingrese el apellido del pasajero: ");
		fflush(stdin);
		gets(auxCad);

		while(strlen(auxCad) >= 51 || strlen(auxCad) <= 0)
		{
			printf("\n¡Apellido demasiado largo o corto! Reingrese apellido: ");
			fflush(stdin);
			gets(auxCad);
		}
		strcpy(vec[id].apellido, auxCad);

		printf("Ingrese el precio: ");
		scanf("%f", &vec[id].precio);
		while(validarRangoFlotante(vec[id].precio, 1, 1000000)!=1){
			printf("\n¡Error! Numeros validos de 1 a un millon.\n>Reingrese: ");
		}

		printf("Ingrese el codigo de vuelo: ");
		fflush(stdin);
		gets(auxCad);
		while(strlen(auxCad) >= 10 || strlen(auxCad) <= 0)
		{
			printf("\n¡Codigo de vuelo demasiado largo o corto! Reingrese codigo de vuelo: ");
			fflush(stdin);
			gets(auxCad);
		}
		strcpy(vec[id].codigoVuelo, auxCad);

		printf("Ingrese el tipo de pasajero: ");
		scanf("%d", &vec[id].tipoPasajero);

		printf("Ingrese status del vuelo: ");
		scanf("%d", &vec[id].statusVuelo);

		vec[id].isEmpty=1;

        todoOk = 1;
    }
    return todoOk;
}
int modificarUnPasajero(ePasajero vec[], int  id){
	int kay=0;
	if(vec != NULL){
		ingresarInt("Ingrese el id del pasajero a modificar: ");
	}

	return kay;
}

