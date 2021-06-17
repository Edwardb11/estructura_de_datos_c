//Ejercicio 02 Presentar por pantalla los multiplos de 3 y la sumatoria de los numeros pares del 1 al 15

//sintaxis while (condicion) {}
#include <stdio.h>
int main(){
int i=0,suma=0;
while(i<=15){
	if (i%3==0){
	printf("%i \n ",i );
	}
	if (i%2==0){
		suma+=i;
		}
	i++;
}
printf(" La Suma es %i ", suma);
}

