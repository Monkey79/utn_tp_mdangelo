#include <stdio.h>
#include <stdlib.h> //para system("pause")
#include <conio.h> //para funcion getche()

#define ARCH	"./bin.txt"
#define ESC 27

struct persona{
		char nombre[31];
		int edad;
	};

int main (void)
{
	FILE  *pArch;
	struct persona pers;
	system("pause");
	printf("\nSe va a generar por primera vez el archivo\n");
	if ((pArch=fopen(ARCH,"wb"))==NULL)
	{
		printf("El archivo no puede ser abierto");
		exit(1);
	}
	do
	{
		printf("\nIngrese el nombre: ");
		gets(pers.nombre);
		printf("\nIngrese la edad: ");
		scanf("%d",&pers.edad);
		fflush(stdin);
		fwrite(&pers,sizeof(pers),1,pArch);
		printf("\nPresione ESC para terminar");
	}while((getche())!=ESC);

	fclose(pArch);

	return 0;
}
