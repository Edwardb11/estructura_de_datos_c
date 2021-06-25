#include <stdio.h>
#include <string.h>
struct alumno{
	char nombre[20];
	char apellido[20];
	int edad;
	float promedio;
	
}estudiante1,estudiante2; //mis dos estructuras 
int main(){
	
	//arreglo 1 estudiante1
	printf("Nombre: ");
	gets(estudiante1.nombre);
	fflush(stdin);
	
	printf("Apellido: ");
	gets(estudiante1.apellido);
	fflush(stdin);

	printf("Edad: ");
	scanf("%d",&estudiante1.edad);
	
	printf("Promedio: ");
	scanf("%f",&estudiante1.promedio);
	
	printf("\nDatos del estudiante 2 \n\n");

	//Arreglo 2 estudiante2
	printf("Nombre: ");
	scanf("%d",&estudiante2.nombre);
	fflush(stdin);
	
	printf("Apellido: ");
	gets(estudiante2.apellido);
	fflush(stdin);

	printf("Edad: ");
	scanf("%d",&estudiante2.edad);
	
	printf("Promedio: ");
	scanf("%f",&estudiante2.promedio);

	printf("\n________________________\n");
	
	printf("Nombre: %s\n",estudiante1.nombre);
	printf("Apellido: %s\n",estudiante1.apellido);
	printf("Edad: %i\n",estudiante1.edad);
	printf("Promedio: %.2f\n",estudiante1.promedio);
	
	
	printf("\n________________________\n");
	
	printf("Nombre: %s\n",estudiante2.nombre);
	printf("Apellido: %s\n",estudiante2.apellido);
	printf("Edad: %i\n",estudiante2.edad);
	printf("Promedio: %.2f\n",estudiante2.promedio);
}
