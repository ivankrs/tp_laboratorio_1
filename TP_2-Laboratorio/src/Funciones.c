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
	for(i=0;i<65;i++)
	{
		printf("~=");
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
float ingresoFloat(char* msj, char* msjError, int rangoBajo, int rangoAlto){

	float numero;
	if(msj!=NULL && msjError!=NULL && (rangoBajo < rangoAlto)){
		printf("%s", msj);
		scanf("%f", &numero);

		while(validarRangoFlotante(numero, rangoBajo, rangoAlto)!=1){
			printf("%s", msjError);
			scanf("%f", &numero);
		}
	}
	return numero;
}
int ingresarInt(char* msj, char* msjError, int rangoBajo, int rangoAlto){
	int numero;
	if(msj!=NULL && msjError!= NULL && rangoBajo < rangoAlto){
		printf("%s",msj);
		scanf("%d", &numero);

		while(validarRangoEntero(numero, rangoBajo, rangoAlto)!=1){
			printf("%s", msjError);
			scanf("%d", &numero);
		}
	}
	return numero;
}
int ingresarString(char pString[], char* msj, char* msjError, int rangoBajo, int rangoAlto){
	int kay=0;
	char auxCad[100];

	if(pString != NULL && rangoBajo < rangoAlto){
		printf("%s", msj);
		fflush(stdin);
		gets(auxCad);

		while(strlen(auxCad) >= rangoAlto || strlen(auxCad) <= rangoBajo)
		{
			printf("%s",msjError);
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
void swapEnteros(int* n1,int* n2){
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}
void swapFlotantes(float* n1,float* n2){
    float aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}
void swapString (char* n1,char* n2){
    char aux[100];
    strcpy(aux,n1);
    strcpy(n1,n2);
    strcpy(n2,aux);
}


void confirmarSalida(char* p){
    char confirma;

    while(confirma!= 's' && confirma!= 'n'){

		printf("\n¿Confirma salida?-('s'= si / 'n'= no): ");
		fflush(stdin);
		scanf("%c", &confirma);
		confirma=tolower(confirma);
    }
    *p = confirma;
}
