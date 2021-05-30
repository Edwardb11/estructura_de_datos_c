#include <stdio.h>
int main()
{
int num1;
printf("Ingrese un valor: ");
scanf("%d",&num1);

if (num1 %2==0 && num1 %3==0){
	printf("Es multiplo de 6");
	
}
else{
	printf("No es multiplo de 6");
}

return 0;
}
