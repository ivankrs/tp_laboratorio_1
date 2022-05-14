/*
 ============================================================================
 Name        : TP_2-Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Funciones.h"
#include "ArrayPasajeros.h"
#define TAM 2000


int main(void) {

	ePasajero pasajero[TAM]=
	{
			{1, "ivan", "abekeo", 123.2, "A021", 2, 1, 1},
			{2, "vanesa", "abekeo", 145.3, "B022", 1, 0, 1}
	};

	int flagAlta=0;
	char salir='n';

	setbuf(stdout,NULL);
	if( !initPassengers(pasajero, TAM)){
		printf("\n¡Ocurrio un problema al inicializar los pasajeros!\n");
	}



	do{
		switch(menu("\n  *** Menu de Opciones ***\n\n1- ALTAS:\n2- MODIFICAR:\n3- BAJA:\n4- INFORMAR:\n5- SALIR:\n\n")){
		case 1:
			printf(" >1- ALTAS:\n\n");
			if(cargarUnPasajero(pasajero, generarId(pasajero, TAM))){
				flagAlta=1;
			}
			else{
				printf("¡No hay más espacio para cargar pasajeros!\n");
			}
			break;

		case  2:
			if(flagAlta){
				printf(" >2- MODIFICAR:\n");
				if(ordenarListaPasajerosPorId(pasajero, TAM) && mostrarListaPasajeros(pasajero, TAM)){
					modificarUnPasajero(pasajero, ingresarInt("\nIngrese el Id del pasajero a modificar: ", "\n¡Error! Numeros validos de 1 a 2000.\n>Reingrese: ", 1, 2000));
				}
			}
			else{
				printf("¡Debe de haber ingresado un pasajero para poder modificar!\n");
			}
			break;

		case  3:
			if(flagAlta){
				printf(" >3- BAJA:\n");
				if(ordenarListaPasajerosPorId(pasajero, TAM) && mostrarListaPasajeros(pasajero, TAM)){
					flagAlta = bajarUnPasajero(pasajero, TAM, ingresarInt("\nIngrese el Id del pasajero a dar de baja: ", "\n¡Error! Numeros validos de 1 a 2000.\n>Reingrese: ", 1, 2000));
				}
			}
			else{
					printf("¡Debe de haber ingresado un pasajero para poder dar de baja!\n");
			}
			break;

		case  4:
			if(flagAlta){

				printf(" >4- INFORMAR:\n");
				printf("\n1.\n");
				if(ordenarListaPasajerosPorApellido(pasajero, TAM)){
					mostrarListaPasajeros(pasajero, TAM);
				}
				else{
					printf("¡No hay pasajero para mostrar\n");
				}
				printf("\n2.\n");
				if(!mostraPrecios(pasajero, TAM)){
					printf("¡No hay precios para mostrar\n");
				}
				printf("\n3.\n");
				if(ordenarListaPasajerosPorCodigo(pasajero, TAM)){
					mostrarListaPasajerosActivos(pasajero, TAM);
				}
				else{
					printf("¡No hay pasajero para mostrar\n");
				}
			}
			else{
				printf("¡Debe de haber ingresado un pasajero para poder informar!\n");
			}

			break;

		case  5:
			confirmarSalida(&salir);
			printf("\n  *** ¡Ha salido del sistema! ***");
			break;

		default:
			printf(" X ¡Opcion invalida! X");
			break;
		}
	}while(salir!='s');


	return EXIT_SUCCESS;
}
