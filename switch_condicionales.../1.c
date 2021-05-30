#include <stdio.h>
#define incremento 0.10
int main(){	

int salario, accion;
printf("Edward Brito Diaz\n");
printf("\n2019-0823\n");

printf("\nMuestra el salario con un incremento del 10 por ciento\n");
printf("Salario del empleado:");
scanf("%d",&salario);
accion=salario+(salario*incremento);
printf("Su nuevo salario es: %d", accion);
}
