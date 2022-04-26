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
#define TAM 3
#define TAN 51

int main(void) {

	ePasajero pasajero[TAM];
	//char nombre[TAN];

	//char salir='n';

	setbuf(stdout,NULL);
	if(!isEmpty(pasajero, TAM)){
		printf("\nOcurrio un problema\n");
	}

	//do{


		switch(menu("\n  *** Menu de Opciones ***\n\n1- ALTAS:\n2- MODIFICAR:\n3- BAJA:\n4- INFORMAR:\n5- SALIR:\n\n")){
		case 1:
			printf("1- ALTAS\n");

			cargarUnPasajero(pasajero, generarId(pasajero, TAM));

			printf("Id: %04d\nNombre: %s\nApellido: %s\nPrecio: %.2f\nCodigo de vuelo: %s\nTipo de pasajero: %d\nStatus de vuelo: %d\nisEmpty: %d", pasajero->id,
																																					pasajero->nombre,
																																					pasajero->apellido,
																																					pasajero->precio,
																																					pasajero->codigoVuelo,
																																					pasajero->tipoPasajero,
																																					pasajero->statusVuelo,
																																					pasajero->isEmpty);

			//se genera ID de 1 a 2000 y se carga pasajero bajo esa ID

			break;

		case  2:
			printf("2- MODIFICAR");
			break;

		case  3:
			printf("3- BAJA");
				break;

		case  4:
			printf("4- INFORMAR");
				break;

		case  5:
			//confirmarSalida(&salir);
				break;

		default:
			printf(" X ¡Opcion invalida! X");
				break;

		}
//	}while(salir!='s');


	return EXIT_SUCCESS;
}
