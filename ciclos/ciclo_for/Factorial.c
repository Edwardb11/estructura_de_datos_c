//Ejercicio 04: Pida un numero en pantalla y nos expree le factorial de ese numero
#include <stdio.h>
int main()
{ 
	int i,x,resultado;
	printf("Ingrese un numero: ");
	scanf("%i",&x);
	for (i=x;i>=1;i--){
		resultado=resultado*i;
		printf("\n %i",i);
	}
	printf("El factorial es: %i ",resultado);
}
