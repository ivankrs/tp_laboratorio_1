/*
 * Funciones.c
 *
 *  Created on: 19 abr. 2022
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
int menu(char* msj){
    int opcion;

    //system("cls");
    lineas();
    printf("%s",msj);
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
			printf("¡El valor ingresado no es valido!¡REINTENTE!: ");
			scanf("%f", pFloat);
		}
		kay=1;
	}

	return kay;
}
int ingresarInt(char* mensaje){
	int numero;

	printf("%s",mensaje);
	scanf("%d", &numero);
	while(validarRangoEntero(numero, 1, 2000)!=1){
		printf("\n¡Error! Numeros validos de 1 a 2000.\n>Reingrese: ");
		scanf("%d", &numero);
	}
	return numero;
}
int ingresarString(char pString[], int len, char* msj){
	int kay=0;
	char auxCad[100];

	if(pString != NULL && len > 0){
		printf("%s", msj);
		fflush(stdin);
		gets(auxCad);

		while(strlen(auxCad) >= len)
		{
			printf("¡Error! Es demasiado largo, deben ser menos de %d caracteres.\n>Reingrese: ", len);
			fflush(stdin);
			gets(auxCad);
		}
		strcpy(pString, auxCad);
		kay=1;
	}


	return kay;
}

int validarRangoEntero(int valor, int inferior, int superior){
    int esValido = 0;
    if(valor >= inferior && valor <= superior){
        esValido = 1;
    }
    return esValido;
}

int validarRangoFlotante(float valor, float inferior, float superior){
    int esValido = 0;
    if(valor >= inferior && valor <= superior){
        esValido = 1;
    }
    return esValido;
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
