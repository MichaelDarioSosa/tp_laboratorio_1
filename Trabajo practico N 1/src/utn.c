/*
 * utn.c
 *
 *  Created on: 13 abr. 2022
 *      Author: micha
 */

#include <stdio.h>
#include <stdlib.h>

float incrementoPorcentual(float valor, float incremento){
	float resultado;

	resultado = valor + (valor * incremento);

	return resultado;
}
float decrementoPorcentual(float valor, float decremento){
	float resultado;

	resultado = valor - (valor * decremento);

	return resultado;
}
float pesoBtc (float valorEnPesos, float valorDelBtc){
	float resultado;

	resultado = valorEnPesos * 1 / valorDelBtc ;

	return resultado;
}

float precioKm (float valorDelVuelo, int kilometros){
	float resultado;

	resultado = valorDelVuelo / kilometros;

	return resultado;
}
float diferencia (float valor1, float valor2){
	float resultado;
	float valorPositivo;

	resultado = valor1 - valor2 ;
	if(resultado < 0){
		valorPositivo = resultado * (-1);
		resultado = valorPositivo;
	}

	return resultado;
}


