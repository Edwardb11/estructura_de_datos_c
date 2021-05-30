#include <stdio.h>

int main()
{
int conexion;
float precio,COSTE;
COSTE=0.20;


printf("Introduzca la duracion de conexion: ");
scanf("%d",&conexion);
precio=conexion*COSTE;
printf("El coste de conexion es: %4.2f",precio);

}
