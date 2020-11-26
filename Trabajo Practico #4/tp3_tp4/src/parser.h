/*
 * parser.h
 *
 *  Created on: 3/11/2020
 *      Author: Vivi Herrera
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);

