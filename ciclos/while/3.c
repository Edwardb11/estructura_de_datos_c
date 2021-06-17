//Crear un programa que digitado un numero entero positivo que calcule cuantas cifras tiene
#include <stdio.h>
int main(){
int numero,i=0;
printf("Digite un numero: ");
scanf("%d",&numero);

while(numero>0){
	numero=numero/10;
        i++;
}
   printf("Tiene %i cifras",i);
   return 0;
}
