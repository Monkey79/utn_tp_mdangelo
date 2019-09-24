/*
 * EmplMenu.c
 *
 *  Created on: 23 sep. 2019
 *      Author: monkey
 */

#define SUCCESS 0
#define ERROR -1

#define TRUE 1;
#define FALSE 0;

int showEmmplMenu(int *iOptSlct){
	int status = ERROR;
	int notValid = TRUE;
		while(notValid == TRUE){
			printf("\n**********Employee Menu**************\n");
			printf("\n**********Employee Menu**************\n");
			printf("\n**************************************\n");
			printf("\n 1-ALTAS \n");
			printf("\n 2-MODIFICAR \n");
			printf("\n 3-BAJA \n");
			printf("\n 4-INFORMAR \n");
			scanf("%i",iOptSlct);
			notValid = iOptSlc;
		}

	return status;
}

