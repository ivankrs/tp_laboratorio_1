/*
 * Funciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: ivank
 */


#include "Funciones.h"


void lineas(void){
	int i;
	printf("\n");
	for(i=1;i<40;i++)
	{
		printf("==");
	}
	printf("\n");
}
//MENU
int menu(float km, float precioAero, float precioLatam){
    int opcion;

    //system("cls");
    lineas();
    printf("\n  *** Menu de Opciones ***\n\n");
    printf("1- Ingresar Kilometros: \n|Cantidad de Km = %.2fKm|\n", km);
    printf("2- Ingresar precio de vuelos: \n|Precio con Aerolíneas = $%.2f, Precio con Latam = $%.2f|\n", precioAero, precioLatam);
    printf("3- Calcular todos los costos\n");
    printf("4- Informar resultados\n");
    printf("5- Cargar forzada de datos\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    lineas();
    printf("\n");

    //system("cls");

    return opcion;
}
//INGRESOS (pnt. 1-2)
int ingresoFloat(float* pFloat, char* msj){
	int kay;
	kay=0;
	if(pFloat!= 0){
		printf("%s", msj);
		scanf("%f", pFloat);

		while(*pFloat<1){
			printf("¡El valor ingresado no es valido! �REINTENTE!: ");
			scanf("%f", pFloat);
		}
		kay=1;
	}

	return kay;
}

int ingresoOpcionUno(float* kmVuelo){
	int kay=0;

	if(ingresoFloat(kmVuelo,"Ingrese la cantidad de kilometros de viaje: ")){
		 kay=1;
	 }
	 else{
		 printf("¡Ocurrio un problema al ingresar los kilometros de viaje!\n");
	 }
	return kay;
}

int ingresoOpcionDos(float* precioAero, float* precioLatam){
	int kay=0;

	if(ingresoFloat(precioAero, "Ingrese el precio por Aerol�neas: ")!=1){
		printf("\n¡Ocurrio un problema al ingresar el precio Aerol�neas!\n");
	}
	else{
		kay+=2;
	}
	if(ingresoFloat(precioLatam, "Ingrese el precio por Latam: ")!=1){
		printf("\n¡Ocurrio un problema al ingresar el precio Latam!\n");
	}
	else{
		kay+=2;
	}
	if(kay==4){
		kay=1;
	}
	else{
		kay=0;
	}
	return kay;
}
//CALCULOS(pnt. 3)
int hacerDescuento(float descuento, float precio, float* pPrecioConDescuento){
	int kay=0;

	if(descuento>0 && precio>0 && pPrecioConDescuento!=0){

		*pPrecioConDescuento=(precio * descuento);

		kay=1;
	}
	return kay;
}

int hacerAumento(float aumento, float precio, float* pPrecioConAumento){
	int kay=0;
	if(aumento>0 && precio>0 && pPrecioConAumento!=0){

		*pPrecioConAumento= ( precio + (precio * aumento) );

		kay=1;
	}
	return kay;
}

int pasarBitcoin(float precio,float bitcoin, float* precioBitcoin){
	int kay=0;
	if(precio>0 && bitcoin>0 && precioBitcoin!=0){

		*precioBitcoin= (precio / bitcoin);
		kay=1;
	}
	return kay;
}

int precioUnitario(float precio, float km, float* precioUnitario){
	int kay=0;
	if(precio>0 && km>0 && precioUnitario!=0){

		*precioUnitario = ( precio / km );
		kay=1;
	}
	return kay;
}

int restarFloat(float a, float b, float* rst){
	int kay=0;
	if(rst !=0){

		*rst = ( a - b );
		if(*rst<0){

			*rst=(b-a);
		}
		kay=1;
	}
	return kay;
}

int hacerCalculos(float precioAero, float precioLatam, float kilometros,float bitcoin,float* precioDescuentoAero, float descuento, float* precioInteresAero, float aumento, float* precioAeroEnBitcoin,float* precioUnitarioAero,float* precioDescuentoLatam,float* precioInteresLatam,float* precioLatamEnBitcoin, float* precioUnitarioLatam, float* diferenciaPrecios){
	int kay=0;


	if(hacerDescuento(descuento, precioAero, precioDescuentoAero)!=1){
		printf("\n¡Ocurrio un problema al calcular el descuento con Aerolíneas!\n");
	}
	else{
		kay+=1;
	}
	if(hacerAumento(aumento, precioAero, precioInteresAero)!=1){
		printf("\n¡Ocurrio un problema al calcular el interes con Aerolíneas!\n");
	}
	else{
			kay+=1;
		}
	if(pasarBitcoin(precioAero, bitcoin, precioAeroEnBitcoin)!=1){
		printf("\n¡Ocurrio un problema al calcular el precio con Aerolíneas en Bitcoins!\n");
	}
	else{
			kay+=1;
		}
	if(precioUnitario(precioAero, kilometros, precioUnitarioAero)!=1){
		printf("\n¡Ocurrio un problema al calcular el precio unitario de Aerolíneas!\n");
	}
	else{
			kay+=1;
		}
	if(hacerDescuento(descuento, precioLatam, precioDescuentoLatam)!=1){
		printf("\n¡Ocurrio un problema al calcular el descuento con Latam!\n");
	}
	else{
			kay+=1;
		}
	if(hacerAumento(aumento, precioLatam, precioInteresLatam)!=1){
		printf("\n¡Ocurrio un problema al calcular el interes con Latam!\n");
	}
	else{
			kay+=1;
		}
	if(pasarBitcoin(precioLatam, bitcoin, precioLatamEnBitcoin)!=1){
		printf("\n¡Ocurrio un problema al calcular el precio con Latam en Bitcoins!\n");
	}
	else{
			kay+=1;
		}
	if(precioUnitario(precioLatam, kilometros, precioUnitarioLatam)!=1){
		printf("\n¡Ocurrio un problema al calcular el precio unitario de Latam!\n");
	}
	else{
			kay+=1;
		}
	if(restarFloat(precioAero, precioLatam, diferenciaPrecios)!=1){
		printf("\n¡Ocurrio un problema al calcular la diferencia de los precio ingresados!\n");
	}
	else{
			kay+=1;
		}
	if(kay==9){
		kay=1;
	}
	else{
		kay=0;
	}
	return kay;
}
void mostrarResultado(char* agencia, float pDescuento, float pAumento, float pBitcoin, float pUnitario){
	printf("\n> %s: \na) Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio pagando con bitcoin : %.7f BTC\nd) Precio unitario: $%.2f\n", agencia, pDescuento, pAumento, pBitcoin, pUnitario);
}

int cargaForzada(float precioAero, float precioLatam, float kilometros, float descuento, float aumento, float bitcoin){
	int kay;
	float precioDescuentoAero;
	float precioInteresAero;
	float precioAeroEnBitcoin;
	float precioUnitarioAero;

	float precioDescuentoLatam;
	float precioInteresLatam;
	float precioLatamEnBitcoin;
	float precioUnitarioLatam;

	float diferenciaPrecios;

	printf(" ***Informe con carga forzada de datos***\n\n|Cantidad de Km = %.2fKm|\n|Precio con Aerolíneas = $%.2f| |Precio con Latam = $%.2f|\n", kilometros, precioAero, precioLatam);
	kay=hacerCalculos(precioAero, precioLatam, kilometros, bitcoin, &precioDescuentoAero, descuento, &precioInteresAero, aumento, &precioAeroEnBitcoin, &precioUnitarioAero, &precioDescuentoLatam, &precioInteresLatam, &precioLatamEnBitcoin, &precioUnitarioLatam, &diferenciaPrecios);

	mostrarResultado("Latam", precioDescuentoLatam, precioInteresLatam, precioLatamEnBitcoin, precioUnitarioLatam);
	mostrarResultado("Aerolíneas", precioDescuentoAero, precioInteresAero, precioAeroEnBitcoin, precioUnitarioAero);
	printf("\nLa diferencia de precio es : $%.2f", diferenciaPrecios);
	return kay;
}

void confirmarSalida(char* p){
    char confirma;

    while(confirma!= 's' && confirma!= 'n'){

		printf("¿Confirma salida?-('s'= si / 'n'= no): ");
		fflush(stdin);
		scanf("%c", &confirma);
		confirma=tolower(confirma);
    }
    *p = confirma;
}
