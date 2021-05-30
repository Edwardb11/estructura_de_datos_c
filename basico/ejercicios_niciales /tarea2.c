#include <stdio.h>
int main(){
	int precio,dolares, pesos;
	precio=57;
	printf("Ingrese la cantidad en Dolar: ");
	scanf("%d",&dolares);
	pesos= precio*dolares;
	printf("Equivalen a %d Pesos Dominicanos", pesos);
}
