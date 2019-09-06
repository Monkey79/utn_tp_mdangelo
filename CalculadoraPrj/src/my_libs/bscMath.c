/*
 * Author: Mariano DAngelo
 * Purpose: Libreria para encargarse todo lo que refiere a op matematicas para el TP
 * Language:  C
 */
#include <stdio.h>

#define DIVER_ERROR "****ERROR!! En la division el divisor NO puede ser cero*****\n"
#define FACTORIAL_ERROR "****ERROR!! Para el factorial este numero debe ser mayor o igual a cero*****\n"

#define FALSE -1
#define TRUE 1

static int greaterThanZero(int iNum){
	int greater = TRUE;
	if(iNum <= 0)
		greater = FALSE;
	return greater;
}

int bscAddNumbers(int iNum1, int iNum2){
	return (iNum1 + iNum2);
}
int bscSubtractNumbers(int iNum1, int iNum2){
	return (iNum1 - iNum2);
}
int bscMultiplyNumbers(int iNum1, int iNum2){
	return (iNum1 * iNum2);
}
float bscDivideNumber(int iNum1, int iNum2){
	float result = 0.0f;
	if(greaterThanZero(iNum2)==TRUE){
		result = iNum1 / (float)iNum2;
	}else {
		printf(DIVER_ERROR);
		return 0.0f;
	}
	return result;
}
int bscfactorialNumber(int iNum1){
	int iResult = 1;
	if(greaterThanZero(iNum1)==TRUE){
		for(int i = iNum1; i>0;i--){
			iResult = iResult*iNum1;
		}
	}else{
		printf(FACTORIAL_ERROR);
		iResult = 0;
	}
	return iResult;
}

