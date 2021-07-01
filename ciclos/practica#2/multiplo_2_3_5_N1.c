//Escriba programa en lenguaje C, para leer una serie de números hasta que
//el usuario teclee el número dato; dentro del ciclo cuente los múltiplos de 2,
//de 3 y de 5. Imprimir cuantos múltiplos se teclearon en cada caso. 
//PARA REALIZAR CON EL CICLO: WHILE 
#include<stdio.h>
int main(){ 
	int numero,multiplo2, multiplo3, multiplo5;
	printf("-- Edward Brito Diaz--\n\n");
    while(numero<100){
	printf("Introduzca un valor: ");
    scanf("%i",&numero);
    	if (numero%2==0){
    		multiplo2++;
		}
		else if (numero%3==0){
    		multiplo3++;
		}
		else if (numero%5==0){
    		multiplo5++;
		}
    	}
	printf("\n Multiplos de 2: %i \n Multiplos de 3: %i \n Multiplos de 5: %i ",multiplo2,multiplo3,multiplo5);
	}
