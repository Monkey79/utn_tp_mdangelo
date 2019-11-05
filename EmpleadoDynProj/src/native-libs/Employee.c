#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"

#define CREATION_ERROR_MSSG "\nNo fue posible crear al Empleado\n"

Employee* employee_new() {
	Employee *empAux = NULL;
	empAux = (Employee*) malloc(sizeof(Employee));
	if (empAux == NULL) {
		printf(CREATION_ERROR_MSSG);
	}
	return empAux;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,char *horasTrabajadasStr,char* sueldo) {
	Employee *empAux = NULL;
	empAux = (Employee*) malloc(sizeof(Employee));
	if(empAux != NULL){
		empAux->id = atoi(idStr);
		strcpy(empAux->nombre, nombreStr);
		empAux->horasTrabajadas = atoi(horasTrabajadasStr);
		empAux->sueldo = atoi(sueldo);
	}else {
		printf(CREATION_ERROR_MSSG);
	}
	return empAux;
}


