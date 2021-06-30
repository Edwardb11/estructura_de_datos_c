//Un número es perfecto si es igual a la suma de sus divisores, exceptuando
//a sí mismo. Por ejemplo: 6 es perfecto porque es igual a 1+2+3. Diseñe un
//programa en C correspondiente para encontrar todos los números
//perfectos entre 1 y 10000.
//PARA REALIZAR CON EL CICLO: WHILE 
#include <stdio.h>
int main()
{
 int x, numeros=1, acumulador;
 for(x=1; x<10000; x++)
 {  
    //divisores enteros menores 
 	acumulador =0;
 	while (x>numeros)
 	{
 if (x%numeros==0)
 	acumulador +=numeros;
 	numeros++;
	}
	numeros =1;
	if (x==acumulador)
	printf("%d \n", x);
}
 return 0;
}
