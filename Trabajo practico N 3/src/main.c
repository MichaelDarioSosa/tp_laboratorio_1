#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "typePassenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

// el id tiene que ser dinamico, guardar la ultima posicion en un archivo para luego leerlo cuando se inicia

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int flag_A=0;
    int flag_B=0;


    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	utn_getNumero(&option, "\n\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
    			"\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
    			"\n3. Alta de pasajero"
    			"\n4. Modificar datos de pasajero"
    			"\n5. Baja de pasajero"
    			"\n6. Listar pasajeros"
    			"\n7. Ordenar pasajeros"
    			"\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
    			"\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
    			"\n10. Salir\n", "Error, Opcion invalida", 1, 10, 5);
        switch(option)
        {
            case 1:
                if(flag_A == 0){
                	controller_loadFromText("data.csv",listaPasajeros);
                	flag_A = 1;
                }
                else{
                	printf("No se puede cargar dos veces el archivo");
                }
                break;
            case 2:
            	if(flag_A == 0){
            		controller_loadFromBinary("bin.bin" , listaPasajeros);
            		flag_A = 1;
            	}
            	else{
					printf("No se puede cargar dos veces el archivo");
				}
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	if(ll_isEmpty(listaPasajeros) == 0){
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Lista vacia");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaPasajeros) == 0){
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Lista vacia");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaPasajeros) == 0){
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Lista vacia");
            	}
            	break;
            case 7:
            	if(ll_isEmpty(listaPasajeros) == 0){
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Lista vacia");
            	}
            	break;
            case 8:
            case 9:
            	controller_saveAsText("data.csv" , listaPasajeros);
            	controller_saveAsBinary("bin.bin" , listaPasajeros);
            	flag_B = 1;
            	break;
            case 10:
            	if(flag_B == 1){
            		option = 11;
            	}
            	else{
					printf("No se puede Salir sin antes haber guardado el archivo");
				}

            break;
        }
    }while(option != 11);
    ll_deleteLinkedList(listaPasajeros);
    return 0;
}

