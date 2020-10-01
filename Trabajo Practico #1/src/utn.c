/*
 * utn.c
 *
 *  Created on: 11/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief utn_getFloat : Pide al usuario un numero.
 * \param mensaje: El mensaje que imprime para pedir un numero.
 * \param mensajeError: mensaje que imprime si no ingreso un numero.
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario.
 * \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos)
{
	int retorno = -1;
	int respuestaScan;
	float bufferFloat;
	printf("%s",mensaje);
	fflush(stdin);
	respuestaScan = scanf("%f",&bufferFloat);
	while (respuestaScan == 0 && reintentos > 0)
	{
		reintentos--;
		printf("%s",mensajeError);
		fflush(stdin);
		respuestaScan = scanf("%f",&bufferFloat);

	}
	if(respuestaScan != 0)
	{ //TODO OK
		*pResultado = bufferFloat;
		retorno = 0;
	}

	if(reintentos==0)
	{
		printf("   Se quedo sin intentos\n");
		retorno = -1;
		system("PAUSE");
	}
	return retorno;
}

/**
 * \brief utn_sumaFloat : Suma dos numeros.
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la suma de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */

float utn_sumaFloat(float operador1, float operador2, float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado= operador1+operador2;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief utn_restaFloat : Resta dos numeros..
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la resta de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
float utn_restaFloat(float operador1, float operador2, float *pResultado)
{
	int retorno=-1;

	if (pResultado != NULL)
	{
		*pResultado= operador1-operador2;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief utn_multiplicacionFloat : Multiplica dos numeros.
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la multiplicacion de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
float utn_multiplicacionFloat(float operador1, float operador2, float *pResultado)
{
	int retorno=-1;

	if (pResultado != NULL)
	{
		*pResultado= operador1*operador2;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief utn_divisionFloat : Divide dos numeros.
 * \param operador1: Variable que recibe primer operador.
 * \param operador2: Variable que recibe segundo operador.
 * \param pResultado: Direccion de memoria de la variable donde escribe la multiplicacion de los dos operadores.
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error (No se puede dividir por 0)
 */
float utn_divisionFloat(float operador1, float operador2, float *pResultado)
{
	int retorno = -1;

	if(pResultado!= NULL && operador2!= 0)
	{
		*pResultado = operador1 / operador2;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief utn_getFactorial : devuelve el factorial de un numero float.
 * \param operador: variable a calcularle su factorial.
 * \param * resultado: Direccion de memoria de la variable donde escribe el valor del factorial.
 * \return retorno: 0: si esta OK. -1: Si hubo un error o se intento calcular el factorial de un numero negativo.
 */
float utn_getFactorial(float operador,float *pResultado)
{
	int retorno = -1;
	int i;
	int factorial = 1;

	if(pResultado != NULL )
	{
		if(operador == 0)
		{
			*pResultado = 1;
			retorno = 0;
		}
		if(operador > 0)
		{
			for (i = 1;i <= operador;i++)
			{
				factorial = (float)factorial * i;
			}
			*pResultado = factorial;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief utn_getNumero : Pide al usuario un numero
 * \param mensaje: El mensaje que imprime para pedir un valor
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido ( no inclusive)
 * \return Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	int numero;
	int respuestaScanF;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			respuestaScanF=scanf("%d",&numero);
			if((respuestaScanF==1) && numero>=minimo && numero<maximo)
			{
				*pResultado = numero;
				retorno=0;
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}
		if(reintentos==0)
			{
				printf("   Se quedo sin intentos");
				retorno=-1;
				system("\nPAUSE");
			}
	}
	return retorno;
}
/*
 * \brief utn_printMenuCalculadora : Imprime en pantalla el menu de una calculadora.
 */
void utn_printMenuCalculadora(void)
{
	printf( "\n\n   >>> MENU CALCULADORA <<<" );
	printf( "\n\n   1. Ingresar 1er operando.");
	printf( "\n   2. Ingresar 2do operando.");
	printf( "\n   3. Calcular todas las operaciones.");
	printf( "\n   4. Informar resultados.");
	printf( "\n   5. Salir.\n");
}
/**
 * \brief utn_calcularMaximoArray: Calcula el numero maximo del array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \param int* pResultado: puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (-1) Error / (0) Ok
 */
int utn_calcularMaximoArray(int pArray[], int len,int *pResultado)
{
	int retorno=-1;
	int maximo;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		for(int i=0; i < len; i++)
		{
			if(i==0 || pArray[i] > maximo)
			{
				maximo = pArray[i];
			}
		}
		*pResultado = maximo;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief utn_calcularMinimoArray: Calcula el numero minimo del array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesador.
 * \param int* pResultado: puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (-1) Error / (0) Ok
 */
int utn_calcularMinimoArray(int pArray[], int len,int *pResultado)
{
	int retorno=-1;
	int minimo;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		for(int i=0; i < len; i++)
		{
			if(i==0 || pArray[i] < minimo)
			{
				minimo = pArray[i];
			}
		}
		*pResultado = minimo;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief utn_calculoPromedioArray: Calcula el promedio del array recibido como parametro.
 * \param int pArray[]: Array a ser procesado.
 * \param int len: cantidad de elementos a ser procesados.
 * \param int* pResultado: puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (-1) Error / (0) Ok
 *
 */
int utn_calculoPromedioArray(int pArray[], int len, float *pResultado)
{
	int retorno=-1;
	int acumulador=0;
	float promedio;

	if(pArray!=NULL && pResultado!=NULL && len>0)
	{
		for( int i=0; i < len ; i++)
		{
			acumulador= acumulador + pArray[i];
		}
		promedio=(float)acumulador/len;
		*pResultado=promedio;
		retorno=0;
	}
	return retorno;
}

