#include <stdio.h>
int main(){	

int valorN1, valorN2, valorN3,operador1,operador2,operador3,sumaTotal;
printf("Edward Brito Diaz\n");
printf("\n2019-0823\n");
printf("Calcula el importe dada una cantidad externa\n");

printf("\nIntroduzca la primera cantidad: ");
scanf("%d",&valorN1);
printf("Introduzca la segunda cantidad : ");
scanf("%d",&valorN2);
printf("Introduzca la tercera cantidad :");
scanf("%d",&valorN3);
operador1= (valorN1*valorN1);
operador2=(valorN2*valorN2);
operador3=(valorN3*valorN3);
sumaTotal=operador1+operador2+operador3;
printf("Importe total : %d ", sumaTotal);
}
