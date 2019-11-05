/*
 * FileMng.c
 *
 *  Created on: 31 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

#define FILE_ERROR_MSSG "\nError: El archivo no existes o no puede ser abierto\n"

#define SUCCESS 10
#define ERROR -10

FILE *fm_openAndGetFile(char *filePath, char *mode){
	FILE * theFilePtr = NULL;
	theFilePtr = fopen(filePath, mode);
	if(theFilePtr==NULL){
		printf(FILE_ERROR_MSSG);
	}
	return theFilePtr;
}



