//PARA REALIZAR CON EL CICLO: FOR 
//6. Escriba un programa para sumar los primeros 100 números primos 
#include <stdio.h>
int main() {
	int  i, primos, j, acumulador=0, suma;
  for (primos=2;primos<=100;primos++){
  
    	{
        for (j=1;j<=primos;j++)
           {		
            acumulador=primos%j;
             if (acumulador==0)
             i++;
         }
        if (i<=2)
			suma+=primos;
			i=0;
  		}
	}
printf("La suma de los 100 primeros numeros primos es: %d.\n",suma);
} 
