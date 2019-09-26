/*
 * EmplMenu.h
 *
 *  Created on: 23 sep. 2019
 *      Author: monkey
 */

#ifndef EMPL_MENU_EMPLOYEESMANAGER_H_
#define EMPL_MENU_EMPLOYEESMANAGER_H_

	#include "../empl_libs/ArrayEmployees.h"

	/*
	 * Author: mdangelo
	 * Purpose: Construye el menu y valida que la seleccion del usuario
	 */
	int showMenuAndGetUserSelection();
	/*
	 * Author: mdangelo
	 * Purpose: Chequea que exista algun empleado previamente cargado (que su bandera isEmpty=TRUE)
	 * ni bien encuentra uno se detiene y devuelve TRUE caso opuesto FALSE
	 */
	int isAlreadyChargedEmployee(Employee employees[], int length, int *isChrgd);

	int createEmployee(Employee employees[], int length);


#endif /* EMPL_MENU_EMPLOYEESMANAGER_H_ */
