/*
 * EmplMenu.c
 *
 *  Created on: 23 sep. 2019
 *      Author: monkey
 */
#include<stdio.h>
#include<stdlib.h>
#include <stdio_ext.h>

#include "../empl_libs/ArrayEmployees.h"


#define SUCCESS 0
#define ERROR  -1

#define TRUE 1
#define FALSE 0

int EMP_ID = 0;

void checkAndGetUpdatedValues(Employee emply);
int calcTotalAndAverageSalary(Employee employees[], int length);
int sortMyEmployees(Employee employees[], int length);
int showMyEMployees(Employee employees[], int length);
int removeEmployeById(Employee employees[], int length, int id);
void buildMenu();

int initAllEmployees(Employee employees[], int length){
	int status = ERROR;
	if(employees!= NULL && length>0){
		status = initEmployee(employees, length);
	}
	return status;
}

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

	//employee's info
	char empName[51];
	char empLName[51];
	float empSalr;
	int empSct;

	if(employees!= NULL && length>0){
		printf("\n=============Datos Empleado===================\n");
		__fpurge(stdin);
		printf("\n Ingrese nombr del empleado: \n");
		fgets(empName, 51, stdin);
		__fpurge(stdin);
		printf("\n Ingrese apellido del empleado: \n");
		fgets(empLName, 51, stdin);
		do{
			printf("\n Ingrese salario del empleado (solo valores mayores a cero) \n");
			scanf("%f", &empSalr);
			salaryNotValid = (empSalr<=0);
		}while(salaryNotValid == TRUE);
		do{
			printf("\n Ingrese sector del empleado (solo valores mayor o igual a 1) \n");
			scanf("%d",&empSct);
			sectorNotValid = (empSct<=0);
		}while(sectorNotValid==TRUE);
		status = addEmployee(employees, length, ++EMP_ID, empName, empLName, empSalr, empSct);
		if(status == SUCCESS) printf("\n**EXITO: Empleado guardado con exito****\n");
	}
	return status;
}

int updateEmployee(Employee employees[], int length){
	int status = ERROR;
	int notFreeEmpId;
	int notFreeEmpIdx;

	if(employees!= NULL && length>0){
		if(isEmployeeCharged(employees, length) == TRUE){
			printf("\nIngrese el id del empleado que desea modificar:\n");
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

int deleteEmployeeById(Employee employees[], int length){
	int status = ERROR;
	int id;

	if(employees!= NULL && length>0){
		printf("\nIngrese el id del empleado que desea borrar: \n");
		scanf("%d",&id);
		status = removeEmployee(employees, length, id);
	}
	return status;
}

int makeEmployeeInform(Employee employees[], int length){
	int status = ERROR;
	if(employees!= NULL && length>0){
		status = sortMyEmployees(employees, length);
		status = showMyEMployees(employees, length);
		status = calcTotalAndAverageSalary(employees, length);
	}
	return status;
}

//************Private******************************************
int calcTotalAndAverageSalary(Employee employees[], int length){
	int status = ERROR;
	Employee empl;
	float salaryTot = 0.0;
	int salaryCnt=0;
	float emplSlryAvrg=0.0;
	int emplSlaryAvrgCnt=0;

	if(employees!= NULL && length>0) {
		status = SUCCESS;
		for(int i=0; i< length; i++){
			empl = employees[i];
			if(empl.isEmpty == FALSE){
				salaryTot += empl.salary;
				salaryCnt++;
			}
		}
		emplSlryAvrg = (salaryTot / salaryCnt);

		for(int e=0; e< length; e++){
			empl = employees[e];
			if(empl.isEmpty == FALSE){
				if(empl.salary > emplSlryAvrg)
					emplSlaryAvrgCnt++;
			}
		}
	}
	printf("\n*************Datos de todos los empleados****************\n");
	printf("\nEl total de los salarios de todos los empleados es de %f",salaryTot);
	printf("\nEl promedio de los salarios de todos los empleados es de %f",emplSlryAvrg);
	printf("\nLa cantidad de empleados que superan este promedio es de %d",emplSlaryAvrgCnt);
	printf("\n********************************************************");
	return status;
}
int sortMyEmployees(Employee employees[], int length){
	int status = ERROR;
	status = sortEmployees(employees, length, 1);
	return status;
}
int showMyEMployees(Employee employees[], int length){
	int status = ERROR;
	status = printEmployees(employees, length);
	return status;
}

void checkAndGetUpdatedValues(Employee emply){
	char updName;
	char updLName;
	char updSlry;
	char updSect;

	//Nombre
	__fpurge(stdin);
	do{
		printf("\n Desea actualizar el nombre del empleado (s|n)? [antes: %s]\n",emply.name);
		scanf("%c", &updName);
	}while(updName!='s' && updName!='n');
	if(updName=='s'){
		printf("\nIngrese el nuevo nombre: \n");
		fgets(emply.name, 51, stdin);
	}

	//Apellido
	__fpurge(stdin);
	do{
		printf("\n Desea actualizar el apelllido del empleado (s|n) ? [antes: %s]\n", emply.lastName);
		scanf("%c", &updLName);
	}while(updLName!='s' && updLName!='n');
	if(updLName=='s'){
		printf("\nIngrese el nuevo apellido: \n");
		fgets(emply.lastName, 51, stdin);
	}
	//Salario
	__fpurge(stdin);
	do{
		printf("\n Desea actualizar el salario del empleado (s|n)? [antes: %f]\n",emply.salary);
		scanf("%c", &updSlry);
	}while(updSlry!='s' && updSlry!='n');
	if(updSlry=='s'){
		do{
			printf("\nIngrese el nuevo salario (solo valores mayores a cero):\n");
			scanf("%f", &emply.salary);
		}while(emply.salary<=0);
	}
	//Sector
	__fpurge(stdin);
	do{
		printf("\n Desea actualizar el sector del empleado (s|n)? [antes: %d]\n", emply.sector);
		scanf("%c", &updSect);
	}while(updSect!='s' && updSect!='n');
	if(updSect=='s'){
		do{
			printf("\nIngrese el nuevo sector: (solo valores mayor o igual a 1) \n");
			scanf("%d", &emply.sector);
		}while(emply.sector<1);
	}

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

