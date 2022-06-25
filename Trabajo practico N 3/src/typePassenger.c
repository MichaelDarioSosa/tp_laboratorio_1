/*
 * typePassenger.c
 *
 *  Created on: 14 jun. 2022
 *      Author: micha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "typePassenger.h"
#include "utn.h"

int typePassenger_hardCode(typePassenger* this){
	int codigo[3]={1,2,3};
	char descripcion[3][50]={"EconomyClass","FirstClass","ExecutiveClass"};
	int i;
	int retorno=-1;
	for(i=0;i<4;i++){
		typePassenger_setCode(this,i,codigo[i]);
		typePassenger_setDescripcion(this,i,descripcion[i]);
		retorno = 0;
	}
	return retorno;
}

int typePassenger_setCode(typePassenger* this,int index, int codigo){
	int retorno=-1;
	if(this != NULL && codigo >= 0 && index >= 0){
		this[index].codigo = codigo;
		retorno = 0;
	}
	return retorno;
}
int typePassenger_getCode(typePassenger* this,int index, int* codigo){
	int retorno=-1;
	if(this != NULL &&  index >= 0){
		*codigo = this[index].codigo;
		retorno = 0;
	}
	return retorno;
}
int typePassenger_setDescripcion(typePassenger* this,int index, char* descripcion){
	int retorno=-1;
	if(this != NULL && descripcion != NULL &&  index >= 0){
		strcpy(this[index].descripcion, descripcion);
		retorno = 0;
	}
	return retorno;
}
int typePassenger_getDescripcion(typePassenger* this, int index, char* descripcion){
	int retorno=-1;
	if(this != NULL && descripcion != NULL &&  index >= 0){
		strcpy(descripcion,this[index].descripcion);
		retorno = 0;
	}
	return retorno;
}
int typePassenger_getTypePassenger(typePassenger* this, char* charPassenger, int intPasajero){
	int bufferCodigo;
	int retorno=-1;
	int i;
	if((intPasajero > 0 && intPasajero < 4) && charPassenger != NULL && this != NULL ){
		for(i=0;i<4;i++){
			typePassenger_getCode(this,i,&bufferCodigo);
			if(intPasajero == bufferCodigo){
				typePassenger_getDescripcion(this,i, charPassenger);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
