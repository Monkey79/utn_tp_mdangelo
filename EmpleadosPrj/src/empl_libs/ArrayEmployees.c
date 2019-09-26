/*
 * ArrayEmployees.c
 *
 *  Created on: 22 sep. 2019
 *      Author: monkey
 */


#include <stdio.h>
#include <string.h>
#include "ArrayEmployees.h"

#define SUCCESS 0
#define ERROR -1

#define TRUE 0
#define FALSE 1

static int findFirstFreeEmpl(Employee employees[]){
	int found = FALSE;
	int i = 0;
	while((i < sizeof(employees)) && (found==FALSE)){
		found = (employees[i].isEmpty == TRUE);
		i++;
	}
	i = (found == FALSE)?-1:(i-1);
	return i;
}

int initEmployee(Employee employees[], int length) {
	int status = ERROR;
		if(employees!= NULL && (sizeof(employees) == length)){
			status = SUCCESS;
			for (int i = 0; i < length;i++) {
				employees[i].isEmpty = TRUE;
			}
		}

	return status;
}

int addEmployee(Employee employees[], int length, int id, char name[], char lastName[], float salary, int sector){
	int status = ERROR;
	int indx;
		if(employees!= NULL && (sizeof(employees) == length)){
			indx = findFirstFreeEmpl(employees);
			if(indx >= 0){
				status = SUCCESS;
				strcpy(employees[indx].name, name);
				strcpy(employees[indx].lastName, lastName);
				employees[indx].salary = salary;
				employees[indx].sector = sector;
			}
		}
	return status;
}

int findEMployeeById(Employee employees[], int length, int nId) {
	int found = FALSE;
	int i = 0;
	if(employees!= NULL && (sizeof(employees) == length)){
		while((i < sizeof(employees)) && (found==FALSE)){
			found = (employees[i].id == nId);
			i++;
		}
		i = (found == FALSE)?ERROR:(i-1);
	}
	return i;
}

int removeEmployee(Employee employees[], int length, int id) {
	int status = ERROR;
	int empId = -1;
	if(employees!= NULL && (sizeof(employees) == length)){
		empId = findEMployeeById(employees, length, id);
		if((empId >= 0) && (employees[empId].isEmpty==FALSE)){
			employees[empId].isEmpty = TRUE;
			status = SUCCESS;
		}
	}
	return status;
}

int sortEmployees(Employee employees[], int length, int order){
	int status = ERROR;
	int isDisrd = TRUE;
	Employee emplAUx;

	if(employees!= NULL && (sizeof(employees) == length)){
		while(isDisrd == TRUE){
			isDisrd = FALSE;
			for (int i = 0; i < length-1; i++) {
				if((strcmp(employees[i].lastName, employees[i+1].lastName)>0) &&(employees[i].sector>employees[i+1].sector)){
					emplAUx = employees[i];
					employees[i] = employees[i+1];
					employees[i+1] = emplAUx;
					isDisrd = TRUE;
				}
			}//end for
		}
		status = SUCCESS;
	}

	return status;
}

int printEmployees(Employee employees[], int length) {
	int status = ERROR;
	if(employees!= NULL && (sizeof(employees) == length)){
		for(int i=0; i< length; i++){
			printf("Empleado.id %i \n",employees[i].id);
			printf("Empleado.name %s \n",employees[i].name);
			printf("Empleado.lastName %s \n",employees[i].lastName);
			printf("Empleado.sector %i \n",employees[i].sector);
		}
	}
	return status;
}



