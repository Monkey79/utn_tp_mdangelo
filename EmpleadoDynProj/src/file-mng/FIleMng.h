/*
 * FIleMng.h
 *
 *  Created on: 2 nov. 2019
 *      Author: monkey
 */

#ifndef FILE_MNG_FILEMNG_H_
#define FILE_MNG_FILEMNG_H_

FILE *fm_openAndGetFile(char *filePath, char *mode);
int fm_getRecord(FILE * ptFile,char *pattern, char *iValue1, char *strValue2, char *iVal3, char *iVal4, int *firstRecord);

#endif /* FILE_MNG_FILEMNG_H_ */
