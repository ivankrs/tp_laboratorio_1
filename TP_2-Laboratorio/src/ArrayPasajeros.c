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
	int id=-1;
	int maxId=0;
	int i;

	if(vec != NULL && tam > 0){
		for(i=0; i < tam; i++)
		{
			if(vec[i].isEmpty==1 && maxId < vec[i].id){
				maxId = vec[i].id;
			}
			if(vec[i].isEmpty==0 && i==0){
				id = 1;
				break;
			}
			else if(vec[i].isEmpty==0 && maxId<2001){
				maxId += 1;
				id=maxId;
				break;
			}
		}
	}
	if(id==-1){
		printf("\n¡Ocurrio un problema en la creacion de Id!");
	}
	return id;
}
int cargarUnPasajero(ePasajero vec[], int idX)
{
	int id=idX-1;
    int todoOk = 0;
    if(vec != NULL)
    {
    	ingresarString(vec[id].nombre, "Ingrese el nombre del pasajero: ", "\n¡Nombre demasiado largo o corto! >Reingrese nombre: ", 0, 51);

		ingresarString(vec[id].apellido, "Ingrese el apellido del pasajero: ", "\n¡Apellido demasiado largo o corto! >Reingrese apellido: ", 0, 51);

		vec[id].precio=ingresoFloat("Ingrese el precio: ","\n¡Error! Numeros validos de 1 a un millon.\n>Reingrese: ", 1, 1000000);

		ingresarString(vec[id].codigoVuelo,"Ingrese el codigo de vuelo: ", "\n¡Codigo de vuelo demasiado largo o corto! >Reingrese codigo de vuelo: ", 0, 10);

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
	if(vec != NULL && id>0){
		cargarUnPasajero(vec, id);
		kay=1;
	}
	return kay;
}
int bajarUnPasajero(ePasajero vec[], int  idX){
	int kay=0;
	int id=idX-1;
	char confirma='x';
	if(vec != NULL && id>=0 && vec[id].isEmpty==1){
		mostrarUnPasajero(vec, id);

		 while(confirma!= 's' && confirma!= 'n'){
			printf("\n¿Confirma dar de baja?-('s'= si / 'n'= no): ");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma=tolower(confirma);
		}
		if(confirma=='s'){
			vec[id].isEmpty=0;
			kay=1;
			printf("\n¡Se ha dado de baja con exito!");
		}
		else{
			printf("\n¡No se ha dado de baja!");
		}
	}
	else{
		printf("\n¡No hay pasajeros para dar de baja!");
	}

	return kay;
}
int mostrarUnPasajero(ePasajero vec[], int idX){
	int kay=0;
	int id=idX-1;
	if(vec!=NULL && id>=0){
		printf("\n Id     Nombre     Apellido     Precio    Codigo de vuelo   Tipo de pasajero   Status del vuelo\n");
		printf("----------------------------------------------------------------------------------------------\n");
		printf("%04d%10s  %10s      %.2f         %4s                %d                  %d\n", vec[id].id, vec[id].nombre, vec[id].apellido, vec[id].precio, vec[id].codigoVuelo, vec[id].tipoPasajero, vec[id].statusVuelo);
		kay=1;
	}


	return kay;

}
int mostrarListaPasajeros(ePasajero vec[], int tam){
	int kay=0;
	int i;
	if(vec!=NULL && tam>0){
		printf("\n Id     Nombre     Apellido     Precio    Codigo de vuelo   Tipo de pasajero   Status del vuelo\n");
		printf("----------------------------------------------------------------------------------------------\n");

		for(i=0 ; i<tam; i++){
			if(vec[i].isEmpty ==1){
				printf("%04d%10s  %10s      %.2f         %4s                %d                  %d\n", vec[i].id, vec[i].nombre, vec[i].apellido, vec[i].precio, vec[i].codigoVuelo, vec[i].tipoPasajero, vec[i].statusVuelo);
			}
		}
			kay=1;
	}
	return kay;
}
