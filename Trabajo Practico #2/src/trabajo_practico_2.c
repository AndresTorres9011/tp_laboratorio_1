/*
 ============================================================================
 Name        : trabajo_practico_2.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Enunciado
 Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
 dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
 El sistema deber� tener el siguiente men� de opciones:
 1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
 de Id. El resto de los campos se le pedir� al usuario.
 2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
 o Salario o Sector
 3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
 4. INFORMAR:
 1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
 2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
 NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
 Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 carga de alg�n empleado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

#define QTY_EMPLOYEES 1000
#define CANTIDAD_REINTENTOS 3
#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int flagAltaEmpleado=FALSE;
	Employee arrayEmployees[QTY_EMPLOYEES];

	if(employees_init(arrayEmployees,QTY_EMPLOYEES)==0)
	{
		do
		{
			if(utn_getNumeroString("\n\n  1-Alta\n  2-Modificar\n  3-Baja "
				             "\n  4-Informe\n  5-Salir\n\n  Ingrese opci�n:",
							 "ERROR Reingrese opcion valida",&opcion,CANTIDAD_REINTENTOS,1,5)==0)
			{
				switch(opcion)
				{
					case 1:
						   if(employee_createNew(arrayEmployees,QTY_EMPLOYEES)==0)
						   {
							   printf("\n  ALTA DE EMPLEADO EXITOSA\n");
							   flagAltaEmpleado=TRUE;
						   }
						   else
						   {
							   printf("\n  NO SE REALIZO ALTA DE EMPLEADO \n");
						   }
						break;
					case 2:
						if(flagAltaEmpleado==TRUE)
						{
							if(employee_modifify(arrayEmployees,QTY_EMPLOYEES)==0)
							{
								printf("\n  MODIFICACION DE EMPLEADO EXITOSA\n");
							}
							else
							{
								printf("\n  MODIFICACION INCORECTA\n");
							}
						}
						else
						{
							printf("\n  NO DIO DE ALTA NINGUN EMPLEADO\n");
						}
					break;
					case 3:
						if(flagAltaEmpleado==TRUE)
						{
							if(employee_remove(arrayEmployees,QTY_EMPLOYEES)==0)
							{
								 printf("\n  BAJA DE EMPLEADO EXITOSA\n");
							}
							else
							{
								printf("\n  BAJA DE EMPLEADO INCORECTA\n");
							}
						}
						else
						{
							printf("\n  NO DIO DE ALTA NINGUN EMPLEADO\n");
						}
					break;
					case 4:
						 if(flagAltaEmpleado==TRUE)
						 {
							 employees_reporting(arrayEmployees,QTY_EMPLOYEES);
						 }
						 else
						 {
							 printf("\n  NO DIO DE ALTA NINGUN EMPLEADO\n");
						 }
					break;
				}
			}
		}while(opcion!=5);
	}
	return EXIT_SUCCESS;
}
