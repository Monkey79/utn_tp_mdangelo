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
#define SHOW_ALL_EMPLOYEE 4

#define SUCCESS 1
#define ERROR  -1

#define TRUE 1
#define FALSE 0
#define EMP_TOP 1000




int main(void) {
	Employee employeesList[EMP_TOP];


	int userSelection = showMenuAndGetUserSelection();

	/*if(userSelection == CREATE_EMPLOYEE){
		createEmployee(employeesList, EMP_TOP);
	}else if(userSelection == UPDATE_EMPLOYEE){
		updateEmployee(employeesList, EMP_TOP);
	}else if(userSelection == DELETE_EMPLOYEE){
		removeEmployee(employeesList, EMP_TOP);
	}*/

	return EXIT_SUCCESS;
}
