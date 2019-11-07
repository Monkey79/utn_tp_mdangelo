/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "file-libs/FileMng.h"
#include "menu-builder/MenuBuilder.h"

#define TRUE 1
#define FALSE 0

//User selection:
#define CHARGE_DATA_EMPLY_FROM_FILE_TXT 1
#define WRITE_DATA_EMPLY_TO_FILE_TXT 8

void _checkUserSelectionAndExecute(int usrSlct,LinkedList *pArrayListEmployee);

int main()
{
	int usrSlct = 0;
	LinkedList *pArrayListEmployee = ll_newLinkedList();


	do {
		mb_createMenuAndGetUsserSelection(&usrSlct);
		_checkUserSelectionAndExecute(usrSlct,pArrayListEmployee);
	} while (mb_isValidSelection(usrSlct)==TRUE);

	return 0;
}

void _checkUserSelectionAndExecute(int usrSlct,LinkedList *pArrayListEmployee){
	char filePath[25] = "./assets/data3.csv";
	char filePathWrite[25] = "./assets/dataWrt.csv";

	switch (usrSlct) {
		case CHARGE_DATA_EMPLY_FROM_FILE_TXT:
			controller_loadFromText(filePath,pArrayListEmployee);
			break;
		case WRITE_DATA_EMPLY_TO_FILE_TXT:
			controller_saveAsText(filePathWrite,pArrayListEmployee);
			break;
		default:
			break;
	}
}




/*
int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}*/

