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

	ePasajero pasajero[TAM]={{1, "ivan", "keo", 123.2, "a21", 1, 2, 1},{2, "vanesa", "fredo", 145.3, "a22", 1, 2, 1}};
	//int flagAlta=0;

	char salir='n';

	setbuf(stdout,NULL);
	/*if(!isEmpty(pasajero, TAM)){
		printf("\n¡Ocurrio un problema!\n");
	}*/

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
			//se genera ID de 1 a 2000 y se carga pasajero bajo esa ID
			//flagAlta=1;
			break;

		case  2:
			printf("2- MODIFICAR\n");
			//if(flagAlta){
				modificarUnPasajero(pasajero, ingresarInt("\nIngrese el Id del pasajero a modificar: ", "\n¡Error! Numeros validos de 1 a 2001.\n>Reingrese: ", 1, 2001));
			//}
			break;

		case  3:
			printf("3- BAJA\n");
			//if(flagAlta){
				bajarUnPasajero(pasajero, ingresarInt("\nIngrese el Id del pasajero a dar de baja: ", "\n¡Error! Numeros validos de 1 a 2001.\n>Reingrese: ", 1, 2001));
			/*}
			else{
					printf("\n¡Debe de haber ingresado un pasajero para poder dar de baja!\n");
				}*/
			break;

		case  4:
			printf("4- INFORMAR\n");
			mostrarListaPasajeros(pasajero, TAM);

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
