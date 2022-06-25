/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "typePassenger.h"
#include "utn.h"

Passenger* Passenger_new(){
	Passenger* unPasajero;
	unPasajero = (Passenger*) malloc(sizeof(Passenger));

	return unPasajero;
}
Passenger* Passenger_newParametros( char* idStr,char* nombreStr, char* apellidoStr,char* precioStr,
									char* codigoVueloStr, int tipoPasajeroStr, char* estadoVuelo){
	Passenger* unPasajero;
	unPasajero = Passenger_new();


	Passenger_setId(unPasajero,atoi(idStr));
	Passenger_setNombre(unPasajero,nombreStr);
	Passenger_setApellido(unPasajero, apellidoStr);
	Passenger_setTipoPasajero(unPasajero, tipoPasajeroStr);
	Passenger_setCodigoVuelo(unPasajero, codigoVueloStr);
	Passenger_setPrecio(unPasajero, atof(precioStr));
	Passenger_setEstadoVuelo(unPasajero, estadoVuelo);

	return unPasajero;
}
int Passenger_delete(Passenger* this){
	int retorno = -1;

	if( this != NULL){
	free(this);
	retorno = 0;
	}
	return retorno;
}
int Passenger_setId(Passenger* this,int id){
	int retorno=-1;
	if(this != NULL && id >= 0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id){
	int retorno=-1;
	if(this != NULL && id >= 0){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno=-1;
	if(this != NULL && apellido != NULL){
		strcpy(this->apellido,apellido);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno=-1;
	if(this != NULL && apellido != NULL){
		strcpy(apellido,this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno=-1;
	if(this != NULL && tipoPasajero >= 0){
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int retorno=-1;
	if(this != NULL && tipoPasajero >= 0){
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno=-1;
	if(this != NULL && precio >= 0){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno=-1;
	if(this != NULL && precio >= 0){
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo){
	int retorno=-1;
	if(this != NULL && estadoVuelo != NULL){
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo){
	int retorno=-1;
	if(this != NULL && estadoVuelo != NULL){
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_printOne(Passenger* unPasajero){

	typePassenger Pasajero[3];
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char typePassenger[50];
	char codigoVuelo[20];
	char estadoVuelo[20];
	int retorno=-1;

	typePassenger_hardCode(Pasajero);
	if(unPasajero != NULL && Passenger_getId(unPasajero,&id) == 0 && Passenger_getNombre(unPasajero,nombre) == 0 &&
	Passenger_getApellido(unPasajero, apellido) == 0 && Passenger_getTipoPasajero(unPasajero, &tipoPasajero) == 0 &&
	Passenger_getCodigoVuelo(unPasajero, codigoVuelo) == 0 && Passenger_getPrecio(unPasajero, &precio) == 0 && Passenger_getEstadoVuelo(unPasajero, estadoVuelo)==0){

		typePassenger_getTypePassenger(Pasajero, typePassenger, tipoPasajero);
		printf("%4d %10s %10s %10.2f %10s %10s %15s\n",id,nombre,apellido,precio,typePassenger,codigoVuelo,estadoVuelo);
		retorno = 0;

	}
	return retorno;
}
Passenger* Passenger_dataIn(char* id){

	Passenger* pAuxiliar;
	char nombre[100];
	char apellido[100];
	int tipoPasajero;
	float precio;
	char price[100];
	char codigoVuelo[100];
	char estadoVuelo[100];


	if(id != NULL && utn_getNombre(nombre, 100, "Ingrese nombre: ", "\nError. Ingrese nombre\n", 10) == 0 &&
		utn_getNombre(apellido, 100, "\nIngrese apellido: \n", "\nError. Ingrese apellido\n", 10) == 0 &&
		utn_getNumero(&tipoPasajero, "\nIngrese tipo de pasajero: \n1- EconomyClass.\n2- FirstClass.\n3- ExecutiveClass", "\nError. Ingrese un numero entre las opciones", 1,3, 5)== 0 &&
		utn_getNumeroFlotante(&precio, "\nIngrese precio: ", "\nError. Ingrese un numero valido.", 0.1, 5)== 0 &&
		utn_getFlyCode(codigoVuelo,20, "Ingrese codigo de vuelo: \n BA2491A  \n IB0800A  \n MM0987B \n GU2345F \n FR5678G \n TU6789B\n", "\nError. Ingrese un codigo de vuelo valido.", 5)== 0&&
		Passenger_setEstadoVueloSegunCodigo(estadoVuelo, codigoVuelo)== 0){
		sprintf(price,"%f",precio);
		pAuxiliar = Passenger_newParametros(id, nombre, apellido, price, codigoVuelo, tipoPasajero, estadoVuelo);
	}
	else{
		pAuxiliar = NULL;
	}
	return pAuxiliar;
}

int Passenger_setTypePassenger(char* typePassenger, int* tipoPasajero){
	int retorno=-1;
	if(typePassenger != NULL && tipoPasajero > 0){
		if(strcmp("EconomyClass",typePassenger) == 0){
			*tipoPasajero = 1;
			retorno = 0;
		}
		else{
			if(strcmp("FirstClass",typePassenger) == 0){
				*tipoPasajero = 2;
				retorno = 0;
			}
			else{
				if(strcmp("ExecutiveClass",typePassenger) == 0){
					*tipoPasajero = 3;
					retorno = 0;
				}
				else{
					*tipoPasajero = 4;
				}
			}
		}
	}
	return retorno;

}
int Passenger_setEstadoVueloSegunCodigo(char* estadoVuelo, char* codigoVuelo){
	int retorno=-1;
	if(estadoVuelo != NULL && codigoVuelo != NULL){
		if(strcmp("BA2491A",codigoVuelo) == 0 || strcmp("IB0800A",codigoVuelo) == 0 || strcmp("TU6789B",codigoVuelo) == 0 ){
			strcpy(estadoVuelo, "Aterrizado");
			retorno = 0;
		}
		else{
			if(strcmp("MM0987B",codigoVuelo) == 0 || strcmp("FR5678G",codigoVuelo) == 0){
				strcpy(estadoVuelo, "En Horario");
				retorno = 0;
			}
			else{
				if(strcmp("GU2345F",codigoVuelo) == 0){
					strcpy(estadoVuelo, "En Vuelo");
					retorno = 0;
				}
				else{
					if(strcmp("HY4567D",codigoVuelo) == 0 || strcmp("BR3456J",codigoVuelo) == 0){
						strcpy(estadoVuelo, "Demorado");
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}
int comparaId(void* pPasajeroA ,void* pPasajeroB){

	int id_A;
	int id_B;
	Passenger_getId((Passenger*)pPasajeroA, &id_A);
	Passenger_getId((Passenger*)pPasajeroB, &id_B);
	if(id_A > id_B){
		return 1;
	}
	if(id_A < id_B){
		return -1;
	}
	return 0;

}
int comparaPrecio(void* pPasajeroA ,void* pPasajeroB){

	float precio_A;
	float precio_B;
	Passenger_getPrecio((Passenger*)pPasajeroA, &precio_A);
	Passenger_getPrecio((Passenger*)pPasajeroB, &precio_B);
	if(precio_A > precio_B){
		return 1;
	}
	if(precio_A < precio_B){
		return -1;
	}
	return 0;

}
int comparaTipoPasajero(void* pPasajeroA ,void* pPasajeroB){

	int tipoPasajero_A;
	int tipoPasajero_B;
	Passenger_getTipoPasajero((Passenger*)pPasajeroA, &tipoPasajero_A);
	Passenger_getTipoPasajero((Passenger*)pPasajeroB, &tipoPasajero_B);
	if(tipoPasajero_A > tipoPasajero_B){
		return 1;
	}
	if(tipoPasajero_A < tipoPasajero_B){
		return -1;
	}
	return 0;

}
int comparaApellido(void* pPasajeroA ,void* pPasajeroB){

	char apellido_A[51];
	char apellido_B[51];
	Passenger_getApellido((Passenger*)pPasajeroA, apellido_A);
	Passenger_getApellido((Passenger*)pPasajeroB, apellido_B);
	if(strcmp(apellido_A,apellido_B)== 1){
		return 1;
	}
	if(strcmp(apellido_A,apellido_B)== -1){
		return -1;
	}
	return 0;

}
