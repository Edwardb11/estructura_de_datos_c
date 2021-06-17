//programa que solicite valor y vaya sumando hasta 
//que uno de los valores ingresado sea mayor que 100

#include <stdio.h>

int main(){
	int acumulador=0,n=1;
	while (n!=100){
		printf("Ingrese un valor: ");
		scanf("%d",&n);
		acumulador+=n;
	}
	printf("El total es: %d",acumulador);
	
}
