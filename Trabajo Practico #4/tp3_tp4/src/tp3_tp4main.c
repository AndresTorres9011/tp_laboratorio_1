/*
 ============================================================================
 Name        : prueba_tp4.c
 Author      : TORRES CAICEDO ANDRES FELIPE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


int main()
{
	setbuf(stdout,NULL);
	int option = 0;
	LinkedList *listaEmpleados = ll_newLinkedList();
	int retorno;

	do
	{
		if(!utn_getNumber(&option,"\n\n1-Cargar archivo de empleados (modo texto).""\n2-Cargar archivo de empleados (modo binario)."
						  "\n3-Alta de empleado\n4-Modificar datos de empleado\n5-Baja de empleado\n6-Listar empleados\n7-Ordenar empleados"
							"\n8-Guardar datos en archivo (modo texto)\n9-Guardar datos en archivo (modo binario)."
							"\n10. SALIR\n\n Opcion: ","\nError! elija una opcion valida",1,10,CANTIDAD_REINTENTOS))
		{
			switch (option)
			{
				case 1:
					if (!controller_loadFromText("dataComoTexto.csv", listaEmpleados))
					{
						printf("\nARCHIVO CARGADO MODO TEXTO\n");
					}
					else
					{
						printf("\nARCHIVO NO CARGADO VERIFIQUE\n");
					}
					break;
				case 2:
					if ((retorno = controller_loadFromBinary("dataComoBinario.bin", listaEmpleados) == 0))
					{
						printf("\nARCHIVO CARGADO MODO BINARIO\n");
					}
					else
					{
						printf("\nARCHIVO NO CARGADO VERIFIQUE\n");
					}
					break;
				 case 3:
					if(!ll_isEmpty(listaEmpleados))
					{
						if(!controller_addEmployee(listaEmpleados))
						{
							printf("\nALTA DE EMPLEADO OK\n");
						}
						else
						{
							printf("\nNO SE REALIZO ALTA DE EMPLEADO\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 4:
					if(!ll_isEmpty(listaEmpleados))
					{
						if (!controller_editEmployee(listaEmpleados))
						{
							printf("\nMODIFICACION DE EMPLEADO OK\n");
						}
						else
						{
							printf("\nNO SE MODIFICO EMPLEADO\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 5:
					if(!ll_isEmpty(listaEmpleados))
					{
						if(!controller_removeEmployee(listaEmpleados))
						{
							printf("\nBAJA DE EMPLEADO OK\n");
						}
						else
						{
							printf("\nNO SE REALIZO BAJA DE EMPLEADO\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 6:
					if(!ll_isEmpty(listaEmpleados))
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 7:
					if(!ll_isEmpty(listaEmpleados))
					{
						if(!controller_sortEmployee(listaEmpleados))
						{
							printf("\nLISTA DE EMPLEADOS ORDENADA\n");
						}
						else
						{
							printf("\nNO SE ORDENO LA LISTA\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 8:
					if(!ll_isEmpty(listaEmpleados))
					{
						if (controller_saveAsText("dataComoTexto.csv", listaEmpleados) == 0)
						{
							printf("\nARCHIVO GUARDADO EN MODO TEXTO\n");
						}
						else
						{
							printf("\nNO SE GUARDO ARCHIVO\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
				case 9:
					if(!ll_isEmpty(listaEmpleados))
					{
						if (controller_saveAsBinary("dataComoBinario.bin", listaEmpleados) == 0)
						{
							printf("\nARCHIVO GUARDADO EN MODO BINARIO\n");

						}
						else
						{
							printf("\nNO SE GUARDO ARCHIVO\n");
						}
					}
					else
					{
						printf("\nCARGUE ARCHIVO EN MODO TEXTO O BINARIO.\n");
					}
					break;
			}
		}
	} while (option != 10);
	printf("\n\nPROGRAMA TERMINADO\n\n");
	return 0;
}
