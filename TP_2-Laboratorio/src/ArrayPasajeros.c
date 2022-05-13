/*
 * ArrayPasajeros.c
 *
 *  Created on: 26 abr. 2022
 *      Author: ivank
 */

#include "ArrayPasajeros.h"
#include "Funciones.h"

void isEmpty(ePasajero vec[], int tam){

	if(vec != NULL && tam > 0){
		for(int i=0; i < tam; i++)
		{
			vec[i].isEmpty=0;
		}
	}
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

		vec[id].precio = ingresoFloat("Ingrese el precio: ","\n¡Error! Numeros validos de 1 a un millon.\n>Reingrese: ", 1, 1000000);

		ingresarString(vec[id].codigoVuelo,"Ingrese el codigo de vuelo: ", "\n¡Codigo de vuelo demasiado largo o corto! >Reingrese codigo de vuelo: ", 0, 5);

		vec[id].tipoPasajero = ingresarInt("Ingrese el tipo de pasajero: ", "\n¡Error! Numeros validos de 1 a 2.\n>Reingrese: ", 1, 2);

		vec[id].statusVuelo = ingresarInt("Ingrese status del vuelo: ", "\n¡Error! Numeros validos de 1 a 2.\n>Reingrese: ", 1, 2);


		vec[id].isEmpty=1;

        todoOk = 1;
    }
    return todoOk;
}
int modificarUnPasajero(ePasajero vec[], int  idX){
	int kay=0;
	int id=idX-1;
	char confirma='x';

	if(vec != NULL && id>=0 && vec[id].isEmpty==1){
		mostrarUnPasajero(vec, id);
		 while(confirma!= 's' && confirma!= 'n'){
			 	printf("\n\n");
				printf("\n¿Confirma modificar pasajero?-('s'= si / 'n'= no): ");
				fflush(stdin);
				scanf("%c", &confirma);
				confirma=tolower(confirma);
			}
			if(confirma=='s'){
				switch(menuModificaUnPasajero(vec, idX)){
				case 1:
					ingresarString(vec[id].nombre, "Ingrese el nombre del pasajero: ", "\n¡Nombre demasiado largo o corto! >Reingrese nombre: ", 0, 51);
					break;

				case 2:
					ingresarString(vec[id].apellido, "Ingrese el apellido del pasajero: ", "\n¡Apellido demasiado largo o corto! >Reingrese apellido: ", 0, 51);
					break;
				case 3:
					vec[id].precio=ingresoFloat("Ingrese el precio: ","\n¡Error! Numeros validos de 1 a un millon.\n>Reingrese: ", 1, 1000000);
					break;
				case 4:
					ingresarString(vec[id].codigoVuelo,"Ingrese el codigo de vuelo: ", "\n¡Codigo de vuelo demasiado largo o corto! >Reingrese codigo de vuelo: ", 0, 5);
					break;
				case 5:
					vec[id].tipoPasajero = ingresarInt("Ingrese el tipo de pasajero: ", "\n¡Error! Numeros validos de 1 a 2.\n>Reingrese: ", 1, 2);
					break;
				case 6:
					vec[id].statusVuelo = ingresarInt("Ingrese status del vuelo: ", "\n¡Error! Numeros validos de 1 a 2.\n>Reingrese: ", 1, 2);
					break;
				case 7:
					cargarUnPasajero(vec, id);
					break;

				default :
					printf(" X ¡Opcion invalida! X");
					break;
				}

				kay=1;

				printf("\n¡Se ha modificado con exito!\n");
			}
			else{
				printf("\n¡No se ha modificado!");
			}
		}
		else{
			printf("\n¡No hay pasajeros para modificar!");
		}
	return kay;
}
int menuModificaUnPasajero(ePasajero vec[], int  idX){
	int kay=0;
	int id=idX-1;

	if(vec != NULL && id>=0 && vec[id].isEmpty==1){

		kay= menu("\n *** Menu Modificar Un Pasajero ***\n\n"
				"1. Modificar Nombre\n"
				"2. Modificar Apellido\n"
				"3. Modificar Precio\n"
				"4. Modificar Tipo Pasajero\n"
				"5. Modificar Codigo de Vuelo\n"
				"6. Modificar Status de Vuelo\n"
				"7. Modificar Todo\n >");

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
			printf("\n\n");
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
int mostrarUnPasajero(ePasajero vec[], int id){
	int kay=0;
	if(vec!=NULL && id>=0){
		  printf(" _________________________________________________________________________________________________________________________");
				printf("\n| Id   |     Nombre    |     Apellido     |      Precio     |    Codigo de vuelo  |  Tipo de pasajero  |  Status del vuelo|\n");
				  printf("|------|---------------|------------------|-----------------|---------------------|--------------------|------------------|\n");
				  printf("|%04d  |  %10s   |    %10s    |      $%6.2f    |          %4s       |         %d          |         %d        |\n", vec[id].id, vec[id].nombre, vec[id].apellido, vec[id].precio, vec[id].codigoVuelo, vec[id].tipoPasajero, vec[id].statusVuelo);
				  printf("|______|_______________|__________________|_________________|_____________________|____________________|__________________|");
		kay=1;
		printf("\n");
	}


	return kay;

}
int mostrarListaPasajeros(ePasajero vec[], int tam){
	int kay=0;
	int i;
	if(vec!=NULL && tam>0){
		  printf(" _________________________________________________________________________________________________________________________");
		printf("\n| Id   |     Nombre    |     Apellido     |      Precio     |    Codigo de vuelo  |  Tipo de pasajero  |  Status del vuelo|\n");
		  printf("|------|---------------|------------------|-----------------|---------------------|--------------------|------------------|\n");

		for(i=0 ; i<tam; i++){
			if(vec[i].isEmpty ==1){
		  printf("|%04d  |  %10s   |    %10s    |      $%6.2f    |          %4s       |         %d          |         %d        |\n", vec[i].id, vec[i].nombre, vec[i].apellido, vec[i].precio, vec[i].codigoVuelo, vec[i].tipoPasajero, vec[i].statusVuelo);
			}
		}
		  printf("|______|_______________|__________________|_________________|_____________________|____________________|__________________|");
			kay=1;
			printf("\n");

	}
	return kay;
}
int ordenarListaPasajerosPorApellido(ePasajero vec[], int tam){
	int kay=0;

	if(vec!=NULL && tam>0){
		for(int i = 0 ; i < tam - 1; i++){

			for(int j = i + 1 ;j < tam ; j++){

				if(((strcmp(vec[j].apellido, vec[i].apellido)) < 0 )|| (( strcmp(vec[j].apellido, vec[i].apellido) == 0 ) && (vec[j].tipoPasajero < vec[i].tipoPasajero))){

					swapEnteros(&vec[j].id, &vec[i].id);
					swapString(vec[j].nombre, vec[i].nombre);
					swapString(vec[j].apellido, vec[i].apellido);
					swapFlotantes(&vec[j].precio, &vec[i].precio);
					swapString(vec[j].codigoVuelo, vec[i].codigoVuelo);
					swapEnteros(&vec[j].tipoPasajero, &vec[i].tipoPasajero);
					swapEnteros(&vec[j].statusVuelo, &vec[i].statusVuelo);
				}
			}
		}

		kay=1;
	}
	return kay;
}
int hacerPromediosPrecios(ePasajero vec[], int tam, float* total, float* promedio, int* cant){
	int kay=0;
	int cantPasajeros=0;
	int cantSobrePromedio;
	cantSobrePromedio=*cant;


	if(vec!=NULL && total!=NULL && promedio!=NULL && cant!=NULL && tam>0){
		for(int i = 0; i < tam; i++){
			if(vec[i].isEmpty == 1){
				*total += vec[i].precio;
				cantPasajeros++;
			}
		}
		*promedio = *total / cantPasajeros;

		for(int i = 0; i < tam; i++){

			if(vec[i].isEmpty == 1 && vec[i].precio > *promedio){

				cantSobrePromedio++;
			}
		}
		*cant=cantSobrePromedio;
		kay=1;
	}
	return kay;
}
int mostraPrecios(ePasajero vec[], int tam){
	int kay=0;
	float totalPrecio=0;
	int cantSobrePromedio=0;
	float promedio;

	if(vec!=NULL && tam>0){

		if(hacerPromediosPrecios(vec, tam, &totalPrecio, &promedio, &cantSobrePromedio)){
			printf("   _____________________________________________________________________");
			printf("\n  |Precio Total  |   Precio Promedio  |  Pasajeros sobre precio promedio|\n");
			printf("  |--------------|--------------------|---------------------------------|\n");
			printf("  |    $%6.2f   |          $%6.2f   |               %3d               |\n",totalPrecio, promedio, cantSobrePromedio);
			printf("  |______________|____________________|_________________________________|");
			kay=1;
			printf("\n");
		}
	}
	return kay;
}
int ordenarListaPasajerosPorCodigo(ePasajero vec[], int tam){
	int kay=0;

	if(vec!=NULL && tam>0){
		for(int i = 0 ; i < tam - 1; i++){

			for(int j = i + 1 ;j < tam ; j++){

				if(((strcmp(vec[j].codigoVuelo, vec[i].codigoVuelo))< 0)|| ((strcmp(vec[j].codigoVuelo, vec[i].codigoVuelo) == 0) && (vec[j].statusVuelo < vec[i].statusVuelo))){

					swapEnteros(&vec[j].id, &vec[i].id);
					swapString(vec[j].nombre, vec[i].nombre);
					swapString(vec[j].apellido, vec[i].apellido);
					swapFlotantes(&vec[j].precio, &vec[i].precio);
					swapString(vec[j].codigoVuelo, vec[i].codigoVuelo);
					swapEnteros(&vec[j].tipoPasajero, &vec[i].tipoPasajero);
					swapEnteros(&vec[j].statusVuelo, &vec[i].statusVuelo);
				}
			}
		}

		kay=1;
	}
	return kay;
}
