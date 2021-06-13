#include <stdio.h>
//Ejercicio 02: Multiplos del 3 del 1 al 30 y haga la sumatoria de los numeros pares
int main()
{ 
int i,suma,k;
for (i=0;i<=20;i+=3){
	if (i%2==0){
	suma+=i;
	}
	if (i%3==0){
		k=i;
	}
	
	printf(" %i \n ",k );
}
printf(" La Suma es %i ", suma);
}
