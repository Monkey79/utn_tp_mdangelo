/*
 * FileMng.c
 *
 *  Created on: 2 nov. 2019
 *      Author: monkey
 */
#include <stdio.h>
#include <stdlib.h>

#define FILE_ERROR_MSSG "\nError: El archivo no existes o no puede ser abierto\n"

#define SUCCESS 10
#define ERROR -10

#define TRUE 1
#define FALSE 0

FILE *fm_openAndGetFile(char *filePath, char *mode){
	FILE * theFilePtr = NULL;
	theFilePtr = fopen(filePath, mode);
	if(theFilePtr==NULL){
		printf(FILE_ERROR_MSSG);
		fclose(theFilePtr);
	}
	return theFilePtr;
}

int fm_getRecord(FILE * ptFile,char *pattern, int *iValue1, char *strValue2, int *iVal3, int *iVal4, int *firstRecord){
	char aux[33];
	int cant;
	if(*firstRecord==TRUE){
		fgets(aux,33,ptFile);
		*firstRecord = FALSE;
	}
	cant = fscanf(ptFile,pattern,iValue1,strValue2,iVal3,iVal4);
	if(cant==4){
		printf("-ok-reg:->\n%d\t%s\t%d\t%d\n",*iValue1,strValue2,*iVal3,*iVal4);
	}
	return cant;
}


