/*
 * utn.h
 *
 *  Created on: 11/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos);
float utn_sumaFloat(float operador1, float operador2, float* pResultado);
float utn_restaFloat(float operador1, float operador2, float *pResultado);
float utn_multiplicacionFloat(float operador1, float operador2, float *pResultado);
float utn_divisionFloat(float operador1, float operador2, float *pResultado);
int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);
float utn_getFactorial(float operador,float *pResultado);
void utn_printMenuCalculadora(void);
int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo);
int utn_calcularMaximoArray(int pArray[], int len,int *pResultado);
int utn_calcularMinimoArray(int pArray[], int len,int *pResultado);
int utn_calculoPromedioArray(int pArray[], int len, float *pResultado);


#endif /* UTN_H_ */
