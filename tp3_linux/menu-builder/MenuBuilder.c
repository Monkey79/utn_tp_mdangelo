/*
 * MenuBuilder.c
 *
 *  Created on: 30 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

#define MENU_ITEM_1 "1-Cargar datos de empleado desde archivo csv (modo texto)"
#define MENU_ITEM_2 "2-Cargar datos de empleado desde archivo csv (modo binario)"

#define MENU_ITEM_3 "3-Alta Empleado"
#define MENU_ITEM_4 "4-Modificar Empleado"
#define MENU_ITEM_5 "5-Baja Empleado"
#define MENU_ITEM_6 "6-Listar Empleados"
#define MENU_ITEM_7 "7-Ordenar Empleados"
#define MENU_ITEM_8 "8-Guardar datos empleados en archivo csv (modo texto)"
#define MENU_ITEM_9 "9-Guardar datos empleados en archivo csv (modo binario)"

#define MENU_ITEM_EXIT "10-SALIR"
#define VALID_USR_SLCT 9

#define TRUE 1
#define FALSE 0

void _showMenuHeader();
void _showMenuFooter();
void _showMenuItems();

void mb_createMenuAndGetUsserSelection(int *usrSlct){
	_showMenuHeader();
	_showMenuItems();
	_showMenuFooter();
	__fpurge(stdin);
	scanf("%d",usrSlct);
}

int mb_isValidSelection(int usrSlct){
	int result = (usrSlct<=VALID_USR_SLCT);
	return result;
}

//**************Private functions**************
void _showMenuHeader(){
	printf("***************************************************************\n");
	printf("*\t\t\tMenu (elija una opcion)\t\t\t*\n*");
	printf("****************************************************************\n");
}
void _showMenuItems() {
	printf("%s \n",MENU_ITEM_1);
	printf("%s \n",MENU_ITEM_2);
	printf("%s \n",MENU_ITEM_3);
	printf("%s \n",MENU_ITEM_4);
	printf("%s \n",MENU_ITEM_5);
	printf("%s \n",MENU_ITEM_6);
	printf("%s \n",MENU_ITEM_7);
	printf("%s \n",MENU_ITEM_8);
	printf("%s \n",MENU_ITEM_9);
	printf("%s \n",MENU_ITEM_EXIT);
}
void _showMenuFooter(){
	printf("****************************************************************\n");
}
