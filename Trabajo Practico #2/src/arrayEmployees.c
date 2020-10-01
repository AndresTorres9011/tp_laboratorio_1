/*
 * utn.c
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

#define TRUE 1
#define FALSE 0
#define MIN_SALARY 1
#define MAX_SALARY 100000
#define MIN_SECTOR 1
#define MAX_SECTOR 10
#define CANTIDAD_REINTENTOS 3
#define MIN_ID 0
#define MAX_ID 9999


static int newIdGenerate(void);

/**
 * \brief _init: To indicate that all position in the array are empty,
*                this function put the flag (isEmpty) in TRUE in all
*                position of the array.
* \param Employee* list: Pointer to array of employees
* \param int len:  Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int employees_init(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief _searchEmpty: Search in the array for the first index with TRUE in isEmpty.
 * \param Employee* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to position of first empty index.
 * \return (-1) Error / (0) Ok
 */
int employees_searchEmpty(Employee* list, int len, int *pIndex)
{
	int retornar = -1;
	if(list != NULL && pIndex != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				*pIndex = i;
				retornar = 0;
				break;
			}
		}
	}
	return retornar;
}
/* \brief newIdGenerate: Create a new id when the user load data (different id).
 *  \return id.
 */
static int newIdGenerate(void)
{
	static int id=0; // es global para solo la fn puede usarla

	//guarda el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}
/**
 *  \brief _add: Add in a existing list the values received.
 *               as parameters in the first empty position.
 * \param Employee* list: Pointer to the array.
 * \param int len: Array length
 * \param int id: Received Id.
 * \param char* name: Data received from the user.
 * \param char* lastName: Data received from the user.
 * \param float salary: Data received from the user.
 * \param int sector: Data received from the user.
 * \return (-1) Error / (0) Ok
 */
int employees_add(Employee* list,int len,int id,char* name,char* lastName,float salary,int sector)
{
	int retorno = -1;
	int index;

	if(list!=NULL && len >0 && name!=NULL && lastName!=NULL &&
			employees_searchEmpty(list,QTY_EMPLOYEES,&index)==0)
	{
			list[index].id=id;
			strncpy(list[index].name,name,SIZE_NAME);
			strncpy(list[index].lastName,lastName,SIZE_NAME);
			list[index].salary=salary;
			list[index].sector=sector;
			list[index].isEmpty=FALSE;
			retorno=0;
	}
    return retorno;
}
/**
 * \brief _createNew: Create a new profile asking data to the user.
 *                    Use _searchEmpty, to locate data in an empty index.
 * \param  * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 *
 */
int employee_createNew(Employee* list, int len)
{
	int retorno = -1;
	int indice;
	Employee buffer;
	if (list != NULL && len >0)
	{
		if (employees_searchEmpty(list,len,&indice) == 0)
		{
			if (utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido",buffer.name,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
				utn_getNombre("\n  Ingrese Apellido?","\n  Error no es un apellido valido",buffer.lastName,CANTIDAD_REINTENTOS,SIZE_NAME) == 0 &&
				utn_getNumeroFloat("\n  Ingrese Salario?","\n  Error no es un numero valido",&buffer.salary,CANTIDAD_REINTENTOS,MIN_SALARY,MAX_SALARY)==0 &&
				utn_getNumeroString("\n  Ingrese Sector?","\n  Error no es un numero valido",&buffer.sector,CANTIDAD_REINTENTOS,MIN_SECTOR,MAX_SECTOR)==0)
			{
				buffer.id= newIdGenerate();
				if(employees_add(list,QTY_EMPLOYEES,buffer.id,buffer.name,buffer.lastName,buffer.salary,buffer.sector)==0)
				{
					list[indice].isEmpty = FALSE;
				    retorno=0;
				}
			}
			else
			{
				printf("  ERROR NO INGRESASTE DATOS VALIDOS");
			}
		}
		else
		{
			printf("\n  NO QUEDAN ESPACIOS LIBRES");
		}
	}
	return retorno ;
}
/**
 * \brief _findById: find  by Id.
 * \param Employee* list: Pointer to the array.
 * \param int len: Array length.
 * \param int *pIndex: Pointer to the memory  where write the value.
 * \param int id: Assigned id.
 * \return (-1) Error / (0) Ok
 *
 */
int employee_findById(Employee* list, int len, int* pIndex, int id)
{
    int retorno = -1;
    //*pIndex = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE )
            {
                if(list[i].id == id)
                {
                   *pIndex = i;
                   retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief _print: Print the uploaded data.
 * \param * list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
int employee_print(Employee* list, int len)
{
	int retorno = -1;

	if(list!= NULL && len > 0 )
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n  ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f -Sector: %d",
						list[i].id,list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief _modifify: Modify the data only if the index corresponds to a NO Empty
 * \param  Employee* list: Pointer to the array.
 * \param int len: Array length.
 * \param int index: Is the index where it is loaded.
 * \return (-1) Error / (0) Ok
 *
 */
int employee_modifify(Employee* list,int len,int index)
{
	int retorno = -1;
	int option;
	int idModificar;
	int auxIndice;
	Employee buffer;

	if(list != NULL && len>0 && index<len)
	{
		employee_print(list,QTY_EMPLOYEES);
		if(utn_getNumeroString("\n\n  Ingrese el ID a modificar:","  Error Reingrese el ID a modificar!"
									,&idModificar,CANTIDAD_REINTENTOS,1,1000)==0)
		{
			if(employee_findById(list,QTY_EMPLOYEES,&auxIndice,idModificar)==0)
			{
				index=auxIndice;
				do
				{
					if(list[index].isEmpty == FALSE && utn_getNumeroString("\n  Elija dato a actualizar\n  1-Nombre\n  2-Apellido\n  3-Salario\n  4-Sector\n  5-Menu anterior"
							,"\nERROR Reingrese opcion valida",&option,CANTIDAD_REINTENTOS,1,5) == 0)
					{
						switch(option)
						{
						   case 1:
							   if(utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido"
															,buffer.name,CANTIDAD_REINTENTOS,SIZE_NAME) == 0)
								{
									strncpy(list[index].name,buffer.name,SIZE_NAME);
									printf("\nNOMBRE ACTUALIZADO: %s",list[index].name);
									retorno = 0;
								}
								else
								{
									printf("\n  NOMBRE NO ACTUALIZADO");
								}

							break;
							case 2:
								if(utn_getNombre("\n  Ingrese Apellido?","\n  Error no es un apellido valido",
										buffer.lastName,CANTIDAD_REINTENTOS,SIZE_NAME) == 0)
								{
									strncpy(list[index].lastName,buffer.lastName,SIZE_NAME);
									printf("\n  APELLIDO ACTUALIZADO: %s",list[index].lastName);
									retorno = 0;
								}
								else
								{
									printf("\n  APELLIDO NO ACTUALIZADO");
								}
							 break;
							 case 3:
								if(utn_getNumeroFloat("\n  Ingrese Salario?","\n  Error no es un numero valido",
										&buffer.salary,CANTIDAD_REINTENTOS,MIN_SALARY,MAX_SALARY)==0)
								{
									list[index].salary=buffer.salary;
									printf("\n SALARIO ACTUALIZADO: %.2f",list[index].salary);
									retorno = 0;
								}
								else
								{
									printf("\n  SALARIO NO ACTUALIZADO");
								}
							break;
							case 4:
							if(utn_getNumeroString("\n  Ingrese Sector?","\n  Error no es un numero valido",
									&buffer.sector,CANTIDAD_REINTENTOS,MIN_SECTOR,MAX_SECTOR)==0)
								{
									list[index].sector=buffer.sector;
									printf("\n  SECTOR ACTUALIZADO: %d",list[index].sector);
									retorno = 0;
								}
								else
								{
									printf("\n SECTOR NO ACTUALIZADO");
								}
							break;
						}

					}
				}while(option != 5);
			  }
			}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE ID\n");
		}
	}
	return retorno;
}
/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param  Employee* list: Pointer to the array.
 * \param int len: Length of the array
 * \param int index: is the position from which the data is deleted.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int employee_remove(Employee* list,int len,int index)
{
	int retorno = -1;
	int idBaja;
	int auxIndice;

	if(list != NULL && len>0 && index<len)
	{
		employee_print(list,QTY_EMPLOYEES);
		if(utn_getNumeroString("\n\n  Ingrese el ID a dar de baja:","  Error Reingrese el ID a dar de baja!"
								 ,&idBaja,CANTIDAD_REINTENTOS,1,1000)==0)
		{
			if(employee_findById(list,QTY_EMPLOYEES,&auxIndice,idBaja)==0)
			{
				index=auxIndice;
				if(list[index].isEmpty == FALSE)
				{
					list[index].isEmpty = TRUE;
					retorno = 0;
				}
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE ID\n");
		}
	}
	return retorno;
}
/**
 * \brief _sortByLastName: Sort the list by ascendent (0) or descendent(1), the argument order
                indicate UP or DOWN order
 * \param Employee *list: Pointer to the array.
 * \param int len: Length of the array.
 * \param int order: Number indicating the order of the list.
 * \return (-1) if Error, (0)  if Ok
 */

/**
 * \brief _sortBySector: Sort the list by ascendent (0) or descendent(1), the argument order
                indicate UP or DOWN order
 * \param Employee *list: Pointer to the array.
 * \param int len: Length of the array.
 * \param int order: Number indicating the order of the list.
 * \return (-1) if Error, (0)  if Ok
 */
int employees_sortBySector(Employee *list, int len, int order)
{
	int retorno = -1;
	Employee auxSwap;
	int flagEstadoDesordenado=1;
	if(list != NULL && len > 0 && (order == 1 || order == 0))
	{
		do
		{
			flagEstadoDesordenado=0;
			// la pasadita
			for(int i=0; i<len-1; i++)
			{
				if( (order == 1 && list[i].sector > list[i+1].sector)
						||
					(order == 0 && list[i].sector < list[i+1].sector))//aca establezco por que criterio quiero ordenar
				{
					auxSwap = list[i];
					list[i] = list[i+1];
					list[i+1] = auxSwap;
					flagEstadoDesordenado=1;
					retorno = 0;
				}
			}
		}while(flagEstadoDesordenado==1);// no esta ordenado
	}
	return retorno;
}
/**
 * \brief _print: Print the uploaded data.
 * \param * list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
int employee_printF(Employee* list, int len)
{
	int retorno = -1;

	if(list!= NULL && len > 0 )
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n  ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f -Sector: %d",
						list[i].id,list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				retorno = 0;
			}
		}
	}
	return retorno;
}




