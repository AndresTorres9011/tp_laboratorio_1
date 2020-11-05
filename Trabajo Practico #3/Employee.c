#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validations.h"

/** \brief _new: Use malloc function to obtain a new memory address
 * 	\return the new memory address.
 */
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}
/** \brief _newParametrosTxt: Register an employee receiving the parameters as text.
 * \param int id:  Receive the id.
 * \param char* nombre: Receive the name.
 * \param int horasTrabajadas: Receive the worked hours.
 * \param float sueldo: Receive salary.
 * \return The memory address of the employee with all his data loaded or NULL in case something went wrong.
 */
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,float sueldo)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && nombre != NULL)
	{
		if(	employee_setId(this,id) == -1 ||
			employee_setNombre(this,nombre) == -1 ||
			employee_setHorasTrabajadas(this,horasTrabajadas)==-1 ||
			employee_setSueldo(this,sueldo) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}
/** \brief _newParametrosTxt: Register an employee receiving the parameters as text.
 * \param char* id:  Receive the id in text form
 * \param char* nombre: Receive the name.
 * \param char* horasTrabajadas: Receive the worked hours in text form.
 * \param char* sueldo: Receive salary in text form.
 * \return The memory address of the employee with all his data loaded or NULL in case something went wrong.
 */
Employee* employee_newParametrosTxt(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && nombre != NULL && sueldo != NULL && id != NULL && horasTrabajadas != NULL)
	{
		if(	employee_setIdTxt(this,id) == -1 ||
			employee_setNombre(this,nombre) == -1 ||
			employee_setHorasTrabajadasTxt(this,horasTrabajadas) == -1 ||
			employee_setSueldoTxt(this,sueldo) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}
/** \brief _delete: Deletes an employee's reserved memory address.
 *  \param Employee* this: Pointer to employee.

 */
void employee_delete(Employee* this)
{
	free(this);
}
/*
 * \brief _setId: Load the id into the employee's field.
 * \param Employee* this : Pointer to employee.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getId: Obtains the employee's ID.
 * \param Employee* this : Pointer to employee.
 * \param int id: Pointer to the space where the obtained id will be stored
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setIdTxt: Load the id as text into the employee's field.
 * \param Employee* this : Pointer to employee.
 * \param int id: Id to load.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_setIdTxt(Employee* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
    {
        this->id = atoi(id);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getIdTxt: Obtains the employee's ID as text.
 * \param Employee* this : Pointer to employee.
 * \param char* id: Pointer to the space where the obtained id will be stored.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_getIdTxt(Employee* this, char* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->id);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setNombre: Load the name into the employee's field.
 * \param Employee* this : Pointer to employee.
 * \param char* nombre: Name to load.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_setNombre(Employee *this, char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL && isValidCompoundName(nombre, NOMBRE_LEN))
	{
		strncpy(this->nombre, nombre, NOMBRE_LEN);
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getNombre: Obtains the employee's name.
 * \param Employee* this : Pointer to employee.
 * \param char* nombre: Pointer to the space where the obtained name will be stored.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if (this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, NOMBRE_LEN);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setHorasTrabajadas: Load the worked hours into the employee's field.
 * \param Employee* this : Pointer to employee.
 * \param int horasTrabajadas: Worked hours to load.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getHorasTrabajadas: Obtains the employee's worked hours.
 * \param Employee* this : Pointer to employee.
 * \param int* horasTrabajadas: Pointer to the space where the obtained worked hours will be stored.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setHorasTrabajadasTxt: Load the worked hours as text into the employee's field.
 * \param Employee* this : Pointer to employee.
 * \param char* horasTrabajadas: Worked hours to load.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if (this != NULL && horasTrabajadas != NULL && isValidNumber(horasTrabajadas, sizeof(horasTrabajadas)))
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getHorasTrabajadasTxt: Obtains the employee's worked hours as text.
 * \param Employee* this : Pointer to employee.
 * \param char* horasTrabajadas: Pointer to the space where the obtained worked hours will be stored.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if (this != NULL && horasTrabajadas != NULL)
    {
        sprintf(horasTrabajadas, "%d", this->horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setSueldo: Load the salarys into the employee's field.
 * \param Employee* this : Pointer to employee.
 * \param float sueldo: Salary to load.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_setSueldo(Employee* this, float sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief _getSueldo: Obtains the employee's salary.
 * \param Employee* this : Pointer to employee.
 * \param float* sueldo: Pointer to the space where the obtained salary will be stored.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_getSueldo(Employee* this, float* sueldo)
{
    int retorno = -1;
    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _setSueldoTxt: Load the worked hours as text into the employee's field.
 * \param Employee* this : Pointer to employee.
 * \param char* sueldo: Salary to load.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_setSueldoTxt(Employee* this, char* sueldo)
{
    int retorno = -1;
    if (this != NULL && sueldo != NULL && isValidNumberFloat(sueldo, sizeof(sueldo)))
    {
        this->sueldo = atof(sueldo);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _getSueldoTxt: Obtains the employee's salary as text.
 * \param Employee* this : Pointer to employee.
 * \param char* sueldo: Pointer to the space where the obtained salary will be stored.
 * \return int (-1) ERROR - If pointer to Employee* is NULL \ (0) OK
 */
int employee_getSueldoTxt(Employee* this, char* sueldo)
{
    int retorno = -1;
    if (this != NULL && sueldo != NULL)
    {
        sprintf(sueldo, "%.2f", this->sueldo);
        retorno = 0;
    }
    return retorno;
}
/*
 * \brief _compareByName: Compare two employee names.
 * \param void* thisA: Pointer to the first employee to compare.
 * \param void* thisB: Pointer to the second employee to compare.
 * \return int (-1) If the first employee's name is less than the second. \(1) If the first employee's name is greater than the second.
 * 					   (0) If the names are the same.
 */
int employee_compareByName(void* thisA, void* thisB)
{
	int retorno = 0;
	Employee* pEmpleadoA = (Employee*)thisA;
	char bufferNombreA[NOMBRE_LEN];
	char bufferNombreB[NOMBRE_LEN];
	int respuestaStrCmp;

	if(thisA != NULL && thisB != NULL)
	{
		employee_getNombre(pEmpleadoA,bufferNombreA);
		employee_getNombre((Employee*)thisB,bufferNombreB);
		respuestaStrCmp=strcmp(bufferNombreA,bufferNombreB);
		if(respuestaStrCmp > 0)
		{
			retorno = 1;
		}
		else if(respuestaStrCmp < 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}
