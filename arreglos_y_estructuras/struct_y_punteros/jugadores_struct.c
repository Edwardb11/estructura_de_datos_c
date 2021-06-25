//Realizar un programa en c con struct que pida al usuario los 
//nombres, edades,equipos y alturas de 4 jugadores y que 
//imprima dichos datos
#include <stdio.h>
#include <string.h>

struct jugador {
	char nombre[50];
	int edad;
	char equipo[30];
	float alt;
	
};

void main(){
	struct jugador jug[5];
	int i, j;
	for (i=0;i<4;i++){
		system("CLS");
		printf("\n Ingrese los jugadores\n");
		
		printf("\n Nombre: ");
		//gets(a1.nombre);
		fflush(stdin);
		scanf("%[^\n]",&jug[i].nombre);
		
		printf("\n Edad: ");
		scanf("%d",&jug[i].edad);
		
		printf("\n Equipo: ");
		//gets(a1.equipos);
		fflush(stdin);
		scanf("%[^\n]",&jug[i].equipo);
		
		printf("\n Alttura: ");
		scanf("%f",&jug[i].alt);
	}
	printf("\n\n Jugadores");
	for(j=0;j<4;j++){
		printf("\n\n Nombre: %s",jug[j].nombre);
		printf("\n Edad: %d",jug[j].edad);
		printf("\n Nombre: %s",jug[j].equipo);
		printf("\n Altura: %.2f",jug[j].alt);
	}
}
