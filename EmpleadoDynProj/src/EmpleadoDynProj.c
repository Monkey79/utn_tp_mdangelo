/*
 ============================================================================
 Name        : EmpleadoDynProj.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
     Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "native-libs/Controller.h"
#include "native-libs/Employee.h"
#include "file-mng/FIleMng.h"
#include "menu-builder/MenuBuilder.h"

#define TRUE 1
#define FALSE 0
#define CHARGE_DATA_EMPLY_FROM_FILE_TXT 1

void _checkUserSelectionAndExecute(int usrSlct);

int main(void) {
	int usrSlct = 0;

	do {
		mb_createMenuAndGetUsserSelection(&usrSlct);
		_checkUserSelectionAndExecute(usrSlct);
	} while (mb_isValidSelection(usrSlct)==TRUE);

	return 0;
}

void _checkUserSelectionAndExecute(int usrSlct){
	FILE *file = NULL;
	char filePath[25] = "./assets/data.csv";
	char mode[3] = "r";
	Employee *emp;
    char aux[33];

	int cant;
    char patter[17] ="%d,%[^,],%d,%d\n";
    char empId[20];
    char empName[128];
    char empHrsJob[20];
    char empSalary[20];
    int firstRecord = TRUE;

	switch (usrSlct) {
		case CHARGE_DATA_EMPLY_FROM_FILE_TXT:
			file = fm_openAndGetFile(filePath,mode);
			if(file != NULL){
				while(!feof(file)){
					cant = fm_getRecord(file,patter, empId, empName, empHrsJob, empSalary, &firstRecord);
					if(cant==4){
						emp = employee_newParametros(empId, empName,empHrsJob,empSalary);
					}else{

					}
				}
			}
			fgets(aux,33,file);
			while(!feof(file)){
				cant = fscanf(file,"%d,%[^,],%d,%d\n",&emp.id,emp.nombre,&emp.horasTrabajadas,&emp.sueldo);

			}
			fclose(file);
			break;
		default:
			break;
	}
}
