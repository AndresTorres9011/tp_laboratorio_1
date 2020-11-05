#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "utn.h"
#include "Controller.h"


static int findMaxId(LinkedList* pArrayListEmployee);
static int generateNewId(LinkedList* pArrayListEmployee);

/**
 * \brief findMaxId: Search max id.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \return id if OK/ (-1) Error
 */
static int findMaxId(LinkedList* pArrayListEmployee)
{

	Employee* pEmployee;
	int len;
	int i;
	int max;
	int id = -1;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		for(i=0;i<len;i++)
		{
			pEmployee = ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee,&id);
			if (i == 0 || id > max)
			{
				max = id;
			}
		}
		id = max;

	}
	return id;
}

/**
 * \brief Generates a new id for a new client,
 * \param void
 * \return int Return value of the new id
 */
static int generateNewId(LinkedList* pArrayListEmployee)
{
    static int id = -1;
    static int flag = 1;

    if(pArrayListEmployee != NULL)
    {
		if(flag == 1)
		{
			id = findMaxId(pArrayListEmployee);
			flag++;
		}
		id++;
    }
    return id;
}

/**
 * \brief _loadFromText: Carga los datos de los empleados desde el archivo que recibe como parametro (modo texto).
 * \param char* path: File address..
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"r");
		if (pFile != NULL)
		{
			retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}
	return retorno;
}
/**
 * \brief _loadFromBinary: Carga los datos de los empleados desde el archivo que recibe como parametro (modo binario).
 * * \param char* path: File address.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"rb");
		if (pFile != NULL)
		{
			retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}
	return retorno;
}
/**
 * \brief _addEmployee: Create a new profile asking data to the user.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee;
	Employee buffer;

	if (pArrayListEmployee != NULL)
	{
		pEmployee = employee_new();
		if(pEmployee != NULL && !utn_getName(buffer.nombre,sizeof(buffer.nombre),"Ingrese nombre: ","Error", CANTIDAD_REINTENTOS) &&
		   !utn_getNumber(&buffer.horasTrabajadas,"Ingrese horas trabajadas: ","Error", 0, 5000, CANTIDAD_REINTENTOS) &&
		   !utn_getFloatNumber(&buffer.sueldo,"Ingrese sueldo: ","Error", MIN_SUELDO, MAX_SUELDO, CANTIDAD_REINTENTOS))
		{
			buffer.id = generateNewId(pArrayListEmployee);
			if (!employee_setNombre(pEmployee, buffer.nombre) &&
				!employee_setHorasTrabajadas(pEmployee, buffer.horasTrabajadas) &&
				!employee_setSueldo(pEmployee, buffer.sueldo) &&
			    !employee_setId(pEmployee,buffer.id))
			{
				retorno = ll_add(pArrayListEmployee, pEmployee);
			}
		}
	}
	return retorno;
}
/**
 * \brief _findById: find the position in the array searched by Id.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \param int id: Id received to search position.
 * \\return int indice encontrado if OK o (-1) si el puntero a LikedList es NULL, id invalido o empleado no encontrado
 */
