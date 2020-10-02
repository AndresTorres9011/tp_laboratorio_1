/*
 * utn.c
 *
 *  Created on: 15/09/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define SIZE_NAME 51
#define QTY_EMPLOYEES 1000

typedef struct
{
	int id;
	char name[SIZE_NAME];
	char lastName[SIZE_NAME];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int employees_init(Employee* list, int len);
int employees_searchEmpty(Employee* list, int len, int *pIndex);
int employees_add(Employee* list,int len,int id,char* name,char* lastName,float salary,int sector);
int employee_createNew(Employee* list, int len);
int employee_findById(Employee* list, int len, int* pIndex, int id);
int employee_printById(Employee* list, int len,int index);
int employee_modifify(Employee* list,int len);
int employee_remove(Employee* list,int len);
int employee_printF(Employee* list, int limite);
int employees_sortBySector(Employee *list, int len, int order);
int employees_sortByLastName(Employee* list, int len, int order);
int employees_reporting(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
