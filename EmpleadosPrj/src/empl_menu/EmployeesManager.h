/*
 * EmplMenu.h
 *
 *  Created on: 23 sep. 2019
 *      Author: monkey
 */

#ifndef EMPL_MENU_EMPLOYEESMANAGER_H_
#define EMPL_MENU_EMPLOYEESMANAGER_H_
	#include "../empl_libs/ArrayEmployees.h"

	int initAllEmployees(Employee employees[], int length);
	//Purpose: Construye el menu y valida que la seleccion del usuario este dentro de lo esperado
	int showMenuAndGetUserSelection();
	//Purpose: Crea un empleado en la primera posicion libre que encuentre (isEmpty=TRUE)
	int createEmployee(Employee employees[], int length);
	//Purpose: Actualiza un empleado pidiendo el ID de ese empleado
	int updateEmployee(Employee employees[], int length);
	//Purpose: Elimina un empleado pidiendo el ID de ese empleado
	int deleteEmployeeById(Employee employees[], int length);
	//Purpose: Ordena la lista de empleados por apellido y sector en forma ascendente=1
	//y descendente=0. Por defecto se ordena en forma ascendente.
	int makeEmployeeInform(Employee employees[], int length);



#endif /* EMPL_MENU_EMPLOYEESMANAGER_H_ */
