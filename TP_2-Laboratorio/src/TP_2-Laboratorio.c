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
#define TAM 2


int main(void) {

	ePasajero pasajero[TAM]=
	{
			{1, "ivan", "abekeo", 123.2, "A021", 2, 1, 1},
			{2, "vanesa", "abekeo", 145.3, "B022", 1, 2, 1}
	};

	int flagAlta=0;
	char salir='n';

	setbuf(stdout,NULL);
	//isEmpty(pasajero, TAM)){


	do{
		switch(menu("\n  *** Menu de Opciones ***\n\n1- ALTAS:\n2- MODIFICAR:\n3- BAJA:\n4- INFORMAR:\n5- SALIR:\n\n")){
		case 1:
			printf("1- ALTAS\n");
			for(int i=0;i<TAM;i++){
				if(pasajero[i].isEmpty==0){
					cargarUnPasajero(pasajero, generarId(pasajero, TAM));
					break;
				}
				else{
					printf("\n¡No hay más espacio para cargar pasajeros!\n");
					break;
				}
			}
			flagAlta=1;
			break;

		case  2:
			if(flagAlta){
				printf("2- MODIFICAR\n");
				if(mostrarListaPasajeros(pasajero, TAM)){
					modificarUnPasajero(pasajero, ingresarInt("\nIngrese el Id del pasajero a modificar: ", "\n¡Error! Numeros validos de 1 a 2001.\n>Reingrese: ", 1, 2000));
				}
			}
			else{
				printf("\n¡Debe de haber ingresado un pasajero para poder modificar!\n");
			}
			break;

		case  3:
			if(flagAlta){
				printf("3- BAJA\n");
				bajarUnPasajero(pasajero, ingresarInt("\nIngrese el Id del pasajero a dar de baja: ", "\n¡Error! Numeros validos de 1 a 2001.\n>Reingrese: ", 1, 2000));
			}
			else{
					printf("\n¡Debe de haber ingresado un pasajero para poder dar de baja!\n");
				}
			break;

		case  4:
			if(flagAlta){

				printf("4- INFORMAR\n");
				if(ordenarListaPasajerosPorApellido(pasajero, TAM)){
					printf("\n1.\n");
					mostrarListaPasajeros(pasajero, TAM);
				}
				printf("\n2.\n");
				mostraPrecios(pasajero, TAM);
				if(ordenarListaPasajerosPorCodigo(pasajero, TAM)){
					printf("\n3.\n");
					mostrarListaPasajeros(pasajero, TAM);
				}
			}
			else{
				printf("\n¡Debe de haber ingresado un pasajero para poder informar!\n");
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
