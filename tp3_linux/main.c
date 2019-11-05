#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


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

#include "Controller.h"
#include "Employee.h"
#include "file-libs/FileMng.h"

#include "menu-builder/MenuBuilder.h"

#define TRUE 1
#define FALSE 0

//User selection:
#define CHARGE_DATA_EMPLY_FROM_FILE_TXT 1


void _checkUserSelectionAndExecute(int usrSlct);

int main()
{
	int usrSlct = 0;

	do {
		mb_createMenuAndGetUsserSelection(&usrSlct);
		_checkUserSelectionAndExecute(usrSlct);
	} while (mb_isValidSelection(usrSlct)==TRUE);

	return 0;
}

void _checkUserSelectionAndExecute(int usrSlct){
	FILE *file = NULL;
	char filePath[12] = "./dataB.csv";
	char mode[3] = "r";
	int cant;
	Employee emp;

    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

	switch (usrSlct) {
		case CHARGE_DATA_EMPLY_FROM_FILE_TXT:
			file = fm_openAndGetFile(filePath, mode);
			while(!feof(file)){
				cant = fscanf(file,"%d,%[^,],%d,%d\n",&id,nombre,&horasTrabajadas,&sueldo);
				printf("\n%d\t%s\t%d\t%d\n",id,nombre, horasTrabajadas, sueldo);
			}
			fclose(file);
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

