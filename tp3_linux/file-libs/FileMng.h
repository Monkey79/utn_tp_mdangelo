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
int fm_getRecord(FILE * ptFile,char *pattern, char *iValue1, char *strValue2, char *iVal3, char *iVal4, int *firstRecord);
int fm_closeFile(FILE * ptFile);

#endif /* FILE_LIBS_FILEMNG_H_ */
