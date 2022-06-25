#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "typePassenger.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo abierto.
 * \param pArrayListPassenger LinkedList* puntero a la lista dinamica ya creada.
 * \return int Retorna 0 (EXITO o -1 (ERROR)
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	char id[100];
	char nombre[100];
	char apellido[100];
	char estadoVuelo[100];
	char typePassenger[100];
	int tipoPasajero;
	char precio[100];
	char codigoVuelo[100];
	int retorno=0;
	int i=0;

	if(pFile != NULL && pArrayListPassenger != NULL){
		do{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,typePassenger,estadoVuelo);
			Passenger_setTypePassenger(typePassenger, &tipoPasajero);
			unPasajero = Passenger_newParametros(id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
			if(unPasajero != NULL){
				if(ll_add(pArrayListPassenger, unPasajero) == 0){
					retorno = 0;
				}
			}
			else{
				printf("No se pudo leer el archivo");
				retorno = -1;
			}
			i++;
		}while(feof(pFile)== 0);
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo bin.bin (modo binario).
 *
 * \param path char* puntero al archivo abierto.
 * \param pArrayListPassenger LinkedList* puntero a la lista dinamica ya creada.
 * \return int Retorna 0 (EXITO o -1 (ERROR)
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* p;

	int retorno=-1;
	int cant;

	if(pFile != NULL && pArrayListPassenger != NULL){

		do{
			p = Passenger_new();
			cant = fread(p,sizeof(Passenger),1,pFile);
			if(cant == 1){
				ll_add(pArrayListPassenger, p );
				retorno = 0;
			}
		}while(feof(pFile)== 0);
	}
    return retorno;
}
/** \brief Guarda los datos de los pasajeros desde la lista dinamica a data.csv (modo texto).
 *
 * \param path char* puntero al archivo abierto.
 * \param pArrayListPassenger LinkedList* puntero a la lista dinamica ya creada.
 * \return int Retorna 0 (EXITO o -1 (ERROR)
 *
 */
int parser_PassengerSaveFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger *p;
	typePassenger Pasajero[3];
	int retorno=-1;
	int i;
	int len;
	int id;
	char nombre[100];
	char apellido[100];
	char estadoVuelo[100];
	char typePassenger[100];
	int tipoPasajero;
	float precio;
	char codigoVuelo[100];

	typePassenger_hardCode(Pasajero);
	len = ll_len(pArrayListPassenger);
	if(pFile != NULL && pArrayListPassenger != NULL ){
		for(i=0;i<len;i++){
			p=(Passenger*) ll_get(pArrayListPassenger, i);
			if(Passenger_getId(p,&id) == 0 && Passenger_getNombre(p,nombre) == 0 &&
					Passenger_getApellido(p, apellido) == 0 && Passenger_getTipoPasajero(p, &tipoPasajero) == 0 &&
					Passenger_getCodigoVuelo(p, codigoVuelo) == 0 && Passenger_getPrecio(p, &precio)==0 && Passenger_setEstadoVueloSegunCodigo(estadoVuelo, codigoVuelo)== 0){
				typePassenger_getTypePassenger(Pasajero, typePassenger, tipoPasajero);
				fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,typePassenger,estadoVuelo);
			}
		}
		retorno = 0;
	}
    return retorno;
}
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char* puntero al archivo abierto.
 * \param pArrayListPassenger LinkedList* puntero a la lista dinamica ya creada.
 * \return int Retorna 0 (EXITO o -1 (ERROR)
 *
 */
int parser_PassengerSaveFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger *p;
	int retorno=-1;
	int i;
	int len;


	if(pFile != NULL && pArrayListPassenger != NULL ){
		len = ll_len(pArrayListPassenger);
		for(i=0;i<len;i++){
			p =(Passenger*) ll_get(pArrayListPassenger, i);
			if(p != NULL){
			fwrite(p,sizeof(Passenger),1,pFile);
			}
		}
	}
    return retorno;
}
