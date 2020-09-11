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
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	float numero1;
	float numero2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorialNumero1;
	float resultadoFactorialNumero2;

	int opcion;

	while(opcion!=5)
	{
		utn_printMenuCalculadora();
		if(utn_getInt("\n   Ingrese opcion: ","\n   Error, Reingrese opcion valida (1-5): ",&opcion,4,1,6)==0 )
		{
		  if(opcion>0 && opcion<5)
		  {
			switch(opcion)
			{
				  case 1:
					  if(utn_getFloat("   Ingresar 1er operando: ","\n   Error, Reingrese un numero: ",&numero1,4) == 0)
					  {
						  printf("   A=%.2f",numero1);
					  }
					  else
					  {
						  printf("ERROR");
					  }
					  break;
				  case 2:
					  if(utn_getFloat("   Ingresar 2do operando: ","\n   Error, Reingrese un numero: ",&numero2,4) == 0)
					  {
						  printf("   B=%.2f",numero2);
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
					  utn_getFactorial(numero1,&resultadoFactorialNumero1);
					  utn_getFactorial(numero2,&resultadoFactorialNumero2);
				  break;
				  case 4:
					  printf("\n   El resultado de %.2f+%.2f es: %.2f",numero1,numero2,resultadoSuma);
					  printf("\n   El resultado de %.2f-%.2f es: %.2f",numero1,numero2, resultadoResta);
					  printf("\n   El resultado de %.2f*%.2f es: %.2f",numero1,numero2, resultadoMultiplicacion);
					  if(utn_divisionFloat(numero1,numero2,&resultadoDivision)==0)
						{
							printf("\n   El resultado de %.2f/%.2f es: %.2f",numero1,numero2,resultadoDivision);
						}
						else
						{
							printf("\n   No se puede dividir por 0");
						}
					  printf("\n   El factorial de %.2f es %.2f y el factorial de %.2f es %.2f"
							  ,numero1,resultadoFactorialNumero1,numero2,resultadoFactorialNumero2);
				  break;
			}
		 }
	  }
	}

	return EXIT_SUCCESS;
}

