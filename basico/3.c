#include <stdio.h>

int main()
{
int num1, num2,suma,preg;
printf("Ingrese el primer valor: ");
scanf("%d",&num1);
printf("Ingrese el segundo valor: ");
scanf("%d",&num2);
suma=num1+num2;
preg=printf("Cual es la suma? ");
scanf("%d", &preg);
if (preg== suma){
	printf("Su respuesta es correcta.");
	}
	else{
		printf("Su respuesta es incorrecta");
	}
return 0;
}
	
