/*
 * typePassenger.h
 *
 *  Created on: 14 jun. 2022
 *      Author: micha
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct
{
	int codigo;
	char descripcion[50];

}typePassenger;
/// Hardcodea los datos de la estructura typePassenger
/// @param this puntero al estructura
/// @return Retorna 0 (EXITO) o -1 (ERROR)
int typePassenger_hardCode(typePassenger* this);
/// Actualiza el parametro "Codigo" de la estructura en el indice indicado
/// @param this Puntero a estructura
/// @param index indice
/// @param codigo Nuevo valor a actualizar
/// @return Retorna 0 (EXITO) o -1 (ERROR)
int typePassenger_setCode(typePassenger* this,int index, int codigo);
/// Devulve el parametro "Codigo" de la estructura en el indice indicado
/// @param this Puntero a estructura
/// @param index indice
/// @param codigo puntero al valor del parametro
/// @return Retorna 0 (EXITO) o -1 (ERROR)
int typePassenger_getCode(typePassenger* this,int index,int* codigo);
/// Actualiza el parametro "Descripcion" de la estructura en el indice indicado
/// @param this Puntero a estructura
/// @param index indice
/// @param codigo puntero al valor del parametro
/// @return Retorna 0 (EXITO) o -1 (ERROR)L
int typePassenger_setDescripcion(typePassenger* this,int index,char* descripcion);
/// Devulve el parametro "Descripcion" de la estructura en el indice indicado
/// @param this Puntero a estructura
/// @param index indice
/// @param codigo puntero del valor del parametro
/// @return Retorna 0 (EXITO) o -1 (ERROR)
int typePassenger_getDescripcion(typePassenger* this,int index,char* descripcion);
/// Utiliza el valor de intPasajero como FK y devulve la descricion
/// @param this Puntero a estructura
/// @param charPassenger devulve descripcion del tipo del pasajero
/// @param intPasajero valor int de codigo FK
/// @return Retorna 0 (EXITO) o -1 (ERROR)
int typePassenger_getTypePassenger(typePassenger* this, char* charPassenger, int intPasajero);
#endif /* TYPEPASSENGER_H_ */
