#include <stdio.h>
#define PI 3.141592

int main()
{
    float perimetro, radio;
    printf( "\n   Introduzca radio: " );
    scanf( "%f", &radio );
    if (radio>0){
	    perimetro = 2* PI * radio;
    printf( "\n   El perimetro de la circunferencia es: %.2f",perimetro );
	}
	else{
		printf("Valor invalido.");	
	}
	return 0;
}
