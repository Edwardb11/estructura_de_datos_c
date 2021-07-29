/* PROGRAMA QUE ALMACENE 6 NUMEROS Y QUE LO SUME Y DIGA SI LA SUMA ES PAR O IMPAR */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int matriz[6], suma = 0;
	int cont;
	
	for (cont = 0; cont < 6; cont++){
		printf("%d. Introduzca un n%cmero: ", cont+1, 163);
		scanf("%d", &matriz[cont]);
		suma = suma + matriz[cont];
	}
	
	if(suma % 2 == 0){
		printf("\n La suma es %d y es un numero PAR", suma);
	}
	
	else{
		printf("\n La suma es %d y es un numero IMPAR", suma);
	}
	
	return 0;
}
