//Crear un programa que lea como datos, los salarios
//de los profesores de una universidad, y de estos obtenga
//el total de la nomina y el promedio de los salarios
#include <stdio.h>

int main(){
	char seguir;
	int acumulador,contador=0,salario,p;
	do{
		printf("Ingrese el salario: ");
		scanf("%d",&salario);
		acumulador+=salario;
		contador++;
		p=acumulador/contador;
		printf("\n Desea introducir otro salario (S/N): ");
		fflush(stdin); //borrar el buffer
		scanf("%c",&seguir);
	}
		while(seguir!='n');
		

printf("\nEl total de la nomina es: %i ",acumulador);
printf("\nEl promedio  de los %i salario es: %i",contador,p);
}
