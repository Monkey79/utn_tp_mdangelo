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

int fm_getRecord(FILE * ptFile,char *pattern, char *strValue1, char *strValue2, char *strValue3, char *strValue4, int *firstRecord){
	char aux[33];
	int cant;
	if(*firstRecord==TRUE){
		fgets(aux,33,ptFile);
		*firstRecord = FALSE;
	}
	cant = fscanf(ptFile,pattern,strValue1,strValue2,strValue3,strValue4);
	if(cant==4){
		//printf("-ok-reg:->\n%d\t%s\t%d\t%d\n",*strValue1,strValue2,*strValue3,*strValue4);
	}
	return cant;
}

int fm_closeFile(FILE * ptFile){
	return fclose(ptFile);
}

int fm_writeRow(char *openMask,int iVal1, char* strVal2, int iVal3, int iVal4, FILE *pFile){
	int status = ERROR;
	int cantResult = fprintf(pFile, openMask, iVal1, strVal2,iVal3, iVal4);
	printf("\ncantResult %d ", cantResult);
	status = (cantResult==4)?SUCCESS:ERROR;
	return status;
}
