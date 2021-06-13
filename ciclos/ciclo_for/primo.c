//Ejercicio 05: Decir si un numero es primo o no digitado 1 numero
#include <stdio.h>
int main(){
	int i,x,divisores=0;
	printf("Ingrese un numero: ");
	scanf("%i",&x);
	for(i=2;i<=x;i++){
		if (x % i == 0){
			divisores++;
		}
	}
	if (divisores<=2){
		printf("El numero es primo.");
	}
	else{
		printf("El Numero no es primo.");
	}
}

