#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "typePassenger.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListPassenger LinkedList* puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger) // validar no se puede entrar 2 veces
{
	FILE* pArchivo;
	int retorno=-1;

	if(path != NULL && pArrayListPassenger != NULL){
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL){

			parser_PassengerFromText(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
			retorno = 0;
			utn_printOk();
		}
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*  Nombre del archivo
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int retorno=-1;

	if(path != NULL && pArrayListPassenger != NULL){
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL){

			if(parser_PassengerFromBinary(pArchivo, pArrayListPassenger)){
				retorno = 0;
				utn_printOk();
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{

	int retorno=-1;
	Passenger* pAuxiliar;
	int lastId;
	char id[1000];

	lastId = controller_initId();
	if(lastId != -1){
		sprintf(id,"%d",lastId);
		lastId++;
		controller_outId(lastId);
	}
	pAuxiliar = Passenger_dataIn(id);
	if(pAuxiliar != NULL && ll_add(pArrayListPassenger, pAuxiliar)== 0){
		utn_printOk();
		retorno = 0;
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	Passenger* pAux;
	int retorno=-1;
	char idStr[1000];
	int retId;
	int id;
	int i;

	if( pArrayListPassenger != NULL && utn_getNumero(&id, "\nIngrese ID a modificar: ", "\nError. dato invalido\n", 0, 99999,5)== 0){
		unPasajero = Passenger_new();
		for(i=0;i<ll_len(pArrayListPassenger);i++){
			pAux = ll_get(pArrayListPassenger, i);
			Passenger_getId(pAux, &retId);
			if(id == retId){
				sprintf(idStr,"%d",id);
				unPasajero = Passenger_dataIn(idStr);
				if(unPasajero != NULL){
					ll_set(pArrayListPassenger, i, unPasajero);
					utn_printOk();
					retorno = 0;
					break;
				}
			}
		}
		if(retorno == -1){
			printf("\nNo se encontro el ID");
		}
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pAux;
	int retorno=-1;
	int id_A;
	int id_B;
	int i;

	if( pArrayListPassenger != NULL && utn_getNumero(&id_A, "\nIngrese ID a remover: ", "Error. dato invalido", 0, 999999,5)== 0){
		for(i=0;i<ll_len(pArrayListPassenger);i++){
			pAux = ll_get(pArrayListPassenger, i);
			Passenger_getId(pAux, &id_B);
			if(id_A == id_B && ll_remove(pArrayListPassenger, i) == 0){
				retorno = 0;
				utn_printOk();
				break;
			}
		}
		if(retorno == -1){
			printf("\nNo se encontro el ID");
		}
	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* p;
	int i;
	int len;
	len = ll_len(pArrayListPassenger);
	for(i=0;i<len;i++){
		p=(Passenger*) ll_get(pArrayListPassenger, i);
		Passenger_printOne(p);
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	int menorMayor;
	if(pArrayListPassenger != NULL && utn_getNumero(&opcion,"\nIngrese criterio de ordenamiento: \n1- ID"
															"\n2- Tipo de pasajero"
															"\n3- Precio"
															"\n4- Apellido\n", "\n1Error. Ingrese una opcion disponible\n1", 1,4, 5) == 0 &&
								 utn_getNumero(&menorMayor, "\nIngrese orden: \n0- Mayor a menor.\n1- Menor a mayor.\n", "\n1Error. Ingrese una opcion disponible\n1", 0, 1, 5)== 0){
		switch(opcion){
		case 1:
			if(ll_sort(pArrayListPassenger, comparaId, menorMayor) == 0){
				utn_printOk();
			}
			break;
		case 2:
			if(ll_sort(pArrayListPassenger, comparaTipoPasajero, menorMayor) == 0){
				utn_printOk();
			}
			break;
		case 3:
			if(ll_sort(pArrayListPassenger, comparaPrecio, menorMayor) == 0){
				utn_printOk();
			}
			break;
		case 4:
			if(ll_sort(pArrayListPassenger, comparaApellido, menorMayor) == 0){
				utn_printOk();
			}
			break;
		case 5:
			if(ll_sort(pArrayListPassenger, comparaTipoPasajero, menorMayor) == 0){
				utn_printOk();
			}
			break;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int retorno=-1;

	if(path != NULL && pArrayListPassenger != NULL){
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL){

			parser_PassengerSaveFromText(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
			retorno = 0;
			utn_printOk();
		}



	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListPassenger LinkedList*  puntero a la lista
 * \return int Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pArchivo;
	int retorno=-1;

	if(path != NULL && pArrayListPassenger != NULL){
		pArchivo = fopen(path,"wb");
		if(pArchivo != NULL){

			parser_PassengerSaveFromBinary(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
			retorno = 0;
		}



	}
	return retorno;
}
/// Abre un archivo con los datos del ultimo Id, toma el dato y cierra la carpeta
/// @return Retorna el valor del ultimo id o -1 (ERROR)
int controller_initId(){

	FILE *pArchivo;
	char lastid[10000];
	int retorno=-1;
	pArchivo = fopen("id.csv","r");

	if(pArchivo != NULL){
		fscanf(pArchivo,"%s",lastid);
		retorno = atoi(lastid);
	}
	fclose(pArchivo);
	return retorno;
}
/// Abre un archivo con los datos del ultimo Id, actualiza el dato y cierra la carpeta
/// @return int Retorna 0 (EXITO) o -1 (ERROR)
int controller_outId(int lastId){
	FILE *pArchivo;
	char id[10000];
	int longi;
	int cant;
	int retorno=-1;
	pArchivo = fopen("id.csv","w");
	if(pArchivo != NULL && lastId > 0){
		sprintf(id,"%d",lastId);
		longi = strlen(id);
		cant = fwrite( id , sizeof(char) , longi , pArchivo );
		if(cant == longi){
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}
