/*
 * Author: Mariano DAngelo
 * Purpose: Libreria para encargarse todo lo que refiere al menu del TP
 * Language:  C
 */
#include <stdio.h>
#include <stdio_ext.h>

struct UserInput {
	int iNum1;
	int iNum2;
	int iOptSelected;
};

void mBuildMenuAndSaveOpt(int iNum1, int iNum2, int *iOptSlctd){
	printf("\n******************************************************\n");
	printf("\n===================CALCULADORA=======================\n");
	printf("\n*****************************************************\n");
	printf("Please choose an option: \n");
	printf("1=Ingresar 1er operando: (valor anterior) %d \n", iNum1);
	printf("2=Ingresar 2do operando: (valor anterior) %d \n", iNum2);
	printf("3=Calcular todas las operaciones: \n");
	printf("4=Informar resultados: \n");
	printf("5=Salir: \n");
	printf("\n*****************************************************\n");
	printf("\n*****************************************************\n");
	__fpurge(stdin);
	scanf("%d", iOptSlctd);
}

void mAskForFirstANumber(int *iNum1) {
	printf("Ingrese el primer operando (debe ser un numero entero): \n");
	__fpurge(stdin);
	scanf("%d", iNum1);
}

void mAskForSecondtNumber(int *iNum2) {
	printf("Ingrese el segundo operando (debe ser un numero entero): \n");
	__fpurge(stdin);
	scanf("%d", iNum2);
}
