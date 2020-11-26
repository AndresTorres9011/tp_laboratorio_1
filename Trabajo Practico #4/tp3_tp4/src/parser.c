#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#define BUFFER_STRING 4096

/*
 * \brief _EmployeeFromText: Parse the employee data from the file in text mode.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEmployee:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *pEmployee;
	char bufferHeader[BUFFER_STRING];
	char bufferId[BUFFER_STRING];
	char bufferNombre[BUFFER_STRING];
	char bufferHorasTrabajadas[BUFFER_STRING];
	char bufferSueldo[BUFFER_STRING];

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^\n]\n",bufferHeader);
		do
		{
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo) == 4)
			{
				pEmployee = employee_newParametrosTxt(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
				if (pEmployee != NULL)
				{
					retorno = ll_add(pArrayListEmployee, pEmployee);
				}
			}
			else
			{
				break;
			}
		} while (!feof(pFile));
	}
	return retorno;
}

/*
 * \brief _EmployeeFromBinary: Parse the employee data from the file in binary mode.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEmployee:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			pEmployee = employee_new();
			if (pEmployee != NULL && fread(pEmployee,sizeof(Employee),1,pFile)==1)
			{
				retorno = ll_add(pArrayListEmployee, pEmployee);
			}
			else
			{
				break;
			}
		} while (!feof(pFile));
	}
	return retorno;
}
/*
 * \brief _EmployeeToText:  Parse employee data to the text mode file.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEmployee:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *pEmployee;
	int bufferId;
	char bufferNombre[NOMBRE_LEN];
	int bufferHorasTrabajadas;
	float bufferSueldo;
	int len= ll_len(pArrayListEmployee);
	int i;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fprintf(pFile, "ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");
		for (i = 0; i < len; i++)
		{
			pEmployee =ll_get(pArrayListEmployee, i);
			if (pEmployee != NULL
					&& employee_getId(pEmployee, &bufferId) == 0
					&& employee_getNombre(pEmployee, bufferNombre) == 0
					&& employee_getSueldo(pEmployee, &bufferSueldo) == 0
					&& employee_getHorasTrabajadas(pEmployee, &bufferHorasTrabajadas) == 0)
			{
				fprintf(pFile, "%d,%s,%d,%f\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _EmployeeToBinary: Parse employee data to the binary mode file.
 * \param FILE* pFile : Pointer to the file.
 * LinkedList* pArrayListEmployee:  Pointer to LinkedList.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee;
	int len=ll_len(pArrayListEmployee);
	int i;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		for (i = 0; i < len; i++)
		{
			pEmployee =ll_get(pArrayListEmployee, i);
			if (pEmployee != NULL)
			{
				fwrite(pEmployee, sizeof(Employee), 1, pFile);
			}
		}
		retorno = 0;
	}
	return retorno;
}
