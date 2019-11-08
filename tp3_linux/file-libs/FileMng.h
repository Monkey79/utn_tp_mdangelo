/*
 * FIleMng.h
 *
 *  Created on: 31 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef FILE_LIBS_FILEMNG_H_
#define FILE_LIBS_FILEMNG_H_

FILE *fm_openAndGetFile(char *filePath, char *mode);
int fm_getRecord(FILE * ptFile,char *pattern, char *strValue1, char *strValue2, char *strValue3, char *strValue4, int *firstRecord);
int fm_closeFile(FILE * ptFile);
int fm_writeRow(char *openMask,int iVal1, char* strVal2, int iVal3, int iVal4, FILE *pFile);

#endif /* FILE_LIBS_FILEMNG_H_ */
