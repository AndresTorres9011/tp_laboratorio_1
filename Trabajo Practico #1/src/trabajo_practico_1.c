/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Programación I – Laboratorio I - Trabajo Practico 1
1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>


int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos);
float utn_sumaFloat(float operador1, float operador2, float* pResultado);
float utn_restaFloat(float operador1, float operador2, float *pResultado);
float utn_multiplicacionFloat(float operador1, float operador2, float *pResultado);
float utn_divisionFloat(float operador1, float operador2, float *pResultado);
int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);

int main(void) {
	setbuf(stdout,NULL);
	float numero1;
	float numero2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int opcion;

	while(opcion!=5)
	{
		printf( "\n\n   >>> MENU CALCULADORA <<<" );
		printf( "\n\n   1. Ingresar 1er operando.");
		printf( "\n   2. Ingresar 2do operando.");
		printf( "\n   3. Calcular todas las operaciones.");
		printf( "\n   4. Informar resultados.");
		printf( "\n   5. Salir.\n");


		if(utn_getInt("\nIngrese opcion: ","\nError, Reingrese opcion valida (1-5): ",&opcion,2,1,6)==0 )
		{
		  if(opcion>0 && opcion<5)
		  {
			switch(opcion)
			{
			  case 1:
				  if(utn_getFloat("Ingresar 1er operando: ","\nError, Reingrese un numero: ",&numero1,2) == 0)
				  {
					  printf("A=%.2f",numero1);
				  }
				  else
				  {
					  printf("ERROR");
				  }
			  break;
			  case 2:
				  if(utn_getFloat("Ingresar 2do operando: ","\nError, Reingrese un numero: ",&numero2,2) == 0)
				  {
					  printf("B=%.2f",numero2);
				  }
				  else
				  {
					  printf("ERROR");
				  }
			  break;
			  case 3:
				utn_sumaFloat(numero1,numero2,&resultadoSuma);
				utn_restaFloat(numero1,numero2,&resultadoResta);
				utn_multiplicacionFloat(numero1,numero2,&resultadoMultiplicacion);
				utn_divisionFloat(numero1,numero2,&resultadoDivision);
			  break;
			  case 4:
				  printf("\nEl resultado de %.2f+%.2f es: %.2f",numero1,numero2,resultadoSuma);
				  printf("\nEl resultado de %.2f-%.2f es: %.2f",numero1,numero2, resultadoResta);
				  printf("\nEl resultado de %.2f*%.2f es: %.2f",numero1,numero2, resultadoMultiplicacion);
				  if(utn_divisionFloat(numero1,numero2,&resultadoDivision)==0)
					{
						printf("\nEl resultado de %.2f/%.2f es: %.2f",numero1,numero2,resultadoDivision);
					}
					else
					{
						printf("\nNo se puede dividir por 0");
					}
			  break;

			}
		 }
	  }
	}



	return EXIT_SUCCESS;
}

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
		printf("Se quedo sin intentos");
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
				printf("Se quedo sin intentos");
				retorno=-1;
			}
	}


	return retorno;
}
