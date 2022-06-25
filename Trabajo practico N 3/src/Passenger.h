/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[20];
	char estadoVuelo[20];


}Passenger;
/// Crea un espacio en memoria
/// @return Retorna un puntero al espacio de memoria
Passenger* Passenger_new();
/// Crea un espacio en memoria y carga los datos en el espacio.
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param codigoVueloStr
/// @param tipoPasajeroStr
/// @param estadoVuelo
/// @return Retorna un puntero a la estructura
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr,char* precioStr, char* codigoVueloStr,int tipoPasajeroStr, char* estadoVuelo);
/// Vacia el espacio en memora
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_delete(Passenger* this);

/// Actualiza el valor del parametro ID de la estructura
/// @param this Puntero de la lista
/// @param id valor del id a actualizar
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setId(Passenger* this,int id);
/// Devuelve el valor del parametro ID de la estructura
/// @param this Puntero de la lista
/// @param id valor puntero del id
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_getId(Passenger* this,int* id);

/// Actualiza el valor del parametro Nombre de la estructura
/// @param this Puntero de la lista
/// @param nombre nombre a actualizar
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setNombre(Passenger* this,char* nombre);
/// Devuelve el valor del parametro nombre de la estructura
/// @param this Puntero de la lista
/// @param nombre puntero del parametro nombre de la lista
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_getNombre(Passenger* this,char* nombre);

/// Actualiza el valor del parametro apellido de la estructura
/// @param this Puntero de la lista
/// @param apellido apellido a actualizar
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setApellido(Passenger* this,char* apellido);
/// Devuelve el valor del parametro apellido de la estructura
/// @param this Puntero de la lista
/// @param apellido puntero del parametro apellido de la lista
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_getApellido(Passenger* this,char* apellido);

/// Actualiza el valor del parametro codigoVuelo de la estructura
/// @param this Puntero de la lista
/// @param codigoVuelo codigoVuelo a actualizar
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/// Devuelve el valor del parametro codigoVuelo de la estructura
/// @param this Puntero de la lista
/// @param codigoVuelo puntero del parametro codigoVuelo de la lista
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// Actualiza el valor del parametro tipoPasajero de la estructura
/// @param this Puntero de la lista
/// @param tipoPasajero valor del tipoPasajero a actualizar
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
/// Devuelve el valor del parametro tipoPasajero de la estructura
/// @param this Puntero de la lista
/// @param tipoPasajero valor puntero del tipoPasajero
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// Actualiza el valor del parametro precio de la estructura
/// @param this Puntero de la lista
/// @param precio valor del precio a actualizar
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setPrecio(Passenger* this,float precio);
/// Devuelve el valor del parametro precio de la estructura
/// @param this Puntero de la lista
/// @param precio valor puntero del precio
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_getPrecio(Passenger* this,float* precio);


/// Actualiza el valor del parametro EstadoVuelo de la estructura
/// @param this Puntero de la lista
/// @param EstadoVuelo EstadoVuelo a actualizar
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setEstadoVuelo(Passenger* this,char* EstadoVuelo);
/// Devuelve el valor del parametro EstadoVuelo de la estructura
/// @param this Puntero de la lista
/// @param EstadoVuelo puntero del parametro EstadoVuelo de la lista
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_getEstadoVuelo(Passenger* this,char* EstadoVuelo);

/// Devuelve FK del tipo de pasajero conforme de la descripcion guardada en el archivo
/// @param typePassenger recibe puntero a la descricion
/// @param tipoPasajero devulve 1 si es "EconomyClass"  2 si es "FirstClass" 3 si es "ExecutiveClass"
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setTypePassenger(char* typePassenger, int* tipoPasajero);

/// recibe el codigo de vuelo y devulve el estado
/// @param estadoVuelo estadoVuelo
/// @param codigoVuelo codigoVuelo
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_setEstadoVueloSegunCodigo(char* estadoVuelo, char* codigoVuelo);

/// Imprime todos los datos relacionado con el pasajero
/// @param unPasajero puntero a lista de pasajero
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
int Passenger_printOne(Passenger* unPasajero);

/// Solicita todos los datos correspondiente al usuario, lo verifica y crea un espacio de la estructura, devulve punte al la estructura creada
/// @param id recibe el id que va a tener el pasajero
/// @return Retorna 0 (EXITO) o -1 si Passenger es NULL
Passenger* Passenger_dataIn(char* id);

/// compara los datos del parametro Id de la estructura
/// @param pPasajeroA
/// @param pPasajeroB
/// @return Retorna -1 si es menor 1 si es mayor o 0 si es igual
int comparaId(void* pPasajeroA ,void* pPasajeroB);
/// compara los datos del parametro Precio de la estructura
/// @param pPasajeroA
/// @param pPasajeroB
/// @return Retorna -1 si es menor 1 si es mayor o 0 si es igual
int comparaPrecio(void* pPasajeroA ,void* pPasajeroB);
/// compara los datos del parametro TipoPasajero de la estructura
/// @param pPasajeroA
/// @param pPasajeroB
/// @return Retorna -1 si es menor 1 si es mayor o 0 si es igual
int comparaTipoPasajero(void* pPasajeroA ,void* pPasajeroB);
/// compara los datos del parametro Apellido de la estructura
/// @param pPasajeroA
/// @param pPasajeroB
/// @return Retorna -1 si es menor 1 si es mayor o 0 si es igual
int comparaApellido(void* pPasajeroA ,void* pPasajeroB);



#endif /* PASSENGER_H_ */
