//Realizar un programa que permita ingresar 2 números entero y los devuelva
// ordenado de menor a mayor utilizando puntero.
#include <stdio.h>
#include <string.h>
int main (){
	int a,b,*pt1,*pt2;
	pt1=&a;
	pt2=&b;
	
	printf("Valor 1: ");
	scanf("%i",&pt1);
	printf("Valor 2: ");
	scanf("%i",&pt2);
	
	if(pt1>pt2){
		printf("El orden ascendente es: %i & %i",pt2,pt1);
	}
	else{
			printf("El orden ascendente es: %i & %i",pt1,pt2);
	}
}
