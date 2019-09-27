/*
 * EmplMenu.h
 *
 *  Created on: 23 sep. 2019
 *      Author: monkey
 */

#ifndef EMPL_MENU_EMPLOYEESMANAGER_H_
#define EMPL_MENU_EMPLOYEESMANAGER_H_

	#include "../empl_libs/ArrayEmployees.h"


	//Purpose: Construye el menu y valida que la seleccion del usuario este dentro de lo esperado
	int showMenuAndGetUserSelection();
	//Purpose: Crea un empleado en la primera posicion libre que encuentre (isEmpty=TRUE)
	int createEmployee(Employee employees[], int length);
	//Purpose: Actualiza un empleado pidiendo el ID de ese empleado
	int updateEmployee(Employee employees[], int length);
	int deleteEmployee(Employee employees[], int length);



#endif /* EMPL_MENU_EMPLOYEESMANAGER_H_ */
