//Programa que digite un numero hasta que el usuario dese y muestre la suma  
#include <stdio.h>

int main(){
char seguir;
int acumulador=0,numero;
//En el acumulador se va a guardar la suma de los numeros introducidos

do{
	printf("\nIntroduzca un numero entero: ");
	scanf("%d",&numero);
	
	acumulador +=numero;
	fflush(stdin);
	printf("\nSi desea continuar (s/n): ");
	scanf("%c",&seguir);
}
while(seguir !='n');
	

printf("\nLa suma es %d ",acumulador);
}
