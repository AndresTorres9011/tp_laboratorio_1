/*
 ============================================================================
 Name        : trabajo_practico_2.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Enunciado
 Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
 dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
 El sistema deberá tener el siguiente menú de opciones:
 1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
 de Id. El resto de los campos se le pedirá al usuario.
 2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
 o Salario o Sector
 3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 4. INFORMAR:
 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 carga de algún empleado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

#define QTY_EMPLOYEES 5
#define CANTIDAD_REINTENTOS 3
#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int indice=0;
    int order=1;
	Employee arrayEmployees[QTY_EMPLOYEES];

	    employees_init(arrayEmployees,QTY_EMPLOYEES);
		arrayEmployees[0].id = 1;
		strcpy(arrayEmployees[0].name, "Andres");
		strcpy(arrayEmployees[0].lastName, "Torres");
		arrayEmployees[0].salary = 6000;
		arrayEmployees[0].sector = 1;
		arrayEmployees[0].isEmpty = FALSE;
		arrayEmployees[1].id = 2;
		strcpy(arrayEmployees[1].name, "xiomara");
		strcpy(arrayEmployees[1].lastName, "alarcon");
		arrayEmployees[1].salary = 9000;
		arrayEmployees[1].sector = 3;
		arrayEmployees[1].isEmpty = FALSE;
		arrayEmployees[2].id = 3;
		strcpy(arrayEmployees[2].name, "viviana");
		strcpy(arrayEmployees[2].lastName, "herrera");
		arrayEmployees[2].salary = 2000;
		arrayEmployees[2].sector = 5;
		arrayEmployees[2].isEmpty = FALSE;
		arrayEmployees[3].id = 4;
		strcpy(arrayEmployees[3].name, "fernando");
		strcpy(arrayEmployees[3].lastName, "Palacios");
		arrayEmployees[3].salary = 5000;
		arrayEmployees[3].sector = 8;
		arrayEmployees[3].isEmpty = FALSE;
		arrayEmployees[4].id = 5;
		strcpy(arrayEmployees[4].name, "berta");
		strcpy(arrayEmployees[4].lastName, "nadin");
		arrayEmployees[4].salary = 4500;
		arrayEmployees[4].sector = 2;
		arrayEmployees[4].isEmpty = FALSE;

	//if(employees_init(arrayEmployees,QTY_EMPLOYEES)==0)
	//{
		do
		{
			if(utn_getNumeroString("\n\n  1-Alta\n  2-Modificar\n  3-Baja "
				             "\n  4-Informar\n  5-Salir\n\n  Ingrese opción:",
							 "ERROR Reingrese opcion valida",&opcion,CANTIDAD_REINTENTOS,1,6)==0)
			{
				switch(opcion)
				{
					case 1:
						   if(employee_createNew(arrayEmployees,QTY_EMPLOYEES)==0)
						   {
							   printf("\n  ALTA DE EMPLEADO EXITOSA\n");
						   }
						   else
						   {
							   printf("\n  NO SE REALIZO ALTA DE EMPLEADO \n");
						   }
						break;
					case 2:
						if(employee_modifify(arrayEmployees,QTY_EMPLOYEES,indice)==0)
						{
							printf("\n  MODIFICACION DE EMPLEADO EXITOSA\n");
						}
						else
						{
							printf("\n  MODIFICACION INCORECTA\n");
						}
					break;
					case 3:
					    if(employee_remove(arrayEmployees,QTY_EMPLOYEES,indice)==0)
					    {
							 printf("\n  BAJA DE EMPLEADO EXITOSA\n");
						}
						else
						{
							printf("\n  BAJA DE EMPLEADO INCORECTA\n");
						}
					break;
					case 4:
						employees_sortBySector(arrayEmployees,QTY_EMPLOYEES,order);
					break;
					case 5:
						 employee_print(arrayEmployees,QTY_EMPLOYEES);
					break;
				}
			}
		}while(opcion!=6);
	//}
	return EXIT_SUCCESS;
}
