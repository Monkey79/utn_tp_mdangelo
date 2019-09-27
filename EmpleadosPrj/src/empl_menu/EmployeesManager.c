/*
 * EmplMenu.c
 *
 *  Created on: 23 sep. 2019
 *      Author: monkey
 */
#include<stdio.h>
#include<stdlib.h>

#include "../empl_libs/ArrayEmployees.h"


#define SUCCESS 1
#define ERROR  -1

#define TRUE 1
#define FALSE 0

int EMP_ID = 0;

void checkAndGetUpdatedValues(Employee emply);
void buildMenu();

static int isEmployeeCharged(Employee employees[], int length){
	int i = 0;
	int isEmpty = TRUE;
	while(i<length && isEmpty==TRUE){
		isEmpty = employees[i].isEmpty;
		i++;
	}
	if(isEmpty == FALSE){
		return TRUE;
	}else
		return FALSE;
}

int showMenuAndGetUserSelection(){
	int iOptSlct = -1;
	int notValid = TRUE;

	while(notValid == TRUE){
		buildMenu();
		scanf("%i",&iOptSlct);
		notValid =  (iOptSlct != 1 && iOptSlct != 2 && iOptSlct != 3 && iOptSlct != 4);
		if(notValid==TRUE)printf("\n ERROR:Opcion no valida recuerde valores entre 1 y 4 inclusive\n");
		printf("\n*===============================================*\n");
	};
	return iOptSlct;
}

int createEmployee(Employee employees[], int length){
	int status = ERROR;
	int salaryNotValid = TRUE;
	int sectorNotValid = TRUE;

	char empName[51];
	char empLName[51];
	float empSalr;
	int empSct;

	if(employees!= NULL && length>0){
		printf("\n=============Datos Empleado===================\n");
		printf("\n Ingrese nombre del empleado: \n");
		fgets(empName, length, stdin);
		printf("\n Ingrese apellido del empleado: \n");
		fgets(empLName, length, stdin);
		do{
			printf("\n Ingrese salario del empleado (solo valores mayores a cero) \n");
			scanf("%f", &empSalr);
			salaryNotValid = (empSalr<=0);
		}while(salaryNotValid == TRUE);

		do{
			printf("\n Ingrese sector del empleado (solo valores mayor o igual a 1) \n");
			scanf("%d",&empSct);
			sectorNotValid = (empSalr<=0);
		}while(sectorNotValid==TRUE);

		//se guarda llamando funcion addEmployee de ArrayEmpĺoyees.h
		status = addEmployee(employees, length, ++EMP_ID, empLName, empLName, empSalr, empSct);
		if(status == SUCCESS)printf("\n EXITO empleado guardado con exito!!\n");
	}
	return status;
}

int updateEmployee(Employee employees[], int length){
	int status = ERROR;
	int notFreeEmpId;
	int notFreeEmpIdx;

	if(employees!= NULL && length>0){
		if(isEmployeeCharged(employees, length) == TRUE){
			printf("\nIngrese el id del empleado que desea modificar: \n");
			scanf("%d",&notFreeEmpId);
			notFreeEmpIdx = findEMployeeById(employees, length, notFreeEmpId);
			if(notFreeEmpIdx < 0){
				printf("\n***ERROR: NO existe empleado con ese ID******\n");
			}else {
				checkAndGetUpdatedValues(employees[notFreeEmpIdx]);
				status = SUCCESS;
			}
		}else {
			printf("\n***ERROR: NO hay ningun empleado previamente cargado!!******\n");
		}
	}
	return status;
}

int deleteEmployee(Employee employees[], int length){
	int status = ERROR;
	int id;
	int empIdx;
	Employee empl;

	if(employees!= NULL && length>0){
		printf("\nIngrese el id del empleado que desea modificar: \n");
		scanf("%d",&id);
		empIdx = findEMployeeById(employees,length, id);
		if(empIdx<0){
			printf("\n No existe empleado con ese Id\n");
		}else{
			removeEmployee(employees, length, empIdx);
		}
	}
	return status;
}

//************Private******************************************
void checkAndGetUpdatedValues(Employee emply){
	char updName;
	char updLName;
	char updSlry;
	char updSect;

	//Nombre
	do{
		printf("\n Desea actualizar el nombre del empleado? (s|n)\n");
		scanf("%c", updName);
	}while(updName!='s' && updName!='n');
	printf("\nIngrese el nuevo nombre: \n");
	fgets(emply.name, 51, stdin);
	//Apellido
	do{
		printf("\n Desea actualizar el apelllido del empleado? (s|n)\n");
		scanf("%c", updLName);
	}while(updLName!='s' && updLName!='n');
	printf("\nIngrese el nuevo apellido: \n");
	fgets(emply.lastName, 51, stdin);

	//Salario
	do{
		printf("\n Desea actualizar el salario del empleado? (s|n)\n");
		scanf("%c", updSlry);
	}while(updSlry!='s' && updSlry!='n');
	do{
		printf("\nIngrese el nuevo salario (solo valores mayores a cero): \n");
		scanf("%f", &emply.salary);
	}while(emply.salary<=0);

	//Sector
	do{
		printf("\n Desea actualizar el sector del empleado? (s|n)\n");
		scanf("%c", updSect);
	}while(updSect!='s' && updSect!='n');
	do{
		printf("\nIngrese el nuevo sector: (solo valores mayor o igual a 1)\n");
		scanf("%f", &emply.sector);
	}while(emply.sector<1);

}

void buildMenu(){
	printf("\n*===========================================**\n");
	printf("\n             Employee Menu                    \n");
	printf("\n*============================================*\n");
	printf("\n 1-ALTAS \n");
	printf("\n 2-MODIFICAR \n");
	printf("\n 3-BAJA \n");
	printf("\n 4-INFORMAR \n");
}

