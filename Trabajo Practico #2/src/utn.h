/*
 * utn.h
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos);
float utn_sumaFloat(float operador1, float operador2, float* pResultado);
float utn_restaFloat(float operador1, float operador2, float *pResultado);
float utn_multiplicacionFloat(float operador1, float operador2, float *pResultado);
float utn_divisionFloat(float operador1, float operador2, float *pResultado);
int utn_getNumero(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);
char utn_getCaracter(char* mensaje, char* mensajeError,char* pResultado, int reintentos, char minimo, char maximo);
float utn_factorial(float operador,float *pResultado);
void utn_printMenuCalculadora(void);
int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int utn_calcularMaximoArray(int pArray[], int len,int *pResultado);
int utn_calcularMinimoArray(int pArray[], int len,int *pResultado);
int utn_calculoPromedioArray(int pArray[], int len, float *pResultado);
int utn_ordenarArrayEnteros(int pArray[], int len);
int utn_imprimirArrayNumeros(int pArray[], int len);
int utn_contadorArrayNumeroRepetido(int pArray[], int len,int numero, int *pResultado);
int utn_contadorArrayLetraRepetido(char pArray[], int len,char letra, int *pResultado);
int utn_imprimirArrayLetras(char pArray[]);
int utn_validarArrayLetras(char* cadena,int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getNumeroString(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);
int utn_getNumeroFloat(char* mensaje, char* mensajeError,float* pResultado, int reintentos, int minimo, int maximo);
int utn_getNickName(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);

#endif /* UTN_H_ */
