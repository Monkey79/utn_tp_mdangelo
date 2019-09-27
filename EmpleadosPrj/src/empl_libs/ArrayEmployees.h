/*
 * ArrayEmployees.h
 *
 *  Created on: 22 sep. 2019
 *      Author: monkey
 */

#ifndef EMPL_LIBS_ARRAYEMPLOYEES_H_
#define EMPL_LIBS_ARRAYEMPLOYEES_H_

struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

	int findFirstFreeEmpl(Employee employees[],int length);
	int initEmployee(Employee employees[], int length);
	int addEmployee(Employee employees[], int length, int id, char name[], char lastName[], float salary, int sector);
	int findEMployeeById(Employee employees[], int length, int id);
	int removeEmployee(Employee employees[], int length, int id);
	int sortEmployees(Employee employees[], int length, int order);
	int printEmployees(Employee employees[], int length);

#endif /* EMPL_LIBS_ARRAYEMPLOYEES_H_ */
