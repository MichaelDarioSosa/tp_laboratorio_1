/*
 * utn.h
 *
 *  Created on: 13 abr. 2022
 *      Author: micha
 */

#ifndef UTN_H_
#define UTN_H_
/// La funcion toma un valor y lo incrementa el porcentaje que requiera.
/// @param valor, dato de tipo float que requiera el incremento.
/// @param incremento, dato de tipo float que indica cuanto aumentar expresados en decimal.
/// @return retorna el valor incrementado.
float incrementoPorcentual(float valor, float incremento);
/**
 * La funcion toma un valor y lo decrementa el porcentaje que requiera.
 * @param valor, dato de tipo float que requiera el decremento.
 * @param decremento, dato de tipo float que indica cuanto aumentar expresados en decimal.
 * @return retorna el valor incrementado.
 */
float decrementoPorcentual(float valor, float decremento);

/// realiza la conversion de pesos argentinos a cantidad de bitcoin.
/// @param valorEnPesos, cantidad de pesos.
/// @param valorDelBtc, valor de cotizacion del bitcoin expresados en pesos.
/// @return cantidad de pesos expresados en bitcoin.
float pesoBtc (float valorEnPesos, float valorDelBtc);

/// calcula el valor unitario del kilometro.
/// @param valorDelVuelo, valor del viaje.
/// @param kilometros, distancia del viaje.
/// @return precio por kilometro.
float precioKm (float valorDelVuelo, int kilometros);

/// Solicita dos numeros al usuario y devuelve la diferencia, independientemente el orden siempre devulve un valor positivo)
/// @param valor1, se ingresa un numero
/// @param valor2 se ingresa un numero
/// @return, devuelve el resto positivo
float diferencia (float valor1, float valor2);

#endif /* UTN_H_ */
