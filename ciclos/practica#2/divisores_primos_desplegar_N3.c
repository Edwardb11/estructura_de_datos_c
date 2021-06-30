//Escriba un programa en C que determine todos los divisores primos de un
//número leído desde el teclado. Ejemplo, si el número de entrada es 45, la
//salida será: 1, 3, 5. 
//PARA REALIZAR CON EL CICLO: DO WHILE 

#include<stdio.h>
int main ( )
{
	int rango, i, primos, j, acumulador=0,resto;
    do
     {
     printf ("Ingrese un numero: ");
	 scanf ("%d",&rango);
     }
     while (rango<0);{
      for (primos=1;primos<=rango;primos++)
    	{
    		 resto=rango%primos;
        for (j=1;j<=primos;j++)
           {		
            acumulador=primos%j;
             if (acumulador==0)
             i++;
         }
        
        if (i<=2 && resto==0 )
        	printf ("\n %d",primos);
            i=0;
			}
	}
	return 0;
}