int controller_findById(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int i;
	int bufferId;
	int len;
	Employee* pEmployee;

	if (pArrayListEmployee != NULL && id > 0)
	{
		len = ll_len(pArrayListEmployee);
		for (i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			if (pEmployee != NULL && !employee_getId(pEmployee,&bufferId) && bufferId == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief _editEmployee: Modify the data of an employee.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \return Return(-1) Error / Return(0) Ok
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee;
	Employee buffer;
	int index;
	int option;

	if (pArrayListEmployee != NULL)
	{
		if (!controller_ListEmployee(pArrayListEmployee) && !utn_getNumber(&buffer.id, "\nIngrese el id del empleado que quiere modificar: ", "\nError!",MIN_ID, MAX_ID, CANTIDAD_REINTENTOS))
		{
			index = controller_findById(pArrayListEmployee, buffer.id);
			if (index != -1)
			{
				pEmployee = (Employee*) ll_get(pArrayListEmployee, index);
				if (pEmployee != NULL)
				{
					do {
						if (!utn_getNumber(&option, "\n\n1.Modificar Nombre \n2.Modificar Horas trabajadas "
								"\n3.Modificar Sueldo \n4.Volver al menu principal\n \n Opcion:","Error, elija una opcion valida\n", 1, 4, CANTIDAD_REINTENTOS))
						{
							switch (option)
							{
							case 1:
								if (!utn_getName(buffer.nombre, NOMBRE_LEN, "\nIngrese nuevo nombre: ", "\nError!", CANTIDAD_REINTENTOS))
								{
									employee_setNombre(pEmployee,buffer.nombre);
									printf("\nMODIFICACION DE NOMBRE OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO NOMBRE\n");
								}
								break;
							case 2:
								if (!utn_getNumber(&buffer.horasTrabajadas, "\nIngrese nueva cantidad de horas trabajadas: ", "\nError!", 0, 5000, CANTIDAD_REINTENTOS))
								{
									employee_setHorasTrabajadas(pEmployee,buffer.horasTrabajadas);
									printf("\nMODIFICACION DE HORAS TRABAJADAS OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO LAS HORAS TRABAJADAS\n");
								}
								break;
							case 3:
								if (!utn_getFloatNumber(&buffer.sueldo, "\nIngrese nuevo sueldo: ", "\nError!", MIN_SUELDO, MAX_SUELDO, CANTIDAD_REINTENTOS))
								{
									employee_setSueldo(pEmployee, buffer.sueldo);
									printf("\nMODIFICACION DE SUELDO OK\n");
									retorno = 0;
								}
								else
								{
									printf("\nNO SE MODIFICO EL SUELDO\n");
								}
								break;
							}
						}
						else
						{
							printf("\nSE QUEDO SIN INTENTOS, REGRESANDO A MENU ANTERIOR\n");
						}
						if (retorno < 0)
						{
							break;
						}
					} while (option != 4);
				}
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE\n");
		}
	}
	return retorno;
}
/**
 * \brief _removeEmployee: Remove data by Id.
 * \param  LinkedList* pArrayListEmployee: Pointer to the array.
 * \return int Return (-1) if Error [Invalid length or NULL pointer o] - Return (0) if Ok
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int index;
	int bufferId;
	Employee* pEmployee;
	char bufferAnswer[10];

	if (pArrayListEmployee != NULL)
	{
		if (!controller_ListEmployee(pArrayListEmployee)
			&& !utn_getNumber(&bufferId , "\nIngrese el id del empleado que quiere eliminar: ", "\nError!",MIN_ID,MAX_ID,CANTIDAD_REINTENTOS))
		{
			index = controller_findById(pArrayListEmployee, bufferId);
			if(index != -1)
			{
				pEmployee = (Employee*)ll_get(pArrayListEmployee, index);
				if (pEmployee != NULL
						&& !utn_getName(bufferAnswer, 10, "\n\nConfirma Board? Ingrese 'Si' para proceder con la baja: ",
								"\nError ingrese una respuesta valida.",CANTIDAD_REINTENTOS) && strncasecmp(bufferAnswer,"si", 10) == 0)
				{
					employee_delete(pEmployee);
					retorno = ll_remove(pArrayListEmployee,index);
				}
			}
		}
		else
		{
			printf("\nID NO ENCONTRADO VERIFIQUE\n");
		}

	}
	return retorno;
}
/**
 * \brief _ListEmployee: Print all the uploaded data.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int len= ll_len(pArrayListEmployee);
    int i;

    if(pArrayListEmployee != NULL)
    {
    	printf("\n%10s %15s %15s %15s\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO\n");
    	for(i=0;i<len;i++)
    	{
    		retorno = controller_printOneEmployee(pArrayListEmployee,i);
    	}
    }
	return retorno;
}
/**
 * \brief _printOneEmployee: Print data by index.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \param int index: Is the data position in the array.
 * \return (-1) Error / (0) Ok
 */
int controller_printOneEmployee(LinkedList* pArrayListEmployee, int index)
{
	int retorno = -1;
	Employee buffer;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && index >= 0)
	{
		pEmployee = (Employee*)ll_get(pArrayListEmployee,index);
		if(	pEmployee != NULL && !employee_getId(pEmployee,&buffer.id) &&
			!employee_getNombre(pEmployee,buffer.nombre) &&
			!employee_getHorasTrabajadas(pEmployee,&buffer.horasTrabajadas) &&
		    !employee_getSueldo(pEmployee,&buffer.sueldo) )
		{
			printf("\n%10d %15s %15d %15.2f\n",buffer.id,buffer.nombre,buffer.horasTrabajadas,buffer.sueldo);
					retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief _sortEmployee: Sort the array by different critery.
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \return (-1) Error / (0) Ok
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int order;

	if (pArrayListEmployee != NULL)
	{
		if(utn_getNumber(&order,"\nIngrese el criterio con el que desea ordenar [1-ASCENDENTE/0-DESCEDENTE]: ","\nError, debe ingresar o 0 o 1",0,1,CANTIDAD_REINTENTOS)==0)
		{
			//printf("\nENTRO A ORDENAR");
			ll_sort(pArrayListEmployee,employee_compareByName,order);
			retorno=0;
			//printf("\nSALGO ORDENADO");
		}
	}
	//printf("NO ORDENADO");
	return retorno;
}
/**
 * \brief _saveAsText: Guarda los datos de los empleados en el archivo que recibe como parametro (modo texto).
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \param char* path: File address.
 * \return (-1) Error / (0) Ok
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			retorno = parser_EmployeeToText(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}
	return retorno;
}
/**
 * \brief _saveAsBinary: Guarda los datos de los empleados en el archivo que recibe como parametro (modo binario).
 * \param LinkedList* pArrayListEmployee: Pointer to the array.
 * \param char* path: File address.
 * \return (-1) Error / (0) Ok
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"wb");
		if (pFile != NULL)
		{
			retorno = parser_EmployeeToBinary(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}
	return retorno;
}
