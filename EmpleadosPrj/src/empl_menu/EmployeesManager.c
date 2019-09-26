/*
 * EmplMenu.c
 *
 *  Created on: 23 sep. 2019
 *      Author: monkey
 */
#include<stdio.h>
#include<stdlib.h>

#include "../empl_libs/ArrayEmployees.h"


#define SUCCESS 100
#define ERROR  -100

#define TRUE 1
#define FALSE 0

static void buildMenu(){
	printf("\n*===========================================**\n");
	printf("\n             Employee Menu                    \n");
	printf("\n*============================================*\n");
	printf("\n 1-ALTAS \n");
	printf("\n 2-MODIFICAR \n");
	printf("\n 3-BAJA \n");
	printf("\n 4-INFORMAR \n");
}

int showMenuAndGetUserSelection(){
	int iOptSlct = -1;
	int notValid = TRUE;

	while(notValid == TRUE){
		buildMenu();
		scanf("%i",iOptSlct);
		notValid =  (*iOptSlct != 1 && *iOptSlct != 2 && *iOptSlct != 3 && *iOptSlct != 4);
		if(notValid==TRUE)printf("\n ERROR:Opcion no valida recuerde valores entre 1 y 4 inclusive\n");
		printf("\n*===============================================*\n");
	};
	return iOptSlct;
}

int isAlreadyChargedEmployee(Employee employees[], int length, int *isChrgd) {
	int status = ERROR;
	int isEmpt = FALSE;
	int i = 0;

	if(employees!= NULL && length>0){
		while(i<length && isEmpt==FALSE){
			isEmpt = (employees[i].isEmpty == TRUE);
			i++;
		}
	}
	isChrgd = isEmpt;
	return status;
}

