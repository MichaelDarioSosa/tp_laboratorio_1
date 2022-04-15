/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main(void){
	setbuf(stdout, NULL);
	int opcion;
	int x=0;
	float z=0;
	float y=0;
	float descuentoDebitoAerolineas;
	float descuentoDebitoLatam;
	float incrementoCreditoAerolineas;
	float IncrementoCreditoLatam;
	float valorAerolineasBtc;
	float valorLatamBtc;
	float precioKmAerolineas;
	float precioKmLatam;
	float diferenciaDePrecio;
	do{
		printf("1. Ingresar Kilómetros:(km= %d).\n2. Ingresar Precio de Vuelos:(Aerolíneas= %.2f, Latam= %.2f).\n3. Calcular todos los costos.\n4. Informar Resultados.\n5. Carga forzada de datos.\n6. Salir\n\n",x,y,z);
		scanf("%d",&opcion);
			switch(opcion){
				case 1:
					printf("Ingresar Kilómetros: ");
					scanf("%d",&x);
					break;
				case 2:
					printf("Precio vuelo Aerolíneas: ");
					scanf("%f",&y);
					printf("Precio vuelo Latam: ");
					scanf("%f",&z);
					break;
				case 3:
					if(x != 0 && z != 0 && y != 0){
						printf("a) Tarjeta de débito (descuento 10)\nb) Tarjeta de crédito (interés 25)\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nd) Mostrar precio por km (precio unitario)\ne) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n\n");
						descuentoDebitoAerolineas = decrementoPorcentual(y,0.1);
						descuentoDebitoLatam = decrementoPorcentual(z,0.1);
						incrementoCreditoAerolineas = incrementoPorcentual(y,0.25);
						IncrementoCreditoLatam = incrementoPorcentual(z,0.25);
						valorAerolineasBtc = pesoBtc (z,4606954.55);
						valorLatamBtc = pesoBtc (y,4606954.55);
						precioKmAerolineas = precioKm (y,x);
						precioKmLatam = precioKm (z,x);
						diferenciaDePrecio = diferencia (z,y);
					}
					else{
						printf("Error, no se ingresaron todos los datos.");
					}
					break;
				case 4:
					printf("KMs Ingresados: %d\n\nAerolíneas: %.2f\na) Precio con tarjeta de débito: %.2f\nb) Precio con tarjeta de crédito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f\n\nLatam: %.2f\na) Precio con tarjeta de débito: %.2f\nb) Precio con tarjeta de crédito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f\n\nLa diferencia de precio es : %.2f\n\n ",x,y,descuentoDebitoAerolineas,incrementoCreditoAerolineas,valorAerolineasBtc,precioKmAerolineas,z,descuentoDebitoLatam,IncrementoCreditoLatam,valorLatamBtc,precioKmLatam,diferenciaDePrecio);
					break;
				case 5:
					x = 7090;
					y = 162965;
					z = 159339;
					descuentoDebitoAerolineas = decrementoPorcentual(y,0.1);
					descuentoDebitoLatam = decrementoPorcentual(z,0.1);
					incrementoCreditoAerolineas = incrementoPorcentual(y,0.25);
					IncrementoCreditoLatam = incrementoPorcentual(z,0.25);
					valorAerolineasBtc = pesoBtc (z,4606954.55);
					valorLatamBtc = pesoBtc (y,4606954.55);
					precioKmAerolineas = precioKm (y,x);
					precioKmLatam = precioKm (z,x);
					diferenciaDePrecio = diferencia (z,y);
					printf("KMs Ingresados: %d\n\nAerolíneas: %.2f\na) Precio con tarjeta de débito: %.2f\nb) Precio con tarjeta de crédito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f\n\nLatam: %.2f\na) Precio con tarjeta de débito: %.2f\nb) Precio con tarjeta de crédito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f\n\nLa diferencia de precio es : %.2f\n ",x,y,descuentoDebitoAerolineas,incrementoCreditoAerolineas,valorAerolineasBtc,precioKmAerolineas,z,descuentoDebitoLatam,IncrementoCreditoLatam,valorLatamBtc,precioKmLatam,diferenciaDePrecio);
					opcion = 6;
					break;
				case 6:
					printf("Usted ah salido.");
					break;
				default:
					printf("Error, Ingrese un opcion valida");
			}
	}while( opcion != 6 );
	return 0;
}
