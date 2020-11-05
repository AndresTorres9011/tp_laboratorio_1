#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validations.h"

Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

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

void employee_delete(Employee* this)
{
	free(this);
}

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
