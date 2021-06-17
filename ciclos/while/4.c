//Programa que simule una clava y entre a un sistema en c
#include <stdio.h>

int main(){
int correcta= 1234, clave=0;

printf("Ingrese una clave: ");
scanf("%i",&clave);
while (clave != correcta ){
	printf("La clave introducida es incorrecta \n ");
	printf("Ingrese una clave: ");
    scanf("%i",&clave);
}

printf("Bienvenido al sistema.");
}
