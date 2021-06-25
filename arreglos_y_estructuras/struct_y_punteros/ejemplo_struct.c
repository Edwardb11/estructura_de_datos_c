#include <stdio.h>
#include <string.h>
struct alumno{
	int matricula;
	char nombre[20];
	char carrera[20];
	float promedio;
	char direccion[20];
	
};
void  main(void)
{
	char nom[20], car[50],dir[20];
	int mat;
	float pro;
	
	struct alumno a1={120,"Ivan","Contabilidad", 8.9,"Santiago"},a2,a3;

	printf("\nIngrese la matr%ccula del alumno 2: ",161);
	scanf("%d", &a2.matricula);
	fflush(stdin);
	printf("\nIngrese el nombre del alumno 2: ");
	gets(a2.nombre);
	printf("\nIngrese la carrera del alumno 2: ");
	gets(a2.carrera);
	printf("\nIngrese el promedio del alumno 2: ");
	scanf("%f", &a2.promedio);
	printf("\nIngrese la direccion del alumno 2: ");
	gets(a2.direccion);
	system("CLS");
	
	
	printf("\nIngrese la matr%ccula del alumno 3: ",161);
	scanf("%d", &mat);
	a3.matricula=mat;
	fflush(stdin);
	printf("\nIngrese el nombre del alumno 3: ");
	gets(nom);
	strcpy(a3.nombre,nom);
	printf("\nIngrese la carrera del alumno 3: ");
	gets(a3.carrera);
	strcpy(a3.carrera,car);
	printf("\nIngrese el promedio del alumno 3: ");
	scanf("%f",&pro);
	a3.promedio=pro;
	fflush(stdin);
	printf("\nIngrese la direccion del alumno 3: ");
	gets(a3.direccion);
	strcpy(a3.direccion,dir);
	system("CLS");
	
	printf("\nDatos del alumno 1\n");
	printf("\nMatricula: %d\n",a1.promedio);
	puts(a1.nombre);
	puts(a1.carrera);
	printf("Promedio: %.2f\n",a1.promedio);
	puts(a1.direccion);
	
	printf("\nDatos del alumno 2\n");
	printf("\nMatricula: %d\n",a2.promedio);
	puts(a2.nombre);
	puts(a2.carrera);
	printf("Promedio: %.2f\n",a2.promedio);
	puts(a2.direccion);


	printf("\nDatos del alumno 3\n");
	printf("\nMatricula: %d\n",a3.promedio);
	puts(a3.nombre);
	puts(a3.carrera);
	printf("Promedio: %.2f\n",a3.promedio);
	puts(a3.direccion);

}
