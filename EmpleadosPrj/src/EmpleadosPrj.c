/*
 ============================================================================
 Name        : EmpleadosPrj.c
 Author      : mdangelo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "empl_libs/ArrayEmployees.h"
#include "empl_menu/EmployeesManager.h"

#define CREATE_EMPLOYEE 1
#define UPDATE_EMPLOYEE 2
#define DELETE_EMPLOYEE 3
#define MAKE_INFORM 4

#define SUCCESS 1
#define ERROR  -1

#define TRUE 1
#define FALSE 0
#define EMP_TOP 5




int main(void) {
	Employee employeesList[EMP_TOP];
	int status;

	initAllEmployees(employeesList, EMP_TOP);

	int userSelection = showMenuAndGetUserSelection();

	do{
		if(userSelection == CREATE_EMPLOYEE){
			status = createEmployee(employeesList, EMP_TOP);
		}else if(userSelection == UPDATE_EMPLOYEE){
			updateEmployee(employeesList, EMP_TOP);
		}else if(userSelection == DELETE_EMPLOYEE){
			deleteEmployeeById(employeesList, EMP_TOP);
		}
		userSelection = showMenuAndGetUserSelection();

	}while(userSelection==CREATE_EMPLOYEE || userSelection==UPDATE_EMPLOYEE || userSelection==DELETE_EMPLOYEE);

	if(userSelection == MAKE_INFORM) makeEmployeeInform(employeesList, EMP_TOP);

	return status;
}
