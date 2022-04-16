/*
 ============================================================================
 Name        : TP_1-Laboratorio.c
 Author      : Ivan Keumurdji Rizzuti
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
para ofrecerlos a sus clientes.
Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
 */

#include "Funciones.h"

int main(void) {

	float kmVuelo=0;
	float precioAero=0;
	float precioLatam=0;

	float precioDescuentoAero;
	float precioInteresAero;
	float precioAeroEnBitcoin;
	float precioUnitarioAero;

	float precioDescuentoLatam;
	float precioInteresLatam;
	float precioLatamEnBitcoin;
	float precioUnitarioLatam;

	float diferenciaPrecios;

	float descuento=10;
	float aumento=25;
	float bitcoin = 4606954.55;

	int kayU=0;
	int kayD=0;

	char confirma;
	char salir='n';

	descuento=(descuento/100);
	aumento=(aumento/100);

	setbuf(stdout,NULL);
	do{
		switch(menu(kmVuelo,precioAero,precioLatam)){
		 case 1:
			 if(kayU==0){

				 kayU=ingresoOpcionUno(&kmVuelo);
			 }
			 else{
				 while(confirma!='s'&& confirma!='n'){
					printf("¡Ya ha ingresado los kilometros del viaje!¿Quiere volver a ingresarlos?(s/n): ");
					fflush(stdin);
					scanf("%c",&confirma);
					confirma=tolower(confirma);
					if(confirma=='s'){
						kayU=ingresoOpcionUno(&kmVuelo);
					}
					else{
						confirma='x';
						break;
					}
				 }
			 }
				break;
		case 2:
			if(kayD==0){
				kayD=ingresoOpcionDos(&precioAero, &precioLatam);
			}
			else{
				while(confirma!='s'&& confirma!='n'){
						printf("¡Ya ha ingresado los precios de los vuelos! ¿Quiere volver a ingresarlos?(s/n): ");
						fflush(stdin);
						scanf("%c",&confirma);
						confirma=tolower(confirma);
						if(confirma=='s'){
							kayD=ingresoOpcionDos(&precioAero, &precioLatam);
						}
						else{
							confirma='x';
							break;
						}
					}
				}
				break;
		case 3:
			if((kayU==1 || kayU==2) && (kayD==1 || kayD==2)){
				if(hacerCalculos(precioAero, precioLatam, kmVuelo, bitcoin, &precioDescuentoAero, descuento, &precioInteresAero, aumento, &precioAeroEnBitcoin, &precioUnitarioAero, &precioDescuentoLatam, &precioInteresLatam, &precioLatamEnBitcoin, &precioUnitarioLatam, &diferenciaPrecios))
				{
					printf(" ***Se han efectuado los calculos***\n");
					kayU=2;
					kayD=2;
				}
				else
				{
					printf("¡Ocurrio un problema al hacer los calculos!");
				}
			}
			else{
				if(kayU==0 && kayD==1){
					printf("¡Debe ingresar datos en las opcion 1 para hacer los calculos!\n");
				}
				else{
					if(kayU==1 && kayD==0){

						printf("¡Debe ingresar datos en las opcion 2 para hacer los calculos!\n");
					}
					else{
						printf("¡Debe ingresar datos en las opciones 1 y 2 para hacer los calculos!\n");
					}
				}
			}
				break;
		case 4:
			if(kayU==2 && kayD==2){
				printf(" ***Informe de costos***\n");
				mostrarResultado("Latam", precioDescuentoLatam, precioInteresLatam, precioLatamEnBitcoin, precioUnitarioLatam);
				mostrarResultado("Aerolíneas", precioDescuentoAero, precioInteresAero, precioAeroEnBitcoin, precioUnitarioAero);
				printf("\nLa diferencia de precio es : $%.2f", diferenciaPrecios);
				kayU=0;
				kayD=0;
			}
			else{
				printf("¡Debe haber hecho los calculos para entrar en la opcion 4!\n");
			}
				break;
		case 5:
			if(cargaForzada(162965, 159339, 7090, descuento, aumento, bitcoin)!=1){
				printf("\n¡Ocurrio un problema con la carga forzada de datos!\n");
			}
				break;
		case 6:
			confirmarSalida(&salir);
			printf("\n ***Ha salido con exito***\n");
			lineas();
				break;
		default:
				printf(" X ¡Opcion Invalida! X\n");
		}
	}while(salir!='s');

	return EXIT_SUCCESS;
}
