#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "file-libs/FileMng.h"

#define TRUE 1
#define FALSE 0
#define ERROR -100
#define SUCCESS 100


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {
	int status = ERROR;
	char patter[17] ="%d,%[^,],%d,%d\n";
	int firstRecord = TRUE;
	int cant;

	Employee *emp;
	char empIdStr[20];
	char empNameStr[128];
	char empHrsJobStr[20];
	char empSalaryStr[20];

	if(pFile != NULL){
			while(!feof(pFile)){
				cant = fm_getRecord(pFile,patter, empIdStr, empNameStr, empHrsJobStr, empSalaryStr, &firstRecord);
				if(cant==4){
					emp = employee_newParametros(empIdStr, empNameStr,empHrsJobStr,empSalaryStr);
					printf("\n Emp.ID %d", emp->id);
					printf("\n Emp.NOMBRE %s", emp->nombre);
					printf("\n Emp.HorasTrag %d", emp->horasTrabajadas);
					printf("\n Emp.Sueldo %d\n", emp->sueldo);
					status = ll_add(pArrayListEmployee, emp);
					printf("\n STATUS_LL-ADD %d", status);
				}else{
					printf("\n error \n");
				}
			}
		}

	return status;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
