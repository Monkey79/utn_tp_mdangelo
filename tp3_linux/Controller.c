#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "file-libs/FileMng.h"

#define TRUE 1
#define FALSE 0
#define ERROR -100
#define SUCCESS 100


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {
	int status = ERROR;
	FILE *file = NULL;
	char mode[3] = "r"; //r= read text-mode
	file = fm_openAndGetFile(path,mode);

	if(file != NULL){
		printf("\ncomo estaba linke-list %d \n", ll_len(pArrayListEmployee));
		status = parser_EmployeeFromText(file, pArrayListEmployee);
		printf("\ncomo quedo linke-list %d \n", ll_len(pArrayListEmployee));
	}
    return status;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {
	int status = ERROR;
	FILE *pFileWrt = NULL;
	Employee *empl=NULL;

	char mode[3] = "w"; //W= write text-mode
	char openMask[50] ="%d,%s,%d,%d\n";
	int emplCant = 0;

	pFileWrt = fm_openAndGetFile(path,mode);

	if(pFileWrt != NULL){
		emplCant = ll_len(pArrayListEmployee);
		if(emplCant>0){
			for(int i=0 ; i<emplCant; i++){
				empl = ll_get(pArrayListEmployee, i);
				printf("\nemp.id %d",empl->id);
				printf("\nemp.nombre %s",empl->nombre);
				printf("\nemp.horas %d",empl->horasTrabajadas);
				printf("\nemp.salario %d\n",empl->sueldo);

				status = fm_writeRow(empl->id, empl->nombre, empl->horasTrabajadas, empl->sueldo, pFileWrt);

				printf("\n write status=%d ", status);
			}
		}else{
			printf("\n Error: NO hay nada para escribir\n");
		}

	}
	fm_closeFile(pFileWrt);
    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

