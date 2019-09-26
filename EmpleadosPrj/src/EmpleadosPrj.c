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

int main(void) {
	Employee employeesList[1000];


	int userSelection = showMenuAndGetUserSelection();

	if(userSelection == CREATE_EMPLOYEE)






	return EXIT_SUCCESS;
}
