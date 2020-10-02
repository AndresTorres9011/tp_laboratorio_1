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
 * \brief _print: Print data search by id.
 * \param * list: Pointer to the array.
 * \param int len: Array length..
 * \param int index: Is the data position.
 * \return (-1) Error / (0) Ok
 */
int employee_printById(Employee* list, int len,int index)
{
	int retorno = -1;

	if(list!= NULL && len > 0)
	{
		if(list[index].isEmpty == FALSE)
		{
			printf("\n  ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f -Sector: %d",
				  list[index].id,list[index].name, list[index].lastName, list[index].salary, list[index].sector);
			retorno = 0;
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
int employee_modifify(Employee* list,int len)
{
	int retorno = -1;
	int option;
	int idModificar;
	int index;
	Employee buffer;

	if(list != NULL && len>0)
	{
		if(utn_getNumeroString("\n\n  Ingrese el ID a modificar:","  Error Reingrese el ID a modificar!"
									,&idModificar,CANTIDAD_REINTENTOS,1,1000)==0)
		{
			if(employee_findById(list,QTY_EMPLOYEES,&index,idModificar)==0 &&
					employee_printById(list,QTY_EMPLOYEES,index)==0)
			{
				//index=auxIndice;
				do
				{
					if(list[index].isEmpty == FALSE && utn_getNumeroString("\n  1-Nombre\n  2-Apellido\n  3-Salario\n  4-Sector\n  5-Menu anterior\n "
							"Elija dato a actualizar:","\nERROR Reingrese opcion valida",&option,CANTIDAD_REINTENTOS,1,5) == 0)
					{
						switch(option)
						{
						   case 1:
							   if(utn_getNombre("\n  Ingrese Nombre?","\n  Error no es un nombre valido"
															,buffer.name,CANTIDAD_REINTENTOS,SIZE_NAME) == 0)
								{
									strncpy(list[index].name,buffer.name,SIZE_NAME);
									printf("\n  NOMBRE ACTUALIZADO: %s",list[index].name);
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
									printf("\n  SALARIO ACTUALIZADO: %.2f",list[index].salary);
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
									printf("\n  SECTOR NO ACTUALIZADO");
								}
							break;
						}
					}
				}while(option != 5);
			  }
			  else
			  {
					printf("\n  ID INCORRECTO ID\n");
			  }
			}
		else
		{
			printf("\n  NO INGRESO NUMEROS\n");
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
int employee_remove(Employee* list,int len)
{
	int retorno = -1;
	int idBaja;
	int index;

	if(list != NULL && len>0)
	{
		if(utn_getNumeroString("\n\n  Ingrese el ID a dar de baja:","  Error Reingrese el ID a dar de baja!"
								 ,&idBaja,CANTIDAD_REINTENTOS,1,1000)==0)
		{
			if(employee_findById(list,QTY_EMPLOYEES,&index,idBaja)==0 &&
					employee_printById(list,QTY_EMPLOYEES,index)==0)
			{
				//index=auxIndice;
				if(list[index].isEmpty == FALSE)
				{
					//BAJA LOGICA DE ID
					list[index].isEmpty = TRUE;
					retorno = 0;
				}
			}
			else
			{
				printf("\n  ID INCORRECTO ID\n");
			}
		}
		else
		{
			printf("\n  NO INGRESO NUMEROS ID\n");
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
int employees_sortByLastName(Employee* list, int len, int order)
{
	int retorno=-1;
	Employee swap;
    int flagEstadoDesordenado=1;

    if(list!=NULL && len>0 && (order == 1 || order == 0))
    {
    	while(flagEstadoDesordenado==1)// no esta ordenado
		{
			flagEstadoDesordenado=0;

			// la pasadita
			for( int i=0 ; i<(len-1)  ; i++)
			{
				if((order == 1 && (strncmp(list[i].lastName, list[i + 1].lastName,SIZE_NAME)>0 ||
					  (strncmp(list[i].lastName, list[i + 1].lastName,SIZE_NAME)==0 &&
					   strncmp(list[i].name, list[i + 1].name,SIZE_NAME)>0))) ||
					  (order == 0 &&(strncmp(list[i].lastName, list[i + 1].lastName,SIZE_NAME)<0 ||
					  (strncmp(list[i].lastName, list[i + 1].lastName,SIZE_NAME)==0 &&
					   strncmp(list[i].name, list[i + 1].name,SIZE_NAME)<0))))
				{
					swap = list[i];
					list[i] = list[i + 1];
					list[i + 1] = swap;
					flagEstadoDesordenado = 1;
				}
			}
		}
    	retorno=0;
    }
	return retorno;
}
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
/**
 * \brief _print: Print the uploaded data in columns.
 * \param * list: Pointer to the array.
 * \param int len: Array length..
 * \return (-1) Error / (0) Ok
 */
int employees_print(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf("\n   ID    | APELLIDO      |NOMBRE         |SECTOR|SUELDO\n");
		for(int i=0;i< len ;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("   %-6d|%-15s|%-15s|%-6d|$%.2f\n",list[i].id,list[i].lastName,list[i].name,list[i].sector,list[i].salary);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief _salaryAccumulator: Accumulates the salaries of the array.
 * \param * list: Pointer to the array.
 * \param int len: Array length.
 * \paramfloat* pResult:Pointer to the memory space where the result of the function will be left.
 * \return (-1) Error / (0) Ok
 */
int employees_salaryAccumulator(Employee* list,int len,float* pResult)
{
	int retorno=-1;
	float accumulator=0;

	if(list!=NULL && len>0 && pResult!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				accumulator+= list[i].salary;
				retorno=0;
			}
		}
	}
	*pResult=accumulator;
	return retorno;
}
/**
 * \brief _countId: Count the data you have registered.
 * \param * list: Pointer to the array.
 * \param int len: Array length.
 * \paramfloat* quantityId:Pointer to the memory space where the result of the function will be left.
 * \return (-1) Error / (0) Ok
 */
int employees_countId(Employee* list,int len,int* quantityId)
{
	int retorno=-1;
	int counterId=0;
	int i;

	if(list!=NULL && len>0 && quantityId!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].id>0)
			{
				counterId++;
				retorno=0;
			}
		}
	}
	*quantityId = counterId;
	return retorno;
}
/**
 * \brief _average: Calculate the average of the array.
 * \param float salary: Salary of the array.
 * \param int quantityId: Id..
 * \paramfloat* * pResult:Pointer to the memory space where the result of the function will be left.
 * \return (-1) Error / (0) Ok
 */
int employees_average(float salary,int quantityId,float* pResult)
{
	int retorno=-1;

	if(salary>0 && quantityId>0 && pResult!=NULL)
	{
		*pResult=salary/quantityId;
		retorno=0;
	}
	return retorno;
}
/**
 * \brief _exceedAverage: Find the salary that exceed the average..
 * \param * list: Pointer to the array.
 * \param int len: Array length.
 * \param  float average:Average of the array.
 * \paramfloat* * pResult:Pointer to the memory space where the result of the function will be left.
 * \return (-1) Error / (0) Ok
 */
int employees_exceedAverage(Employee* list,int len,float average, int* pResult)
{
	int retorno=-1;
	int i;
	int counterSalaryExceed=0;

	if(list!=NULL && len>0 && list>0 && pResult!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].salary > average)
			{
				counterSalaryExceed++;
				retorno=0;
			}
		}
	}
	*pResult=counterSalaryExceed;
	return retorno;
}
/**
 * \brief _salaryReport: Make a report of the salaries.
 * \param * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 */
int employees_salaryReport(Employee* list,int len)
{
	int retorno=-1;
	float totalSalary;
	int totalEmployees;
	float average;
	int exceedSalary;

	if(list!=NULL && len>0)
	{
		if(employees_salaryAccumulator(list,len,&totalSalary)==0 &&
				employees_countId(list,len,&totalEmployees)==0)
		{
			 printf("\n\n   El salario total es: $%.2f",totalSalary);
			 if(employees_average(totalSalary,totalEmployees,&average)==0)
			 {
				  printf("\n\n   El salario promedio es: $%.2f",average);
			 }
		}
		if(employees_exceedAverage(list,len,average,&exceedSalary)==0)
		{
			printf("\n\n   Los empleados que superan el promedio de salario son: %d\n",exceedSalary);
		}
		else
		{
			printf("\n\n   Nadie supera el salario promedio");
		}
		retorno=0;
	}
	return retorno;
}
/**
 * \brief _reporting: Makes a detailed report of the data entered and sorts them.
 * \param * list: Pointer to the array.
 * \param int len: Array length.
 * \return (-1) Error / (0) Ok
 */
int employees_reporting(Employee* list, int len)
{
	int retorno = -1;
	int order;
	int option;

	if( list!=NULL && len>0)
	{
		do
		{
			if(utn_getNumeroString("\n  1-Mostrar listado de empleados ordenado por apellido\n  "
				"2-Mostrar listado de empleados ordenado por sector\n  3-Informe de salarios salarios\n  "
				"4-Menu anterior\n  Ingrese opcion Informe:","\nError Reingrese opcion correcta",&option,CANTIDAD_REINTENTOS,1,4)==0)
			{
				switch(option)
				{
					case 1:
						if(utn_getNumeroString("\n  Orden alfabetico 1- Ascendente (A-Z) o 0- Descendente (Z-A)\n  Ingrese criterio orden:",
							"Error Reingrese opcion correcta",&order,CANTIDAD_REINTENTOS,0,1)==0)
						{
							if(employees_sortByLastName(list,QTY_EMPLOYEES,order)==0)
							{
								employees_print(list,QTY_EMPLOYEES);
								retorno = 0;
							}
						}
						else
						{
							printf("  INGRESE OPCION VALIDA.\n");
						}
						break;
					case 2:
						if(utn_getNumeroString("\n  Orden numerico 1- Ascendente (0-10) o 0- Descendente (10-0)\n  Ingrese criterio orden:",
								"Error Reingrese opcion correcta",&order,CANTIDAD_REINTENTOS,0,1)==0)
						{
							if(employees_sortBySector(list,QTY_EMPLOYEES,order)==0)
							{
								employees_print(list,QTY_EMPLOYEES);
								retorno = 0;
							}
						}
						else
						{
							printf("  INGRESE OPCION VALIDA.\n");
						}
					break;
					case 3:
						if(employees_salaryReport(list,QTY_EMPLOYEES)==0)
						{
							retorno = 0;
						}
					break;
				}
			 }
			}while(option!=4);
		}
	return retorno;
}
