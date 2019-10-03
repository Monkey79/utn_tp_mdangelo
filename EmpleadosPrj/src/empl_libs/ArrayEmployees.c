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

#define TRUE  1
#define FALSE 0

void orderAsc(Employee employees[], int length);
void orderDesc(Employee employees[], int length);
void swapEmpl(Employee *empl1, Employee *empl2);

int findFirstFreeEmpl(Employee employees[],int length){
	int notEmpty = TRUE;
	int i = 0;
	do{
		notEmpty = (employees[i].isEmpty  == FALSE);
		i++;
	}while((i < length) && notEmpty==TRUE);
	i = (notEmpty == TRUE)?-1:(i-1);
	return i;
}

int initEmployee(Employee employees[], int length) {
	int status = ERROR;
		if(employees!= NULL && length>0){
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
		if(employees!= NULL && length>0){
			indx = findFirstFreeEmpl(employees, length);
			if(indx >= 0){
				status = SUCCESS;
				employees[indx].id = id;
				strcpy(employees[indx].name, name);
				strcpy(employees[indx].lastName, lastName);
				employees[indx].salary = (float)salary;
				employees[indx].sector = sector;
				employees[indx].isEmpty = FALSE;
			}
		}
	return status;
}

int findEMployeeById(Employee employees[], int length, int nId) {
	int found = FALSE;
	int i = 0;
	if(employees!= NULL && length>0){
		while((i < length) && found==FALSE){
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
	if(employees!= NULL && length>0){
		empId = findEMployeeById(employees, length, id);
		if((empId >= 0) && (employees[empId].isEmpty==FALSE)){
			employees[empId].isEmpty = TRUE;
			status = SUCCESS;
			printf("\nEXITO. Se borro al empleado %s \n", employees[empId].name);

		}else{
			printf("\n No existe empleado con ese Id\n");
		}
	}
	return status;
}

int sortEmployees(Employee employees[], int length, int order){
	int status = ERROR;
	if(employees!= NULL && length>0){
		if(order==1)
			orderAsc(employees, length);
		else if(order == 0)
			orderDesc(employees, length);
		status = SUCCESS;
	}
	return status;
}

int printEmployees(Employee employees[], int length) {
	int status = ERROR;
	Employee empl;

	if(employees!= NULL && length>0){
		for(int i=0; i< length; i++){
			empl = employees[i];
			if(empl.isEmpty == 0){
				printf("\n*********Empleado************\n");
				printf("Empleado.ID::%d \n", empl.id);
				printf("Empleado.nombre::%s\n", empl.name);
				printf("Empleado.apellido::%s\n", empl.lastName);
				printf("Empleado.salario::%f\n", empl.salary);
				printf("Empleado.sector::%d\n", empl.sector);
				printf("\n******************************\n");
			}
		}
	}
	return status;
}
/**********Private Functions************************************/
void orderAsc(Employee employees[], int length){
	printf("\n==ORD ASC===\n");
	int isDisrd = TRUE;
	int lstNmStrCmpr;
	Employee emplAUx;

	while(isDisrd == TRUE){
		isDisrd = FALSE;
		for (int i = 0; i < length-1; i++) {
			lstNmStrCmpr = strcmp(employees[i].lastName, employees[i+1].lastName);
			if(lstNmStrCmpr == 0){
				if(employees[i].sector > employees[i+1].sector) {
					emplAUx = employees[i];
					employees[i] = employees[i+1];
					employees[i+1] = emplAUx;
					isDisrd = TRUE;
				}
			}else if(lstNmStrCmpr > 0){
				emplAUx = employees[i];
				employees[i] = employees[i+1];
				employees[i+1] = emplAUx;
				isDisrd = TRUE;
			}
		}//end for
	}
}

void orderDesc(Employee employees[], int length){
	printf("\n==ORD DESC===\n");
	int isDisrd = TRUE;
	int lstNmStrCmpr;
	Employee emplAUx;

	while(isDisrd == TRUE){
		isDisrd = FALSE;
		for (int i = 0; i < length-1; i++) {
			lstNmStrCmpr = strcmp(employees[i].lastName, employees[i+1].lastName);
			if(lstNmStrCmpr == 0){
				if(employees[i].sector < employees[i+1].sector){
					emplAUx = employees[i];
					employees[i] = employees[i+1];
					employees[i+1] = emplAUx;
					isDisrd = TRUE;
				}
			}else if(lstNmStrCmpr<0){
				emplAUx = employees[i];
				employees[i] = employees[i+1];
				employees[i+1] = emplAUx;
				isDisrd = TRUE;
			}
		}//end for
	}
}
