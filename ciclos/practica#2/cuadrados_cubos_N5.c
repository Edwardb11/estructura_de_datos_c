//PARA REALIZAR CON EL CICLO: FOR 
//5. Escriba un programa utilizando un ciclo FOR que despliegue una tabla con
//valores de los cuadrados y cubos de los números de 1 a 20. 
#include <conio.h>
#include <math.h>
#include <stdio.h>

int main()
{
    int x;
 	 printf( "\n Valores de los cuadrados: \n " );

    for ( x = 1 ; x <= 20 ; x++ )
    {
        printf( "%.f ", pow( x, 2 ) );
    }
    printf("\n");
    printf( "\n Valores de los cubos: \n " );

    for ( x = 1 ; x <= 20 ; x++ )
    {
        printf( "%.f ", pow( x, 3 ) );
    }
  
    return 0;
}


